/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:49:11 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/10 16:23:30 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/_pthread/_pthread_t.h>
#include "context_internal.h"

static t_philosopher	*new_philosopher(t_context *context, int id)
{
	t_philosopher	*philosopher;

	philosopher = malloc(sizeof(t_philosopher));
	if (philosopher == NULL)
		return (NULL);
	philosopher->id = id;
	philosopher->status = P_THINKING;
	philosopher->number_of_philosophers = context->number_of_philosophers;
	philosopher->time_to_die = context->time_to_die;
	philosopher->time_to_eat = context->time_to_eat;
	philosopher->context = context;
	return (philosopher);
}

static t_philosopher	**new_philosophers(t_context *context)
{
	t_philosopher	**philosophers;
	int				i;

	philosophers = malloc(sizeof(t_philosopher *)
			* context->number_of_philosophers);
	if (philosophers == NULL)
		return (NULL);
	i = 0;
	while (i < context->number_of_philosophers)
	{
		philosophers[i] = new_philosopher(context, i);
		if (philosophers[i] == NULL)
		{
			destroy_philosophers(philosophers, i);
			return (NULL);
		}
		i++;
	}
	return (philosophers);
}

static pthread_t	**new_threads(int number_of_philosophers)
{
	pthread_t	**threads;
	int			i;

	threads = malloc(sizeof(pthread_t *) * number_of_philosophers);
	if (threads == NULL)
		return (NULL);
	i = 0;
	while (i < number_of_philosophers)
	{
		threads[i] = malloc(sizeof(pthread_t));
		if (threads[i] == NULL)
		{
			while (i > 0)
			{
				free(threads[i - 1]);
				i--;
			}
		}
		i++;
	}
	return (threads);
}

// When call this function, make sure there are no running philosophers
// since the context is not locked, which means non-thread-safe.
int	init_context(t_context *context, int number_of_philosophers,
				int time_to_die, int time_to_eat)
{
	if (errno == ERANGE || number_of_philosophers <= 0
		|| time_to_die <= 0 || time_to_eat <= 0)
		return (EXIT_FAILURE);
	context->number_of_philosophers = number_of_philosophers;
	context->time_to_die = time_to_die;
	context->time_to_eat = time_to_eat;
	if (pthread_mutex_init(&context->forks_mutex, NULL) == -1)
		return (EXIT_FAILURE);
	context->forks = malloc(sizeof(bool) * context->number_of_philosophers);
	context->philosophers = new_philosophers(context);
	context->threads = new_threads(context->number_of_philosophers);
	if (context->forks == NULL || context->philosophers == NULL
		|| context->threads == NULL)
	{
		destroy_context(context);
		return (EXIT_FAILURE);
	}
	memset(context->forks, true, number_of_philosophers);
	context->is_someone_died = false;
	return (EXIT_SUCCESS);
}
