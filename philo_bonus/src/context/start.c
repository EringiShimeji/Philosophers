/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:44:06 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/02 15:59:16 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "context_internal.h"
#include "utils.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

static t_msec	calc_first_meal_time(t_philo *philo)
{
	int		n;
	int		id;
	int		k;
	t_msec	unit;

	n = philo->ctx->num_of_philos;
	if (n == 1)
		return (philo->ctx->start_time);
	id = philo->id;
	k = n / 2;
	unit = philo->time_to_eat / k;
	return (philo->ctx->start_time + unit * ((id * k) % n));
}

static void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->next_meal_time = calc_first_meal_time(philo);
	presice_msleep_until(philo->ctx->start_time);
	while (true)
	{
		if (think(philo)
			|| eat(philo)
			|| psleep(philo))
			return (NULL);
	}
}

static int	start_process(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->pid = fork();
	if (philo->pid == -1)
		return (EXIT_FAILURE);
	if (philo->pid == 0)
	{
		pthread_create(&philo->main_thread, NULL, start_routine, philo);
		monitor_myself(philo);
		pthread_join(philo->main_thread, NULL);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

int	start_eating(t_context *ctx)
{
	int		i;

	i = 0;
	ctx->start_time = gettimeofday_as_ms() + 1000;
	while (i < ctx->num_of_philos)
	{
		if (start_process(&ctx->philos[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
