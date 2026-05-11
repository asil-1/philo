/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 09:47:06 by ldepenne          #+#    #+#             */
/*   Updated: 2026/05/11 17:09:27 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static int	all_meal(t_ctx *ctx)
{
	if (view_n_meals(ctx) == ctx->rules.nb_of_meal)
		sem_post(ctx->sem[MEAL]);
	if (ctx->sem[MEAL]->__align == ctx->rules.nb_of_philo)
	{
		increase_death_status(ctx);
		sem_wait(ctx->sem[PRINT]);
		printf("Everyone has eaten!\n");
		sem_post(ctx->sem[PRINT]);
		return (1);
	}
	return (0);
}

static void	alone(t_ctx *ctx)
{
	size_t	deadtime;
	size_t	time_since_last_meal;

	deadtime = (size_t)ctx->rules.time_to_die;
	print_fork(ctx);
	while (1)
	{
		time_since_last_meal = get_current_time() - ctx->time_start;
		if (time_since_last_meal > deadtime)
		{
			print_death(ctx);
			break ;
		}
	}
}

static void	philo_eat(t_ctx *ctx)
{
	if (!(ctx->id % 2))
	{
		print_think(ctx);
		ft_usleep(10, ctx);
		if (view_death_status(ctx) > 0)
			return ;
	}
	sem_wait(ctx->sem[FORK]);
	sem_wait(ctx->sem[FORK]);
	if (view_death_status(ctx) > 0)
	{
		sem_post(ctx->sem[FORK]);
		sem_post(ctx->sem[FORK]);
		return ;
	}
	print_fork(ctx);
	print_fork(ctx);
	print_eat(ctx);
	update_last_time_meal(ctx);
	ft_usleep(ctx->rules.time_to_eat, ctx);
	sem_post(ctx->sem[FORK]);
	sem_post(ctx->sem[FORK]);
}

static void	philo_sleep(t_ctx *ctx)
{
	print_sleep(ctx);
	ft_usleep(ctx->rules.time_to_sleep, ctx);
	if (view_death_status(ctx) > 0)
		return ;
	if (ctx->id % 2)
	{
		print_think(ctx);
		ft_usleep(10, ctx);
	}
}

void	routine(t_ctx *ctx)
{
	if (ctx->rules.nb_of_philo == 1)
	{
		alone(ctx);
		close_sem(ctx);
		unlink_all_sem();
		exit (0);
	}
	create_threads(ctx);
	while (view_death_status(ctx) < 1)
	{
		if (ctx->rules.flag_meal == 1)
		{
			if (all_meal(ctx) == 1)
			{
				finish_process(ctx);
				exit (0);
			}
		}
		philo_eat(ctx);
		if (view_death_status(ctx) > 0)
			break ;
		philo_sleep(ctx);
	}
	finish_process(ctx);
	exit(0);
}
