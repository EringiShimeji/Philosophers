/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:30:28 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/20 15:46:11 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context_internal.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int	log_safely(t_philo *philo, const char *message)
{
	t_msec	timestamp;

	if (did_someone_died(philo->ctx))
		return (EXIT_FAILURE);
	pthread_mutex_lock(&philo->ctx->io_lock);
	timestamp = gettimeofday_as_ms() - philo->ctx->start_time;
	if (philo->ctx->did_someone_died)
	{
		pthread_mutex_unlock(&philo->ctx->io_lock);
		return (EXIT_FAILURE);
	}
	printf("%lld %d %s\n", timestamp, philo->id, message);
	pthread_mutex_unlock(&philo->ctx->io_lock);
	return (EXIT_SUCCESS);
}
