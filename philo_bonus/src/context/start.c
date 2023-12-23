/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:44:06 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/23 17:37:48 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "context_internal.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>

static void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	wait_until_ready(philo->ctx);
	monitor_myself(philo);
	while (true)
	{
		think(philo);
		eat(philo);
		psleep(philo);
	}
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

static void	prologue(t_philo *philo)
{
	if (reopen_sem(philo))
		terminate_philos_by(philo);
}

static int	start_process(t_philo *philo)
{
	philo->pid = fork();
	if (philo->pid == -1)
		return (EXIT_FAILURE);
	if (philo->pid == 0)
	{
		prologue(philo);
		start_routine(philo);
		terminate_philos_by(philo);
		exit(0);
	}
	return (EXIT_SUCCESS);
}

int	start_eating(t_context *ctx)
{
	int		i;
	t_philo	*philo;

	i = 0;
	sem_wait(ctx->is_ready);
	while (i < ctx->num_of_philos)
	{
		philo = &ctx->philos[i++];
		philo->next_meal_time = calc_first_meal_time(philo);
	}
	i = 0;
	while (i < ctx->num_of_philos)
	{
		philo = &ctx->philos[i++];
		if (start_process(philo))
			terminate_philos_by(philo);
	}
	sem_post(ctx->is_ready);
	return (EXIT_SUCCESS);
}
