/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 02:33:08 by smatsuo           #+#    #+#             */
/*   Updated: 2024/01/02 15:59:37 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "context/context_internal.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_context	ctx;

	if (init_context(&ctx, argc, argv))
		return (print_error());
	if (start_eating(&ctx))
	{
		terminate_philos(&ctx);
		destroy_context(&ctx);
		return (print_error());
	}
	wait_philos(&ctx);
	destroy_context(&ctx);
}
