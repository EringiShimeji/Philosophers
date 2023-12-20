/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:24:24 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/20 15:46:48 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "utils.h"
#include <stdbool.h>

bool	can_eat(t_context *ctx)
{
	return (read_safely_bool(&ctx->lock, &ctx->can_eat));
}

bool	did_someone_died(t_context *ctx)
{
	return (read_safely_bool(&ctx->io_lock, &ctx->did_someone_died));
}

t_msec	get_last_meal_time(t_philo *philo)
{
	return (read_safely_msec(&philo->lock, &philo->last_meal_time));
}
