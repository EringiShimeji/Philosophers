/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:24:44 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/18 23:50:50 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <pthread.h>
#include "utils.h"

bool	read_safely_bool(pthread_mutex_t *lock, bool *p)
{
	bool	value;

	pthread_mutex_lock(lock);
	value = *p;
	pthread_mutex_unlock(lock);
	return (value);
}

t_msec	read_safely_msec(pthread_mutex_t *lock, t_msec *p)
{
	t_msec	value;

	pthread_mutex_lock(lock);
	value = *p;
	pthread_mutex_unlock(lock);
	return (value);
}
