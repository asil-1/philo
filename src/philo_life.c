/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:49:13 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/26 11:04:22 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
		ft_usleep(philo->ctx->rules.time_to_eat, philo->ctx);
	}
	pthread_mutex_unlock(&philo->ctx->fork[philo->id]);
	pthread_mutex_unlock(&philo->ctx->fork[left_fork]);
}

void	philo_odd_eat(t_philo *philo)
{
	if (is_dead(philo) == 1 || someone_dead(philo->ctx) >= 1)
		return ;
	print_think(philo);
	ft_usleep(10, philo->ctx);
	if (is_dead(philo) == 1 || someone_dead(philo->ctx) >= 1)
		return ;
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
		ft_usleep(philo->ctx->rules.time_to_eat, philo->ctx);
	}
	pthread_mutex_unlock(&philo->ctx->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->ctx->fork[philo->id]);
}

void	philo_eat(t_philo *philo)
{
	if (!(philo->id % 2))
		philo_even_eat(philo);
	else
		philo_odd_eat(philo);
}

void	philo_sleep(t_philo *philo)
{
	if (someone_dead(philo->ctx) > 0)
		return ;
	print_sleep(philo);
	ft_usleep(philo->ctx->rules.time_to_sleep, philo->ctx);
	if (!(philo->id % 2))
	{
		if (someone_dead(philo->ctx) > 0)
			return ;
		print_think(philo);
		ft_usleep(10, philo->ctx);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (someone_dead(philo->ctx) < 1)
	{
		if (philo->ctx->rules.flag_meal == 1)
		{
			if (all_meal(philo) == 1)
				return (arg);
		}
		philo_eat(philo);
		philo_sleep(philo);
		if (someone_dead(philo->ctx) > 0)
			return (NULL);
		is_dead(philo);
	}
	return (arg);
}
