/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:31:29 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 14:09:06 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_INTERNAL_H
# define CONTEXT_INTERNAL_H

# include "context.h"
# include <pthread.h>
# include <stdbool.h>

void	set_dead_info(t_context *ctx, bool value);
void	wait_until_ready(t_philo *philo);
bool	did_someone_died(t_context *ctx);
t_msec	get_last_meal_time(t_philo *philo);
int		log_safely(t_philo *philo, const char *message);
int		eat(t_philo *philo);
int		think(t_philo *philo);
int		psleep(t_philo *philo);
void	set_last_meal_time(t_philo *philo, t_msec value);
void	set_has_finished_meal(t_philo *philo, bool value);
void	terminate_philos(t_context *ctx);
void	monitor_myself(t_philo *philo);

#endif
