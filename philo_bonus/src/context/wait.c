/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:20:57 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/23 17:48:03 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	wait_philos(t_context *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->num_of_philos)
		waitpid(ctx->philos[i++].pid, NULL, 0);
	return (EXIT_SUCCESS);
}
