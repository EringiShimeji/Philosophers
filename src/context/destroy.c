/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:09:15 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/10 11:38:38 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include <pthread.h>
#include <stdlib.h>

static void	destroy_philosopher(t_philosopher *philosopher)
{
	free(philosopher);
}

void	destroy_philosophers(t_philosopher **philosophers,
						int number_of_philosophers)
{
	int	i;

	if (philosophers == NULL)
		return ;
	i = 0;
	while (i < number_of_philosophers)
	{
		destroy_philosopher(philosophers[i]);
		i++;
	}
	free(philosophers);
}

void	destroy_context(t_context *context)
{
	int	i;

	free(context->forks);
	pthread_mutex_destroy(&context->forks_mutex);
	if (context->threads != NULL)
	{
		i = 0;
		while (i < context->number_of_philosophers)
		{
			free(context->threads[i]);
			i++;
		}
		free(context->threads);
	}
	destroy_philosophers(context->philosophers,
		context->number_of_philosophers);
}
