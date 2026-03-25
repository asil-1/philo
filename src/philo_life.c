/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:49:13 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/25 09:39:55 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_even_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->fork[philo->id]);
	print_fork(philo);
	if (philo->id == 0)
		pthread_mutex_lock
			(&philo->ctx->fork[philo->ctx->rules.nb_of_philo - 1]);
	else
		pthread_mutex_lock(&philo->ctx->fork[philo->id - 1]);
	print_fork(philo);
	if (philo->deadtime > philo->ctx->rules.time_to_die)
	{
		print_death(philo);
		philo->ctx->death++;
		return ;
	}
	print_eat(philo);
	ft_usleep(philo->ctx->rules.time_to_eat);
	pthread_mutex_unlock(&philo->ctx->fork[philo->id]);
	if (philo->id == 0)
		pthread_mutex_unlock
			(&philo->ctx->fork[philo->ctx->rules.nb_of_philo - 1]);
	else
		pthread_mutex_unlock(&philo->ctx->fork[philo->id - 1]);
}

void	philo_odd_eat(t_philo *philo)
{
	print_think(philo);
	ft_usleep(10);
	pthread_mutex_lock(&philo->ctx->fork[philo->id - 1]);
	print_fork(philo);
	pthread_mutex_lock(&philo->ctx->fork[philo->id]);
	print_fork(philo);
	if (philo->deadtime > philo->ctx->rules.time_to_die)
	{
		print_death(philo);
		philo->ctx->death++;
		return ;
	}
	print_eat(philo);
	ft_usleep(philo->ctx->rules.time_to_eat);
	pthread_mutex_unlock(&philo->ctx->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->ctx->fork[philo->id]);
}

void	philo_eat(t_philo *philo)
{
	if (!(philo->id % 2))
		philo_even_eat(philo);
	else
		philo_odd_eat(philo);
	philo->n_meal++;
}

void	philo_sleep(t_philo *philo)
{
	print_sleep(philo);
	ft_usleep(philo->ctx->rules.time_to_sleep);
	print_think(philo);
	usleep(10);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->ctx->death < 1)
	{
		if (philo->ctx->rules.flag_meal == 1)
		{
			if (all_meal(philo) == 1)
				return (arg);
		}
		if (philo->deadtime > philo->ctx->rules.time_to_die)
		{
			print_death(philo);
			philo->ctx->death++;
			return (arg);
		}
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (arg);
}
