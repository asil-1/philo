/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:01:52 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/31 16:45:30 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_b.h>

static int	create_fork(t_ctx *ctx, int nb_philo)
{
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

int	create_sem(t_ctx *ctx)
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
	if (create_fork(ctx, ctx->rules.nb_of_philo) < 0)
		return (-1);
	return (0);
}

void	sem_unlink(t_ctx *ctx) /** @todo change destroy to sem_unlink */
{
	sem_destroy(&ctx->semprint);
	sem_destroy(&ctx->semfork);
	sem_destroy(&ctx->semdeath);
	sem_destroy(&ctx->semeals);
}

/** @todo changer la creation des thread par une creation de process */
int	create_process(t_philo **philo, t_ctx *ctx, int nb_philo)
{
	int	i;

	i = 0;
	*philo = malloc(nb_philo * sizeof(t_philo));
	if (!*philo)
	{
		print_error("Malloc failed");
		return (-1);
	}
	while (i < nb_philo)
	{
		/** remplir la structure t_philo, avec leur pid(fork()), id = i, etc*/
		pid = fork();
		if (pid < 0)
		{
			//unlink les sem
			//noter l'erreur
			//sortir
		}
		// routine()
	}
}

void	wait_process(t_philo *philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		// waitpid
		++i;
	}
	free(philo);
}
