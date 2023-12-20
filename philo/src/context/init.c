/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:37:30 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/20 13:27:11 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "utils.h"
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

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

static int	create_philos(t_context *ctx)
{
	int		i;
	t_philo	*philo;

	ctx->philos = malloc(sizeof(t_philo) * ctx->num_of_philos);
	if (ctx->philos == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < ctx->num_of_philos)
	{
		philo = &ctx->philos[i];
		memset(philo, 0, sizeof(t_philo));
		philo->id = i + 1;
		philo->ctx = ctx;
		philo->time_to_die = ctx->time_to_die;
		philo->time_to_eat = ctx->time_to_eat;
		philo->time_to_sleep = ctx->time_to_sleep;
		pthread_mutex_init(&philo->lock, NULL);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	create_forks(t_context *ctx)
{
	int	i;

	ctx->forks = malloc(sizeof(pthread_mutex_t) * ctx->num_of_philos);
	if (ctx->forks == NULL)
		return (EXIT_FAILURE);
	i = 0;
	while (i < ctx->num_of_philos)
	{
		if (pthread_mutex_init(&ctx->forks[i], NULL))
			return (EXIT_FAILURE);
		i++;
	}
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
	pthread_mutex_init(&ctx->lock, NULL);
	pthread_mutex_init(&ctx->io_lock, NULL);
	return (EXIT_SUCCESS);
}
