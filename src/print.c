/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:08:39 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/24 13:40:30 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	the_time(philo);
	printf("%s%zu %d has taken a fork %s\n",
		BROWN, philo->watch, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}

void	print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	the_time(philo);
	printf("%s%zu %d is eating %s\n", YELLOW, philo->watch, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}

void	print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	the_time(philo);
	printf("%s%zu %d is sleeping %s\n", BLUE, philo->watch, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}

void	print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	the_time(philo);
	printf("%s%zu %d is thinking %s\n", CYAN, philo->watch, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	the_time(philo);
	printf("%s%zu %d died %s\n", DEATH_COLOR, philo->watch, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}
