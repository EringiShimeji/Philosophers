/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 02:55:06 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/10 02:42:23 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	unsigned char	u;

	u = c;
	return (u == '\t' || u == '\n' || u == '\v'
		|| u == '\f' || u == '\r' || u == ' ');
}
