/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_management_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:01:24 by ldepenne          #+#    #+#             */
/*   Updated: 2026/05/07 10:59:08 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static int	create_child(t_ctx *ctx)
{
	int	i;

	i = 0;
	while (i < ctx->rules.nb_of_philo)
	{
		ctx->pid = fork();
		if (ctx->pid == 0)
		{
			ctx->status_pid = 0;
			ctx->id = i;
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
		waitpid(-1, &ctx->status_pid, 0);
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
