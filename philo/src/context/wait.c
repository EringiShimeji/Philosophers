/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:20:57 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/20 15:53:31 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int	wait_philos(t_context *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->num_of_philos)
		pthread_join(ctx->philos[i++].thread, NULL);
	return (EXIT_SUCCESS);
}
