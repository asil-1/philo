/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:57:56 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/08 09:43:40 by ldepenne         ###   ########.fr       */
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
	sem_unlink("test");
	sem_unlink("print");
	sem_unlink("child");
}

int	open_sem(t_ctx *ctx)
{
	ctx->sem[test] = sem_open("test", O_CREAT | O_EXCL, 644, 0);
	if (ctx->sem[test] == SEM_FAILED)
	{
		write(2, "Failed to open test semaphore\n", 30);
		return (1);
	}
	ctx->sem[print] = sem_open("print", O_CREAT | O_EXCL, 644, 1);
	if (ctx->sem[print] == SEM_FAILED)
	{
		write(2, "Failed to open test semaphore\n", 30);
		close_sem(ctx, print);
		sem_unlink("test");
		return (1);
	}
	ctx->sem[child] = sem_open("child", O_CREAT | O_EXCL, 644, 0);
	if (ctx->sem[child] == SEM_FAILED)
	{
		write(2, "Failed to open test semaphore\n", 30);
		close_sem(ctx, child);
		sem_unlink("test");
		sem_unlink("print");
		return (1);
	}
	return (0);
}
