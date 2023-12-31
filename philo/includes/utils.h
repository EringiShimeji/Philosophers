/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:37:23 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/20 15:13:31 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef long long	t_msec;
typedef suseconds_t	t_usec;

long		ft_strtol(const char *str, char **endptr, int base);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_isspace(int c);
int			print_error(void);
void		presice_msleep_until(t_msec end);
t_msec		gettimeofday_as_ms(void);
void		write_safely_bool(pthread_mutex_t *lock, bool *p, bool value);
bool		read_safely_bool(pthread_mutex_t *lock, bool *p);
t_msec		read_safely_msec(pthread_mutex_t *lock, t_msec *p);
void		write_safely_msec(pthread_mutex_t *lock, t_msec *p, t_msec value);
void		presice_msleep(t_msec duration);

#endif
