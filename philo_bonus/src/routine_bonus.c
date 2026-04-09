/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 09:47:06 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/09 17:00:55 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	philo_sleep(t_ctx *ctx)
{
	if (ctx->death_flag)
		exit(0);
	print_sleep(ctx);
}

int	routine(t_ctx *ctx)
{
	sem_wait(ctx->sem[PRINT]);
	ctx->watch = the_time(ctx);
	printf("test id: %d what time is it in my watch ? %zu\n", ctx->id, ctx->watch);
	printf("%d\n", ctx->death_flag);
	sem_post(ctx->sem[PRINT]);

	someone_dead(ctx);
	if (ctx->death_flag)
	{
		//je crois qu'il n'y a rien a free;
		//est ce que je dois attendre mon thread ?
		exit (0);
	}
	// while (ctx->death_flag == 0)
	// {
	// 	// philo_eat(ctx);
	// 	philo_sleep(ctx);
	// }
	for (int i = 0; i < 3; i++)
		philo_sleep(ctx);

	sem_post(ctx->sem[parent]);
	close_sem(ctx, NB_SEM);
	exit(0);
}
