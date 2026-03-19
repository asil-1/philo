/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:49:13 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/19 14:21:16 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	even_eat(t_philo *philo)
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
	usleep(philo->ctx->rules.time_to_eat);
	pthread_mutex_unlock(&philo->ctx->fork[philo->id]);
	if (philo->id == 0)
		pthread_mutex_unlock
			(&philo->ctx->fork[philo->ctx->rules.nb_of_philo - 1]);
	else
		pthread_mutex_unlock(&philo->ctx->fork[philo->id - 1]);
}

void	odd_eat(t_philo *philo)
{
	print_think(philo);
	usleep(10);
	pthread_mutex_lock(&philo->ctx->fork[philo->id - 1]);
	print_fork(philo);
	pthread_mutex_lock(&philo->ctx->fork[philo->id]);
	print_fork(philo);
	print_eat(philo);
	usleep(philo->ctx->rules.time_to_eat);
	pthread_mutex_unlock(&philo->ctx->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->ctx->fork[philo->id]);
}

void	eat(t_philo *philo)
{
	if (!(philo->id % 2))
		even_eat(philo);
	else
		odd_eat(philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	eat(philo);
	// dormir
		//apres avoir dormi faut penser, au moins pour les pair
	return (arg);
}
