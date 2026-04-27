/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:49:13 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/27 15:04:15 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
	ft_usleep(philo->ctx->rules.time_to_sleep, philo);
	if (!(philo->id % 2))
	{
		if (someone_dead(philo->ctx) > 0)
			return ;
		print_think(philo);
		ft_usleep(10, philo);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->ctx->rules.nb_of_philo == 1)
		do_we_live_to_eat_or_do_we_eat_to_live(philo);
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
