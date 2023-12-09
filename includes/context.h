/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:43:25 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/10 03:06:24 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_H
# define CONTEXT_H

# include <stdbool.h>

typedef struct s_context
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
}	t_context;

#endif
