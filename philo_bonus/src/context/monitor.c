/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:33:20 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/02 16:44:16 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "context_internal.h"
#include "utils.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool	has_finished_meal(t_philo *philo)
{
	return (read_safely_bool(philo->lock, &philo->has_finished_meal));
}

static bool	is_dead(t_philo *philo)
{
	t_msec	last_meal_time;
	t_msec	now;

	last_meal_time = get_last_meal_time(philo);
	sem_wait(philo->ctx->io_lock);
	now = gettimeofday_as_ms() - philo->ctx->start_time;
	sem_post(philo->ctx->io_lock);
	return (now - last_meal_time >= philo->time_to_die);
}

static void	*monitor_routine(void *arg)
{
	t_philo	*philo;
	t_msec	timestamp;

	philo = arg;
	while (true)
	{
		if (has_finished_meal(philo))
			return (NULL);
		if (is_dead(philo))
		{
			sem_wait(philo->ctx->io_lock);
			timestamp = gettimeofday_as_ms() - philo->ctx->start_time;
			printf("%lld %d died\n", timestamp, philo->id);
			exit(EXIT_FAILURE);
		}
	}
}

void	monitor_myself(t_philo *philo)
{
	pthread_create(&philo->monitor_thread, NULL, monitor_routine, philo);
	pthread_join(philo->monitor_thread, NULL);
}
