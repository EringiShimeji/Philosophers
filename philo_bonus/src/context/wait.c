/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:20:57 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 14:11:41 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "context_internal.h"
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	wait_philos(t_context *ctx)
{
	int		i;
	bool	is_all_exited;
	int		wait_res;
	int		status;

	while (true)
	{
		i = 0;
		is_all_exited = true;
		while (i < ctx->num_of_philos)
		{
			wait_res = waitpid(ctx->philos[i++].pid, &status, WNOHANG);
			is_all_exited &= wait_res != 0;
			if (wait_res != 0 && WEXITSTATUS(status) == EXIT_FAILURE)
			{
				terminate_philos(ctx);
				exit(EXIT_SUCCESS);
			}
		}
		if (is_all_exited)
			exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
