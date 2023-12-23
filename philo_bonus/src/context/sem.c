/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:17:35 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/23 17:35:28 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context_internal.h"
#include <stdlib.h>

int	reopen_sem(t_philo *philo)
{
	(void )philo;
	// philo->ctx->lock = sem_open(philo->ctx->lock_name, 0);
	// philo->ctx->io_lock = sem_open(philo->ctx->io_lock_name, 0);
	// philo->ctx->is_ready = sem_open(philo->ctx->is_ready_name, 0);
	// philo->ctx->fork_pool = sem_open(philo->ctx->fork_pool_name, 0);
	// philo->lock = sem_open(philo->lock_name, 0);
	return (EXIT_SUCCESS);
}
