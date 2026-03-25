/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:54:05 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/25 14:27:13 by ldepenne         ###   ########.fr       */
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

static int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nb;

	if (!nptr)
		return (0);
	sign = 1;
	nb = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	return (nb * sign);
}

int	parcing(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				printf("%c\n", argv[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	if (ft_atoi(argv[1]) > 200)
		return (1);
	return (0);
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
