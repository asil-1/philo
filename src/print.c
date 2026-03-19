/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:08:39 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/19 14:22:11 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	printf("%stimestamp_in_ms %d has taken a fork %s\n",
		BROWN, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}

void	print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	printf("%stimestamp_in_ms %d is eating %s\n", YELLOW, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}

void	print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	printf("%stimestamp_in_ms %d is sleeping %s\n", BLUE, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}

void	print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	printf("%stimestamp_in_ms %d is thinking %s\n", CYAN, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	printf("%stimestamp_in_ms %d died %s\n", DEATH_COLOR, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}
