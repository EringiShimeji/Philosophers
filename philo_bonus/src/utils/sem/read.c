/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:24:44 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/23 01:20:14 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <semaphore.h>
#include "utils.h"

bool	read_safely_bool(sem_t *lock, const bool *p)
{
	bool	value;

	sem_wait(lock);
	value = *p;
	sem_post(lock);
	return (value);
}

t_msec	read_safely_msec(sem_t *lock, const t_msec *p)
{
	t_msec	value;

	sem_wait(lock);
	value = *p;
	sem_post(lock);
	return (value);
}
