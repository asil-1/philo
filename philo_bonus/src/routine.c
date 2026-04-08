/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 09:47:06 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/08 11:29:46 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	routine(t_ctx *ctx)
{
	sem_wait(ctx->sem[print]);
	ctx->watch = the_time(ctx);
	printf("test id: %d what time is it in my watch ? %zu\n", ctx->id, ctx->watch);
	sem_post(ctx->sem[print]);
	sem_post(ctx->sem[test]);
	close_sem(ctx, NB_SEM);
	exit(0);
}
