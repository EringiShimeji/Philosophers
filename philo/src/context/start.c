/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:44:06 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/20 15:44:35 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "context_internal.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (!can_eat(philo->ctx))
		if (did_someone_died(philo->ctx))
			return (NULL);
	while (!did_someone_died(philo->ctx))
	{
		if (think(philo)
			|| eat(philo)
			|| psleep(philo))
			return (NULL);
	}
	return (NULL);
}

static t_msec	calc_first_meal_time(t_philo *philo)
{
	int	id;
	int	n;
	int	k;
	int	unit;

	id = philo->id;
	n = philo->ctx->num_of_philos;
	k = n / 2;
	unit = philo->time_to_eat / k;
	return (philo->ctx->start_time + unit * ((id * k) % n));
}

int	start_eating(t_context *ctx)
{
	int		i;
	t_philo	*philo;

	i = 0;
	while (i < ctx->num_of_philos)
	{
		philo = &ctx->philos[i++];
		if (pthread_create(&philo->thread, NULL, start_routine, philo))
		{
			set_dead_info(philo->ctx, true);
			wait_philos(philo->ctx);
			return (EXIT_FAILURE);
		}
	}
	ctx->start_time = gettimeofday_as_ms();
	i = 0;
	while (i < ctx->num_of_philos)
	{
		philo = &ctx->philos[i++];
		philo->next_meal_time = calc_first_meal_time(philo);
	}
	write_safely_bool(&ctx->lock, &ctx->can_eat, true);
	return (EXIT_SUCCESS);
}
