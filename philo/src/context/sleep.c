/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:35:50 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/20 15:07:10 by smatsuo          ###   ########.fr       */
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
	return (EXIT_SUCCESS);
}
