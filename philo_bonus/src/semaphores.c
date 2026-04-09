/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:57:56 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/09 17:04:03 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

/** @param nb nb to close */
void	close_sem(t_ctx *ctx, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		sem_close(ctx->sem[i]);
		i++;
	}
}

void	unlink_all_sem(void)
{
	sem_unlink("parent");
	sem_unlink("print");
	sem_unlink("death");
}

int	open_sem(t_ctx *ctx)
{
	ctx->sem[parent] = sem_open("parent", O_CREAT | O_EXCL, 644, 0);
	if (ctx->sem[parent] == SEM_FAILED)
	{
		write(2, "Failed to open parent semaphore\n", 30);
		return (1);
	}
	ctx->sem[PRINT] = sem_open("print", O_CREAT | O_EXCL, 644, 1);
	if (ctx->sem[PRINT] == SEM_FAILED)
	{
		write(2, "Failed to open print semaphore\n", 30);
		close_sem(ctx, PRINT);
		unlink_all_sem();
		return (1);
	}
	ctx->sem[DEATH] = sem_open("death", O_CREAT | O_EXCL, 644, 0);
	if (ctx->sem[DEATH] == SEM_FAILED)
	{
		write(2, "Failed to open death semaphore\n", 30);
		close_sem(ctx, DEATH);
		unlink_all_sem();
		return (1);
	}
	return (0);
}
