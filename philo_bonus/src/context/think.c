/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:20:51 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/23 01:50:07 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context_internal.h"
#include "utils.h"
#include <stdlib.h>

int	think(t_philo *philo)
{
	if (log_safely(philo, "is thinking"))
		return (EXIT_FAILURE);
	presice_msleep_until(philo->next_meal_time);
	return (EXIT_SUCCESS);
}
