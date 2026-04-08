/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:52:45 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/08 11:27:30 by ldepenne         ###   ########.fr       */
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
void	ft_usleep(size_t time)
{
	size_t	t_start;

	t_start = get_current_time();
	if (t_start < 0)
	{
		// ctx->fprint_death++; faut mourrir ici
		// ctx->flag_death++;
	}
	while ((get_current_time() - t_start) < time)
		usleep(10);
}

size_t	the_time(t_ctx *ctx)
{
	size_t	time;

	time = (get_current_time() - ctx->time_start);
	return (time);
}
