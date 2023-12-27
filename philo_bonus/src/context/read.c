/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:24:24 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 12:16:03 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "utils.h"
#include <stdbool.h>

void	wait_until_ready(t_philo *philo)
{
	sem_wait(philo->ctx->is_ready);
	sem_post(philo->ctx->is_ready);
}

bool	did_someone_died(t_context *ctx)
{
	return (read_safely_bool(ctx->io_lock, &ctx->did_someone_died));
}

t_msec	get_last_meal_time(t_philo *philo)
{
	return (read_safely_msec(philo->lock, &philo->last_meal_time));
}
