/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:52:15 by ldepenne          #+#    #+#             */
/*   Updated: 2026/05/06 14:08:58 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

long	ft_atol(const char *nptr)
{
	long	sign;
	long	nb;

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

static int	isnum(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
		{
			print_error("invalid argument");
			return (1);
		}
		i++;
	}
	return (0);
}

int	parsing(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > INT_MAX)
		{
			print_error("a number is too large");
			return (1);
		}
		if (isnum(argv[i]) == 1)
			return (1);
		i++;
	}
	if (ft_atol(argv[1]) < 1)
	{
		print_error("not enough philosophers");
		return (1);
	}
	return (0);
}
