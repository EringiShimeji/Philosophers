/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:37:23 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 14:39:54 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <semaphore.h>

typedef long long	t_msec;
typedef suseconds_t	t_usec;

long		ft_strtol(const char *str, char **endptr, int base);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);
int			ft_isspace(int c);
int			print_error(void);
void		presice_msleep_until(t_msec end);
t_msec		gettimeofday_as_ms(void);
void		write_safely_bool(sem_t *lock, bool *p, bool value);
bool		read_safely_bool(sem_t *lock, bool *p);
t_msec		read_safely_msec(sem_t *lock, t_msec *p);
void		write_safely_msec(sem_t *lock, t_msec *p, t_msec value);
void		presice_msleep(t_msec duration);
void		*ft_xmalloc(size_t size);
sem_t		*xsem_open(const char *name, int value);

#endif
