/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:01:52 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/27 18:18:54 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_b.h>

int	create_sem(t_ctx *ctx, int nb_philo)
{
	if (sem_init(&ctx->semprint, 0, 1) < 0)
	{
		print_error("Create semaphore failed");
		return (-1);
	}
	if (sem_init(&ctx->semdeath, 0, 1) < 0)
	{
		print_error("Create semaphore failed");
		sem_destroy(&ctx->semprint);
		return (-1);
	}
	if (sem_init(&ctx->semeals, 0, 1) < 0)
	{
		print_error("Create semaphore failed");
		sem_destroy(&ctx->semprint);
		sem_destroy(&ctx->semdeath);
		return (-1);
	}
	if (sem_init(&ctx->semfork, 0, nb_philo) < 0)
	{
		print_error("Create semaphore failed");
		sem_destroy(&ctx->semprint);
		sem_destroy(&ctx->semdeath);
		sem_destroy(&ctx->semeals);
		return (-1);
	}
	return (0);
}

void	destroy_sem(t_ctx *ctx)
{
	sem_destroy(&ctx->semprint);
	sem_destroy(&ctx->semfork);
	sem_destroy(&ctx->semdeath);
	sem_destroy(&ctx->semeals);
}

int	create_thread(t_philo **philo, t_ctx *ctx, int nb_philo)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * nb_philo);
	if (!*philo)
	{
		print_error("Malloc failed (create_thread)");
		return (-1);
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
			return (-1);
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
