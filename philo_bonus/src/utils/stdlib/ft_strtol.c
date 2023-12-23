/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 23:20:43 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/10 10:57:26 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stddef.h>
#include "utils.h"
#include <limits.h>

static void	set_base_and_sign(const char **p, int *sign, int *base)
{
	*sign = 1;
	if (**p == '+')
		(*p)++;
	else if (**p == '-')
	{
		*sign = -1;
		(*p)++;
	}
	if (ft_memcmp(*p, "0x", 2) == 0)
	{
		if (*base == 0)
			*base = 16;
		if (*base == 16)
			*p += 2;
	}
	else if (*base == 0)
	{
		if (**p == '0')
		{
			*base = 8;
			(*p)++;
		}
		else
			*base = 10;
	}
}

static int	add_digit(const char *p, long *res, int base, int sign)
{
	int	digit;

	if ('0' <= *p && *p <= '0' + base)
		digit = *p - '0';
	else if (base > 10 && 'a' <= *p && *p <= 'a' + base)
		digit = *p - 'a';
	else if (base > 10 && 'A' <= *p && *p <= 'A' + base)
		digit = *p - 'A';
	else
		return (1);
	if (sign == 1 && *res > (LONG_MAX - digit) / base)
	{
		*res = LONG_MAX;
		errno = ERANGE;
		return (1);
	}
	if (sign == -1 && -(*res) < (LONG_MIN + digit) / base)
	{
		*res = LONG_MIN;
		errno = ERANGE;
		return (1);
	}
	*res = *res * base + digit;
	return (0);
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	long		res;
	const char	*p;
	int			sign;

	if (str == NULL || base < 2 || base > 36)
		return (0);
	p = str;
	while (ft_isspace(*p))
		p++;
	set_base_and_sign(&p, &sign, &base);
	res = 0;
	while (*p != '\0')
	{
		if (add_digit(p, &res, base, sign))
			break ;
		p++;
	}
	if (endptr != NULL && *p == '\0')
			*endptr = (char *)str;
	else if (endptr != NULL)
			*endptr = (char *)p;
	return (res * sign);
}
