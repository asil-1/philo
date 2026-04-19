/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:01:24 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/19 20:25:47 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static int	create_child(t_ctx *ctx)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < ctx->rules.nb_of_philo)
	{
		ctx->pid = fork();
		if (ctx->pid == 0)
		{
			ctx->status = status;
			ctx->id = i;
			sem_unlink("death_flag");//il aime pas parce qu'il unlink ceux deja cree, ils ont le meme nom
			sem_open("death_flag", O_CREAT | O_EXCL, 644, 1);
			if (ctx->sem[DEATH_FLAG] == SEM_FAILED)
			{
				write(2, "Failed to open death_flag semaphore\n", 36);
				exit (1);
			}
			routine(ctx);
		}
		if (ctx->pid < 0)
		{
			close_sem(ctx);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	wait_child(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->rules.nb_of_philo)
	{
		waitpid(-1, &ctx->status, 0);
		i++;
	}
}

int	child_management(t_ctx *ctx)
{
	if (create_child(ctx) != 0)
		return (1);
	wait_child(ctx);
	return (0);
}
