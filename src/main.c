/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:33:08 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/10 03:02:28 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/_pthread/_pthread_t.h>
#include "utils.h"
#include "pthread.h"

static void	*run_in_thread(void *arg)
{
	(void)arg;
	printf("I'm in thread!\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_context	context;
	int			i;
	pthread_t	thread;

	if (argc != 4)
		return (print_error());
	context.number_of_philosophers = ft_atoi(argv[1]);
	context.time_to_die = ft_atoi(argv[2]);
	context.time_to_eat = ft_atoi(argv[3]);
	if (context.number_of_philosophers <= 0 || context.time_to_die <= 0
		|| context.time_to_eat <= 0)
		return (print_error());
	i = 0;
	while (i < context.number_of_philosophers)
	{
		pthread_create(&thread, NULL, run_in_thread, NULL);
		pthread_join(thread, NULL);
		i++;
	}
}
