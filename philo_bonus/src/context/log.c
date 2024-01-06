/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:30:28 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 12:14:45 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context_internal.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int	log_safely(t_philo *philo, const char *message)
{
	t_msec	timestamp;

	sem_wait(philo->ctx->io_lock);
	timestamp = gettimeofday_as_ms() - philo->ctx->start_time;
	printf("%lld %d %s\n", timestamp, philo->id, message);
	sem_post(philo->ctx->io_lock);
	return (EXIT_SUCCESS);
}
