/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:22:49 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/11 18:29:24 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context_internal.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

static void	select_forks(t_philo *philo, pthread_mutex_t *selected_forks[2])
{
	int				id;
	pthread_mutex_t	*forks;

	id = philo->id;
	forks = philo->ctx->forks;
	if (id == philo->ctx->num_of_philos)
	{
		selected_forks[0] = &forks[0];
		selected_forks[1] = &forks[id - 1];
	}
	else
	{
		selected_forks[0] = &forks[id - 1];
		selected_forks[1] = &forks[id];
	}
}

static void	put_forks(pthread_mutex_t *forks[2])
{
	pthread_mutex_unlock(forks[1]);
	pthread_mutex_unlock(forks[0]);
}

static int	take_forks(t_philo *philo, pthread_mutex_t	*forks[2])
{
	pthread_mutex_lock(forks[0]);
	if (log_safely(philo, "has taken a fork"))
		return (EXIT_FAILURE);
	if (forks[0] == forks[1])
		return (EXIT_FAILURE);
	pthread_mutex_lock(forks[1]);
	return (log_safely(philo, "has taken a fork"));
}

static t_msec	calc_next_meal_time(t_philo *philo, t_msec last_meal_time)
{
	t_msec	meal_finished_time;

	meal_finished_time = last_meal_time + philo->time_to_eat;
	return (meal_finished_time + philo->time_to_eat / philo->ctx->num_of_philos
		+ philo->time_to_eat);
}

int	eat(t_philo *philo)
{
	pthread_mutex_t	*forks[2];
	t_msec			now;

	select_forks(philo, forks);
	if (take_forks(philo, forks))
	{
		put_forks(forks);
		return (EXIT_FAILURE);
	}
	now = gettimeofday_as_ms();
	if (log_safely(philo, "is eating"))
	{
		put_forks(forks);
		return (EXIT_FAILURE);
	}
	set_last_meal_time(philo, now);
	presice_msleep(philo->time_to_eat);
	philo->next_meal_time = calc_next_meal_time(philo, now);
	put_forks(forks);
	philo->num_of_eaten_meals++;
	return (EXIT_SUCCESS);
}
