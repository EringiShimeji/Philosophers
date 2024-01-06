/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:05:37 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/23 01:20:37 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <semaphore.h>
#include "utils.h"

void	write_safely_bool(sem_t *lock, bool *p, bool value)
{
	sem_wait(lock);
	*p = value;
	sem_post(lock);
}

void	write_safely_msec(sem_t *lock, t_msec *p, t_msec value)
{
	sem_wait(lock);
	*p = value;
	sem_post(lock);
}
