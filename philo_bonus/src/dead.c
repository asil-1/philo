/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:10:02 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/09 15:40:01 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	*is_dead(void *arg)
{
	t_ctx *ctx;

	ctx = arg;
	sem_wait(ctx->sem[DEATH]);
	sem_post(ctx->sem[DEATH]);
	ctx->death_flag++;
	return (0);
}

void	someone_dead(t_ctx *ctx)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, is_dead, ctx))
	{
		sem_post(ctx->sem[DEATH]);
		ctx->death_flag++;
		//printf(msg je suis mort)
		return ;
	}
	pthread_detach(thread); /** @todo change for pthread_join. */
}