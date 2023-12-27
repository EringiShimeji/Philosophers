/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:43:13 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 13:56:45 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_xmalloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
		exit(print_error());
	return (res);
}
