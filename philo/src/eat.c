/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:02:00 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/27 17:37:25 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_even_eat(t_philo *philo)
{
	int	left_fork;

	left_fork = philo->id - 1;
	if (philo->id == 0)
		left_fork = philo->ctx->rules.nb_of_philo - 1;
	pthread_mutex_lock(&philo->ctx->fork[philo->id]);
	if (is_dead(philo) == 1 || someone_dead(philo->ctx) >= 1)
	{
		pthread_mutex_unlock(&philo->ctx->fork[philo->id]);
		return ;
	}
	print_fork(philo);
	pthread_mutex_lock(&philo->ctx->fork[left_fork]);
	if (is_dead(philo) == 0 || someone_dead(philo->ctx) == 0)
	{
		print_fork(philo);
		print_eat(philo);
		philo->last_timeal = get_current_time();
		ft_usleep(philo->ctx->rules.time_to_eat, philo);
	}
	pthread_mutex_unlock(&philo->ctx->fork[philo->id]);
	pthread_mutex_unlock(&philo->ctx->fork[left_fork]);
}

void	philo_odd_eat(t_philo *philo)
{
	print_think(philo);
	ft_usleep(10, philo);
	pthread_mutex_lock(&philo->ctx->fork[philo->id - 1]);
	if (is_dead(philo) == 1 || someone_dead(philo->ctx) >= 1)
	{
		pthread_mutex_unlock(&philo->ctx->fork[philo->id - 1]);
		return ;
	}
	print_fork(philo);
	pthread_mutex_lock(&philo->ctx->fork[philo->id]);
	if (is_dead(philo) == 0 || someone_dead(philo->ctx) == 0)
	{
		print_fork(philo);
		print_eat(philo);
		philo->last_timeal = get_current_time();
		ft_usleep(philo->ctx->rules.time_to_eat, philo);
	}
	pthread_mutex_unlock(&philo->ctx->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->ctx->fork[philo->id]);
}

void	do_we_live_to_eat_or_do_we_eat_to_live(t_philo *philo)
{
	print_fork(philo);
	while (someone_dead(philo->ctx) < 1)
		is_dead(philo);
}
