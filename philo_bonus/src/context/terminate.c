/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:34 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/02 16:00:25 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "context_internal.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_pid_t.h>

void	terminate_philos(t_context *ctx)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < ctx->num_of_philos)
	{
		pid = ctx->philos[i++].pid;
		if (pid > 0)
			kill(pid, SIGTERM);
	}
}
