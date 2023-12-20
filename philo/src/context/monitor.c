/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:33:20 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/20 15:54:33 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "context_internal.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>

static bool	has_finished_meal(t_philo *philo)
{
	return (read_safely_bool(&philo->lock, &philo->has_finished_meal));
}

static bool	is_dead(t_philo *philo)
{
	t_msec	last_meal_time;
	t_msec	now;

	last_meal_time = get_last_meal_time(philo);
	now = gettimeofday_as_ms() - philo->ctx->start_time;
	return (now - last_meal_time >= philo->time_to_die);
}

static int	terminate_philos(t_philo *philo)
{
	int	timestamp;

	pthread_mutex_lock(&philo->ctx->io_lock);
	timestamp = gettimeofday_as_ms() - philo->ctx->start_time;
	printf("%d %d died\n", timestamp, philo->id);
	philo->ctx->did_someone_died = true;
	pthread_mutex_unlock(&philo->ctx->io_lock);
	return (wait_philos(philo->ctx));
}

int	monitor_philos(t_context *ctx)
{
	int		i;
	t_philo	*philo;
	bool	everyone_finshed_meal;

	while (true)
	{
		i = 0;
		everyone_finshed_meal = true;
		while (i < ctx->num_of_philos)
		{
			philo = &ctx->philos[i++];
			if (has_finished_meal(philo))
				continue ;
			everyone_finshed_meal = false;
			if (is_dead(philo))
				return (terminate_philos(philo));
		}
		if (everyone_finshed_meal)
			return (wait_philos(ctx));
	}
}
