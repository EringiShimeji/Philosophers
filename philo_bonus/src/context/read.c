/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:24:24 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 14:40:27 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "utils.h"

t_msec	get_last_meal_time(t_philo *philo)
{
	return (read_safely_msec(philo->lock, &philo->last_meal_time));
}
