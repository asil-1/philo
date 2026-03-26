/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:54:05 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/26 10:56:02 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}	

t_rules	init_rules(char **argv)
{
	t_rules	rules;

	rules.flag_meal = 0;
	rules.nb_of_philo = ft_atoi(argv[1]);
	rules.time_to_die = ft_atoi(argv[2]);
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		rules.flag_meal = 1;
		rules.nb_of_meal = ft_atoi(argv[5]);
	}
	return (rules);
}

int	all_meal(t_philo *philo)
{
	int	result;

	pthread_mutex_lock(&philo->ctx->m_meals);
	result = 0;
	if (philo->n_meal == philo->ctx->rules.nb_of_meal)
		philo->ctx->meals++;
	if (philo->ctx->meals >= philo->ctx->rules.nb_of_philo)
		result = 1;
	pthread_mutex_unlock(&philo->ctx->m_meals);
	return (result);
}
