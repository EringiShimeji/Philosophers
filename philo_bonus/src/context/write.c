/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:16:21 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 12:16:09 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "utils.h"
#include <stdbool.h>

void	set_last_meal_time(t_philo *philo, t_msec value)
{
	write_safely_msec(philo->lock, &philo->last_meal_time,
		value - philo->ctx->start_time);
}

void	set_has_finished_meal(t_philo *philo, bool value)
{
	write_safely_bool(philo->lock, &philo->has_finished_meal, value);
}
