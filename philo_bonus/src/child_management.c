/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:01:24 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/21 14:10:58 by ldepenne         ###   ########.fr       */
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
