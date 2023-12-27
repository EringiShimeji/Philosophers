/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:35:50 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 14:18:32 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context_internal.h"
#include "utils.h"
#include <stdlib.h>

int	psleep(t_philo *philo)
{
	if (log_safely(philo, "is sleeping"))
		return (EXIT_FAILURE);
	presice_msleep(philo->time_to_sleep);
	if (philo->num_of_eaten_meals == philo->ctx->must_eat)
	{
		set_has_finished_meal(philo, true);
		exit(EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
