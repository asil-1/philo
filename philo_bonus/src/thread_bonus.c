/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:10:02 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/10 16:25:41 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	*view_all_process(void *arg)
{
	t_ctx *ctx;

	ctx = arg;

	sem_wait(ctx->sem[DEATH]);
	sem_post(ctx->sem[DEATH]);
	ctx->death_flag++;
	return (0);
}

static void	*view_me(void *arg)
{
	t_ctx	*ctx;
	size_t	deadtime;
	size_t	time_since_last_meal;

	ctx = (t_ctx *)arg;
	deadtime = (size_t)ctx->rules.time_to_die;

	while (ctx->death_flag == 0)
	{
		if (ctx->n_meal > 0)
			time_since_last_meal = get_current_time() - ctx->last_timeal;
		else
			time_since_last_meal = get_current_time() - ctx->time_start;
		if (time_since_last_meal > deadtime)
		{
			/* il est mort...
			donc on va le dire aux autres
			on va le dire a l'ecran
			on va arreter le process*/
			sem_post(ctx->sem[DEATH]);
			print_death(ctx);
			ctx->death_flag++;
		}
	}
	return (0);
}

void	create_threads(t_ctx *ctx)
{
	if (pthread_create(&ctx->thread_spy, NULL, view_all_process, ctx))
	{
		print_death(ctx);
		sem_post(ctx->sem[DEATH]);
		ctx->death_flag++;
		return ;
	}
	if (pthread_create(&ctx->thread_me, NULL, view_me, ctx))
	{
		print_death(ctx);
		sem_post(ctx->sem[DEATH]);
		ctx->death_flag++;
		return ;
	}
}
