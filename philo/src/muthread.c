/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   muthread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 15:27:33 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/27 15:39:26 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	simple_mutex(t_ctx *ctx)
{
	if (pthread_mutex_init(&ctx->m_print, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&ctx->m_fdead, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&ctx->m_meals, NULL) != 0)
		return (1);
	return (0);
}

int	create_mutex(t_ctx *ctx, int nb_philo)
{
	int	i;

	if (simple_mutex(ctx) > 0)
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
		if (pthread_mutex_init(&ctx->fork[i], NULL) != 0)
		{
			print_error("Create fork mutex failed");
			destroy_mutex(ctx, i);
			return (1);
		}
		++i;
	}
	return (0);
}

void	destroy_mutex(t_ctx *ctx, int nb_of_philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&ctx->m_print);
	pthread_mutex_destroy(&ctx->m_fdead);
	pthread_mutex_destroy(&ctx->m_meals);
	while (i < nb_of_philo)
	{
		pthread_mutex_destroy(&ctx->fork[i]);
		++i;
	}
	free(ctx->fork);
}

int	create_thread(t_philo **philo, t_ctx *ctx, int nb_philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * nb_philo);
	if (!*philo)
	{
		print_error("Malloc failed (create_thread)");
		return (1);
	}
	i = 0;
	while (i < nb_philo)
	{
		(*philo)[i].id = i;
		(*philo)[i].ctx = ctx;
		(*philo)[i].n_meal = 0;
		if (pthread_create
			(&(*philo)[i].thread, NULL, routine, (*philo) + i) != 0)
		{
			print_error("Create thread failed");
			wait_thread(*philo, i);
			return (1);
		}
		++i;
	}
	return (0);
}

void	wait_thread(t_philo *philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_join(philo[i].thread, NULL);
		++i;
	}
	free(philo);
}
