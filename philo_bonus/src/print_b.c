/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:16:23 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/27 17:40:26 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_b.h>

void	print_fork(t_philo *philo)
{
	sem_wait(&philo->ctx->semprint);
	the_time(philo);
	if (someone_dead(philo->ctx) == 0)
		printf("%s%zu %d has taken a fork%s\n",
			BLUE, philo->watch, philo->id, NC);
	sem_post(&philo->ctx->semprint);
}

void	print_eat(t_philo *philo)
{
	sem_wait(&philo->ctx->semprint);
	the_time(philo);
	if (someone_dead(philo->ctx) == 0)
		printf("%s%zu %d is eating%s\n",
			HIGH_BLUE, philo->watch, philo->id, NC);
	philo->n_meal++;
	sem_post(&philo->ctx->semprint);
}

void	print_sleep(t_philo *philo)
{
	sem_wait(&philo->ctx->semprint);
	the_time(philo);
	if (someone_dead(philo->ctx) == 0)
		printf("%zu %d is sleeping\n", philo->watch, philo->id);
	sem_post(&philo->ctx->semprint);
}

void	print_think(t_philo *philo)
{
	sem_wait(&philo->ctx->semprint);
	the_time(philo);
	if (someone_dead(philo->ctx) == 0)
		printf("%s%zu %d is thinking%s\n",
			CYAN, philo->watch, philo->id, NC);
	sem_post(&philo->ctx->semprint);
}

void	print_death(t_philo *philo)
{
	sem_wait(&philo->ctx->semprint);
	the_time(philo);
	if (philo->ctx->fprint_death == 0)
		printf("%s%zu %d died%s\n",
			DEATH_COLOR, philo->watch, philo->id, NC);
	philo->ctx->fprint_death++;
	sem_post(&philo->ctx->semprint);
}
