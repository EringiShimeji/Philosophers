/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:32:14 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 14:40:59 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include <stdlib.h>
#include <semaphore.h>

void	destroy_context(t_context *ctx)
{
	int	i;

	i = 0;
	if (ctx->philos != NULL)
	{
		while (i < ctx->num_of_philos)
		{
			sem_close(ctx->philos[i].lock);
			sem_unlink(ctx->philos[i].lock_name);
			i++;
		}
		free(ctx->philos);
	}
	if (ctx->fork_pool != NULL)
	{
		sem_close(ctx->fork_pool);
		sem_unlink(ctx->fork_pool_name);
	}
	sem_close(ctx->lock);
	sem_unlink(ctx->lock_name);
}
