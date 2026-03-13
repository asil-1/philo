/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   muthread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:27:33 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/13 18:00:31 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	create_mutex(t_ctx *ctx, int nb_philo)
{
	int	i;

	if (pthread_mutex_init(&ctx->m_print, NULL) != 0)
	{
		print_error("Create print mutex failed");
		return (1);
	}
	ctx->fork = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (!ctx->fork)
	{
		print_error("Malloc failed (create_mutex)");
		return (1);
	}
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_init(ctx->fork + i, NULL) != 0)
		{
			print_error("Create mutex failed");
			destroy_mutex(ctx, i);
			return (1);
		}
		++i;
	}
	return (0);
}

void	destroy_mutex(t_ctx *ctx, int mutex_to_destroy)
{
	int	i;

	i = 0;
	while (i < mutex_to_destroy)
	{
		pthread_mutex_destroy(ctx->fork + i);
		++i;
	}
	free(ctx->fork);
}

int	create_thread(t_ctx *ctx, int nb_philo)
{
	int	i;

	ctx->philo = malloc(sizeof(t_philo) * nb_philo);
	if (!ctx->philo)
	{
		print_error("Malloc failed (create_thread)");
		return (1);
	}
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_create(&(ctx->philo + i)->thread, NULL, routine, ctx) != 0)
		{
			print_error("Create thread failed");
			wait_thread(ctx, i);
			return (1);
		}
		++i;
	}
	return (0);
}

void	wait_thread(t_ctx *ctx, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_join((ctx->philo + i)->thread, NULL);
		++i;
	}
	free(ctx->philo);
}
