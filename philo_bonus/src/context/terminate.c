/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatsuo <smatsuo@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 17:13:34 by smatsuo           #+#    #+#             */
/*   Updated: 2023/12/27 14:09:13 by smatsuo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "context.h"
#include "context_internal.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	terminate_philos(t_context *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->num_of_philos)
		kill(ctx->philos[i++].pid, SIGTERM);
}
