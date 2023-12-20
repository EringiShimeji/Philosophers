/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:10:52 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/10 11:39:30 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTEXT_INTERNAL_H
# define CONTEXT_INTERNAL_H

# include "context.h"

void	destroy_philosophers(t_philosopher **philosophers,
			int number_of_philosophers);

#endif
