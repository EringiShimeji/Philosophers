/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:35:00 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 14:40:44 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include "utils.h"
# include <stdbool.h>
# include <semaphore.h>

# define NO_MUST_EAT (-1)

typedef struct s_philo	t_philo;

typedef struct s_context
{
	sem_t			*lock;
	char			*lock_name;
	sem_t			*io_lock;
	char			*io_lock_name;
	sem_t			*fork_pool;
	char			*fork_pool_name;
	t_philo			*philos;
	int				num_of_philos;
	t_msec			time_to_die;
	t_msec			time_to_eat;
	t_msec			time_to_sleep;
	int				must_eat;
	t_msec			start_time;
}	t_context;

struct s_philo
{
	int				id;
	t_context		*ctx;
	pthread_t		main_thread;
	pthread_t		monitor_thread;
	sem_t			*lock;
	char			*lock_name;
	int				pid;
	t_msec			time_to_die;
	t_msec			time_to_eat;
	t_msec			time_to_sleep;
	t_msec			next_meal_time;
	t_msec			last_meal_time;
	int				num_of_eaten_meals;
	bool			has_finished_meal;
};

int		init_context(t_context *ctx, int argc, char **argv);
void	destroy_context(t_context *ctx);
int		start_eating(t_context *ctx);
int		wait_philos(t_context *ctx);

#endif
