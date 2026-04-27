/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:02:27 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/27 15:04:35 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
void	ft_usleep(size_t time, t_philo *philo)
{
	size_t	t_start;

	t_start = get_current_time();
	if (t_start < 0)
	{
		philo->ctx->fprint_death++;
		philo->ctx->flag_death++;
	}
	while ((get_current_time() - t_start) < time)
	{
		if (is_dead(philo) > 0)
			return ;
		usleep(10);
	}
}

void	the_time(t_philo *philo)
{
	size_t	time;

	time = (get_current_time() - philo->ctx->time_start);
	philo->watch = time;
}

int	is_dead(t_philo *philo)
{
	size_t	deadtime;
	size_t	time_since_last_meal;

	deadtime = (size_t)philo->ctx->rules.time_to_die;
	if (philo->n_meal > 0)
		time_since_last_meal = get_current_time() - philo->last_timeal;
	else
		time_since_last_meal = get_current_time() - philo->ctx->time_start;
	if (time_since_last_meal > deadtime)
	{
		pthread_mutex_lock(&philo->ctx->m_fdead);
		philo->ctx->flag_death++;
		pthread_mutex_unlock(&philo->ctx->m_fdead);
		print_death(philo);
		return (1);
	}
	return (0);
}
