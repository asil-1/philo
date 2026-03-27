/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:10:49 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/27 18:15:03 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_b.h>

static void	only(t_philo *philo)
{
	print_fork(philo);
	while (someone_dead(philo->ctx) < 1)
		is_dead(philo);
}

static void	philo_eat(t_philo *philo)
{
	if (!(philo->id % 2))
	{
		ft_usleep(10, philo->ctx);
		if (is_dead(philo) == 1 || someone_dead(philo->ctx) >= 1)
			return ;
	}
	sem_wait(&philo->ctx->semfork);
	if (is_dead(philo) == 1 || someone_dead(philo->ctx) >= 1)
	{
		sem_post(&philo->ctx->semfork);
		return ;
	}
	print_fork(philo);
	sem_wait(&philo->ctx->semfork);
	if (is_dead(philo) == 0 || someone_dead(philo->ctx) == 0)
	{
		print_fork(philo);
		print_eat(philo);
		philo->last_timeal = get_current_time();
		ft_usleep(philo->ctx->rules.time_to_eat, philo->ctx);
	}
	sem_post(&philo->ctx->semfork);
	sem_post(&philo->ctx->semfork);
}

static void	philo_sleep(t_philo *philo)
{
	if (someone_dead(philo->ctx) > 0)
		return ;
	print_sleep(philo);
	ft_usleep(philo->ctx->rules.time_to_sleep, philo->ctx);
	if (someone_dead(philo->ctx) > 0)
		return ;
	print_think(philo);
	ft_usleep(10, philo->ctx);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->ctx->rules.nb_of_philo == 1)
		only(philo);
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
