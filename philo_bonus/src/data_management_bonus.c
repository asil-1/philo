/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_management_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 11:27:49 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/29 11:41:14 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	view_death_status(t_ctx *ctx)
{
	int	status;

	sem_wait(ctx->sem[DEATH_FLAG]);
	status = ctx->sem[DEATH]->__align;
	sem_post(ctx->sem[DEATH_FLAG]);
	return (status);
}

void	increase_death_status(t_ctx *ctx)
{
	sem_wait(ctx->sem[DEATH_FLAG]);
	sem_post(ctx->sem[DEATH]);
	sem_post(ctx->sem[DEATH_FLAG]);
}

int	view_n_meals(t_ctx *ctx)
{
	int	numbers_of_meals;

	sem_wait(ctx->sem[N_MEAL]);
	numbers_of_meals = ctx->n_meal;
	sem_post(ctx->sem[N_MEAL]);
	return (numbers_of_meals);
}

void	update_last_time_meal(t_ctx *ctx)
{
	sem_wait(ctx->sem[TIME_MEAL]);
	ctx->last_timeal = get_current_time();
	sem_post(ctx->sem[TIME_MEAL]);
}

size_t	view_last_time_meal(t_ctx *ctx)
{
	size_t	last_time;

	sem_wait(ctx->sem[TIME_MEAL]);
	last_time = ctx->last_timeal;
	sem_post(ctx->sem[TIME_MEAL]);
	return (last_time);
}
