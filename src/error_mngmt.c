/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mngmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:49:44 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/24 13:15:52 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}
