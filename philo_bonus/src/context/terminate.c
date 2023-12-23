/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:34 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/23 17:14:39 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "context_internal.h"
#include <signal.h>
#include <stdlib.h>

void	terminate_philos_by(t_philo *philo)
{
	int	i;
	int	pid;

	i = 0;
	while (i < philo->ctx->num_of_philos)
	{
		pid = philo->ctx->philos[i++].pid;
		if (pid == philo->pid)
			continue ;
		kill(pid, SIGTERM);
	}
	exit(EXIT_SUCCESS);
}
