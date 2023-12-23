/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:28:03 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/23 01:01:39 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_itoa_helper(long long n, char *res, int res_i)
{
	if (n < 10)
	{
		res[res_i] = n % 10 + '0';
		return (res_i + 1);
	}
	res_i = ft_itoa_helper(n / 10, res, res_i);
	res[res_i] = n % 10 + '0';
	return (res_i + 1);
}

char	*ft_itoa(int n)
{
	long long	num;
	char		res[20];
	int			res_i;

	num = n;
	res_i = 0;
	if (num < 0)
	{
		res[res_i++] = '-';
		num *= -1;
	}
	res_i = ft_itoa_helper(num, res, res_i);
	res[res_i] = '\0';
	return (ft_strdup(res));
}
