/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:10:02 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/27 15:26:09 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	*view_me(void *arg)
{
	t_ctx	*ctx;
	size_t	deadtime;
	size_t	time_since_last_meal;

	ctx = (t_ctx *)arg;
	deadtime = (size_t)ctx->rules.time_to_die;
	while (view_death_status(ctx) == 0)
	{
		if (view_n_meals(ctx) > 0)
			time_since_last_meal = get_current_time()
				- view_last_time_meal(ctx);
		else
			time_since_last_meal = get_current_time() - ctx->time_start;
		if (time_since_last_meal > deadtime)
		{
			sem_wait(ctx->sem[PRINT]);
			print_death(ctx);
			increase_death_status(ctx);
			sem_post(ctx->sem[PRINT]);
		}
	}
	return (0);
}

void	create_threads(t_ctx *ctx)
{
	ctx->last_timeal = get_current_time();
	if (pthread_create(&ctx->thread_me, NULL, view_me, ctx))
	{
		sem_wait(ctx->sem[PRINT]);
		sem_post(ctx->sem[DEATH]);
		increase_death_status(ctx);
		printf("create thread_me failed\n");
		sem_post(ctx->sem[PRINT]);
		return ;
	}
}
