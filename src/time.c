/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:02:27 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/24 13:37:45 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	get_current_time(void)
{
	size_t	current_time;
	struct timeval	time;

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
	size_t t_start;

	t_start = get_current_time();
	if (t_start < 0)
		(void)time; //faire un truc de cette erreur
	while ((get_current_time() - t_start) < time)
		usleep(10);
}

void	the_time(t_philo *philo)
{
	size_t	time;

	time = get_current_time() - philo->ctx->time_start;
	philo->watch = time;
}