/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:05:37 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/20 12:40:18 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdbool.h>
#include "utils.h"

void	write_safely_bool(pthread_mutex_t *lock, bool *p, bool value)
{
	pthread_mutex_lock(lock);
	*p = value;
	pthread_mutex_unlock(lock);
}

void	write_safely_msec(pthread_mutex_t *lock, t_msec *p, t_msec value)
{
	pthread_mutex_lock(lock);
	*p = value;
	pthread_mutex_unlock(lock);
}
