/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:53:13 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/23 21:20:21 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "utils.h"
#include <stdio.h>
#include <sys/_types/_suseconds_t.h>
#include <sys/_types/_useconds_t.h>
#include <sys/time.h>
#include <unistd.h>

static t_usec	gettimeofday_as_us(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

t_msec	gettimeofday_as_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	presice_msleep_until(t_msec end)
{
	int	diff;

	while (true)
	{
		diff = end * 1000 - gettimeofday_as_us();
		if (diff <= 0)
			return ;
		usleep(diff / 2);
	}
}

void	presice_msleep(t_msec duration)
{
	t_msec	now;
	t_msec	end;

	now = gettimeofday_as_ms();
	end = now + duration;
	presice_msleep_until(end);
}
