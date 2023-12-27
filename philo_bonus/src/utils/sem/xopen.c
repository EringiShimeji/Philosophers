/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xopen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:35:29 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 14:50:53 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/semaphore.h>
#include "utils.h"

sem_t	*xsem_open(const char *name, int value)
{
	sem_t	*res;

	sem_unlink(name);
	res = sem_open(name, O_CREAT, 0666, value);
	if (res == SEM_FAILED)
		exit(print_error());
	return (res);
}
