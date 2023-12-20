/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:32:14 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/20 10:31:12 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include <pthread.h>
#include <stdlib.h>

void	destroy_context(t_context *ctx)
{
	int	i;

	i = 0;
	if (ctx->philos != NULL)
	{
		while (i < ctx->num_of_philos)
		{
			pthread_mutex_destroy(&ctx->philos[i].lock);
			i++;
		}
		free(ctx->philos);
	}
	if (ctx->forks != NULL)
	{
		while (i < ctx->num_of_philos)
		{
			pthread_mutex_destroy(&ctx->forks[i]);
			i++;
		}
		free(ctx->forks);
	}
	pthread_mutex_destroy(&ctx->lock);
}
