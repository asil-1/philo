/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:49:13 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/24 13:26:19 by ldepenne         ###   ########.fr       */
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
}

void	philo_sleep(t_philo *philo)
{
	print_sleep(philo);
	ft_usleep(philo->ctx->rules.time_to_sleep);
	print_think(philo); //attention les philo impairs pensent deux fois, a voir si ça pose un pblm
	usleep(10);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	// tant qu epersonne n'est mort -> ajouter un bool die dans ctx, quand quelqu'un l'actionne c'est la fin on print et on sort du programme
	if (philo->ctx->rules.nb_of_meal)
	{
		i = 0;
		while (i < philo->ctx->rules.nb_of_meal && philo->ctx->death < 1)
		{
			philo_eat(philo);
			philo_sleep(philo);
			i++;
		}
	}
	else
	{
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (arg);
}
