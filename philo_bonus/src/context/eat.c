/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:22:49 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/11 18:33:01 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "context_internal.h"
#include "utils.h"
#include <stdlib.h>

static int	take_forks(t_philo *philo)
{
	sem_wait(philo->ctx->fork_pool);
	if (log_safely(philo, "has taken a fork"))
		return (EXIT_FAILURE);
	sem_wait(philo->ctx->fork_pool);
	return (log_safely(philo, "has taken a fork"));
}

static void	put_forks(t_philo *philo)
{
	sem_post(philo->ctx->fork_pool);
	sem_post(philo->ctx->fork_pool);
}

static t_msec	calc_next_meal_time(t_philo *philo, t_msec last_meal_time)
{
	const int		n = philo->ctx->num_of_philos;
	const int		k = n / 2;
	double			interval;

	interval = (double)n * philo->time_to_eat / k;
	if (interval > (t_msec)interval)
		interval = (t_msec)interval + 1;
	if (interval < philo->time_to_eat + philo->time_to_sleep)
		interval = philo->time_to_eat + philo->time_to_sleep;
	return (last_meal_time + (t_msec)interval);
}

int	eat(t_philo *philo)
{
	t_msec			now;

	if (take_forks(philo))
		return (EXIT_FAILURE);
	now = gettimeofday_as_ms();
	if (log_safely(philo, "is eating"))
	{
		put_forks(philo);
		return (EXIT_FAILURE);
	}
	set_last_meal_time(philo, now);
	presice_msleep(philo->time_to_eat);
	philo->next_meal_time = calc_next_meal_time(philo, now);
	put_forks(philo);
	philo->num_of_eaten_meals++;
	return (EXIT_SUCCESS);
}
