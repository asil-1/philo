/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:08:39 by ldepenne          #+#    #+#             */
/*   Updated: 2026/05/06 10:28:10 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	the_time(philo);
	if (someone_dead(philo->ctx) == 0)
		printf("%s%zu %d has taken a fork%s\n",
			LIGHT_YELLOW, philo->watch, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}

void	print_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	the_time(philo);
	if (someone_dead(philo->ctx) == 0)
		printf("%s%zu %d is eating%s\n",
			YELLOW, philo->watch, philo->id, NO_COLOR);
	philo->n_meal++;
	pthread_mutex_unlock(&philo->ctx->m_print);
}

void	print_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	the_time(philo);
	if (someone_dead(philo->ctx) == 0)
		printf("%s%zu %d is sleeping%s\n",
			DARK_BLUE, philo->watch, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}

void	print_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	the_time(philo);
	if (someone_dead(philo->ctx) == 0)
		printf("%s%zu %d is thinking%s\n",
			BLUE, philo->watch, philo->id, NO_COLOR);
	pthread_mutex_unlock(&philo->ctx->m_print);
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->ctx->m_print);
	the_time(philo);
	if (philo->ctx->fprint_death == 0)
		printf("%s%zu %d died%s\n",
			DEATH_COLOR, philo->watch, philo->id, NO_COLOR);
	philo->ctx->fprint_death++;
	pthread_mutex_unlock(&philo->ctx->m_print);
}
