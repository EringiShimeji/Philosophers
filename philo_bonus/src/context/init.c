/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:37:30 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 14:25:50 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "utils.h"
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/semaphore.h>

static int	parse_args(t_context *ctx, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (EXIT_FAILURE);
	ctx->num_of_philos = ft_atoi(argv[1]);
	ctx->time_to_die = ft_atoi(argv[2]);
	ctx->time_to_eat = ft_atoi(argv[3]);
	ctx->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ctx->must_eat = ft_atoi(argv[5]);
	else
		ctx->must_eat = NO_MUST_EAT;
	if (errno == ERANGE || ctx->num_of_philos <= 0
		|| ctx->time_to_die <= 0 || ctx->time_to_eat <= 0
		|| ctx->time_to_sleep <= 0 || (argc == 6 && ctx->must_eat <= 0))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static sem_t	*create_lock_for_philo(t_philo *philo)
{
	char	*id_str;
	char	*name;

	id_str = ft_itoa(philo->id);
	if (id_str == NULL)
		return (NULL);
	name = ft_strjoin("ft_lock_", id_str);
	if (name == NULL)
		return (NULL);
	philo->lock_name = name;
	sem_unlink(philo->lock_name);
	return (sem_open(name, O_CREAT, 0600, 1));
}

static int	create_philos(t_context *ctx)
{
	int		i;
	t_philo	*philo;

	ctx->philos = ft_xmalloc(sizeof(t_philo) * ctx->num_of_philos);
	i = 0;
	while (i < ctx->num_of_philos)
	{
		philo = &ctx->philos[i];
		philo->lock = create_lock_for_philo(philo);
		if (philo->lock == NULL)
			return (EXIT_FAILURE);
		memset(philo, 0, sizeof(t_philo));
		philo->id = i + 1;
		philo->ctx = ctx;
		philo->time_to_die = ctx->time_to_die;
		philo->time_to_eat = ctx->time_to_eat;
		philo->time_to_sleep = ctx->time_to_sleep;
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	create_forks(t_context *ctx)
{
	ctx->fork_pool_name = "ft_fork_pool";
	sem_unlink(ctx->fork_pool_name);
	ctx->fork_pool = sem_open(ctx->fork_pool_name, O_CREAT,
			0600, ctx->num_of_philos);
	return (EXIT_SUCCESS);
}

int	init_context(t_context *ctx, int argc, char **argv)
{
	memset(ctx, 0, sizeof(t_context));
	if (parse_args(ctx, argc, argv))
		return (EXIT_FAILURE);
	if (create_philos(ctx) || create_forks(ctx))
	{
		destroy_context(ctx);
		return (EXIT_FAILURE);
	}
	ctx->lock_name = "ft_lock";
	sem_unlink(ctx->lock_name);
	ctx->lock = sem_open(ctx->lock_name, O_CREAT, O_WRONLY, 1);
	ctx->io_lock_name = "ft_io_lock";
	sem_unlink(ctx->io_lock_name);
	ctx->io_lock = sem_open(ctx->io_lock_name, O_CREAT, 0600, 1);
	ctx->is_ready_name = "ft_is_ready";
	sem_unlink(ctx->is_ready_name);
	ctx->is_ready = sem_open(ctx->is_ready_name, O_CREAT, 0600, 1);
	return (EXIT_SUCCESS);
}
