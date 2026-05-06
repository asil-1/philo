/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:57:56 by ldepenne          #+#    #+#             */
/*   Updated: 2026/05/06 11:09:17 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	close_sem(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < NB_SEM)
	{
		sem_close(ctx->sem[i]);
		i++;
	}
}

void	unlink_all_sem(void)
{
	sem_unlink("fork");
	sem_unlink("meal");
	sem_unlink("print");
	sem_unlink("death");
	sem_unlink("n_meal");
	sem_unlink("time_meal");
	sem_unlink("death_flag");
}

int	open_sem(t_ctx *ctx)
{
	int	i;

	i = 0;
	ctx->sem[FORK] = sem_open("fork", O_CREAT | O_EXCL, 644,
			ctx->rules.nb_of_philo);
	ctx->sem[MEAL] = sem_open("meal", O_CREAT | O_EXCL, 644, 0);
	ctx->sem[PRINT] = sem_open("print", O_CREAT | O_EXCL, 644, 1);
	ctx->sem[DEATH] = sem_open("death", O_CREAT | O_EXCL, 644, 0);
	ctx->sem[N_MEAL] = sem_open("n_meal", O_CREAT | O_EXCL, 644, 1);
	ctx->sem[TIME_MEAL] = sem_open("time_meal", O_CREAT | O_EXCL, 644, 1);
	ctx->sem[DEATH_FLAG] = sem_open("death_flag", O_CREAT | O_EXCL, 644, 1);
	while (i < NB_SEM)
	{
		if (ctx->sem[i] == SEM_FAILED)
		{
			write(2, "Failed to open semaphore\n", 25);
			close_sem(ctx);
			unlink_all_sem();
			return (1);
		}
		i++;
	}
	return (0);
}
