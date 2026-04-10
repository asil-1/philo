/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:50:34 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/10 11:47:15 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	print_fork(t_ctx *ctx)
{
	sem_wait(ctx->sem[PRINT]);
	the_time(ctx);
	if (ctx->death_flag == 0)
		printf("%s%zu %d has taken a fork %s\n",
			HIGH_BLUE, ctx->watch, ctx->id, NC);
	sem_post(ctx->sem[PRINT]);
}

void	print_eat(t_ctx *ctx)
{
	sem_wait(ctx->sem[PRINT]);
	the_time(ctx);
	if (ctx->death_flag == 0)
		printf("%s%zu %d is eating %s\n",
			BLUE, ctx->watch, ctx->id, NC);
	// philo->n_meal++;
	sem_post(ctx->sem[PRINT]);
}

void	print_sleep(t_ctx *ctx)
{
	sem_wait(ctx->sem[PRINT]);
	the_time(ctx);
	if (ctx->death_flag == 0)
		printf("%s%zu %d is sleeping %s\n",
			CYAN, ctx->watch, ctx->id, NC);
	sem_post(ctx->sem[PRINT]);
}

void	print_think(t_ctx *ctx)
{
	sem_wait(ctx->sem[PRINT]);
	the_time(ctx);
	if (ctx->death_flag == 0)
		printf("%zu %d is thinking\n", ctx->watch, ctx->id);
	sem_post(ctx->sem[PRINT]);
}

void	print_death(t_ctx *ctx)
{
	sem_wait(ctx->sem[PRINT]);
	the_time(ctx);
		printf("%s%zu %d died %s\n",
			DEATH_COLOR, ctx->watch, ctx->id, NC);
	sem_post(ctx->sem[PRINT]);
}
