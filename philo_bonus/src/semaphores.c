/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:57:56 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/10 16:11:01 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	close_sem(t_ctx *ctx)
{
	int i;

	i = 0;
	while (i < NB_SEM)
	{
		sem_close(ctx->sem[i]);
		i++;
	}
}

void	unlink_all_sem(void)
{
	sem_unlink("parent");
	sem_unlink("death");
	sem_unlink("meal");
	sem_unlink("print");
	sem_unlink("fork");
}

int	open_sem(t_ctx *ctx)
{
	int	i;

	i = 0;
	ctx->sem[parent] = sem_open("parent", O_CREAT | O_EXCL, 644, 0);
	ctx->sem[DEATH] = sem_open("death", O_CREAT | O_EXCL, 644, 0);
	ctx->sem[MEAL] = sem_open("meal", O_CREAT | O_EXCL, 644, 0);
	ctx->sem[PRINT] = sem_open("print", O_CREAT | O_EXCL, 644, 1);
	ctx->sem[FORK] = sem_open("fork", O_CREAT | O_EXCL, 644, ctx->rules.nb_of_philo);
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
