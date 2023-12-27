/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:44:06 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 15:12:19 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "context_internal.h"
#include "utils.h"
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_pid_t.h>
#include <sys/fcntl.h>
#include <unistd.h>

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

static void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->next_meal_time = calc_first_meal_time(philo);
	presice_msleep_until(philo->ctx->start_time);
	while (!did_someone_died(philo->ctx))
	{
		if (think(philo)
			|| eat(philo)
			|| psleep(philo))
			exit(EXIT_SUCCESS);
	}
	set_has_finished_meal(philo, true);
	return (NULL);
}

static void	*start_process(void *arg)
{
	t_philo	*philo;

	philo = arg;
	philo->pid = fork();
	if (philo->pid == -1)
		return (NULL);
	if (philo->pid == 0)
	{
		pthread_create(&philo->main_thread, NULL, start_routine, philo);
		pthread_detach(philo->main_thread);
		monitor_myself(philo);
		exit(EXIT_SUCCESS);
	}
	return (NULL);
}

int	start_eating(t_context *ctx)
{
	int		i;

	i = 0;
	ctx->start_time = gettimeofday_as_ms() + 1000;
	while (i < ctx->num_of_philos)
	{
		start_process(&ctx->philos[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
