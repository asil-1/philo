/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:52:45 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/29 14:50:33 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

size_t	get_current_time(void)
{
	struct timeval	time;
	size_t			current_time;

	if (gettimeofday(&time, NULL) < 0)
	{
		print_error("gettimeofday failed");
		return (-1);
	}
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}

/** @param time in milliseconds*/
void	ft_usleep(size_t time, t_ctx *ctx)
{
	size_t	t_start;

	t_start = get_current_time();
	if (t_start < 0)
	{
		increase_death_status(ctx);
		return ;
	}
	while ((get_current_time() - t_start) < time)
	{
		view_me(ctx);
		if (view_death_status(ctx) > 0)
			return ;
		usleep(10);
	}
}

size_t	the_time(t_ctx *ctx)
{
	size_t	time;

	time = (get_current_time() - ctx->time_start);
	return (time);
}
