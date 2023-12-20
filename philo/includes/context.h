/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:35:00 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/20 15:54:10 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include "utils.h"
# include <stdbool.h>
# include <pthread.h>

# define NO_MUST_EAT -1

typedef struct s_philo	t_philo;

typedef struct s_context
{
	pthread_mutex_t	lock;
	pthread_mutex_t	io_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	int				num_of_philos;
	t_msec			time_to_die;
	t_msec			time_to_eat;
	t_msec			time_to_sleep;
	int				must_eat;
	bool			can_eat;
	bool			did_someone_died;
	t_msec			start_time;
}	t_context;

struct s_philo
{
	int				id;
	t_context		*ctx;
	pthread_mutex_t	lock;
	pthread_t		thread;
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
int		monitor_philos(t_context *ctx);

#endif
