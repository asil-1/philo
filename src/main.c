/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:32:13 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/19 13:43:59 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	t_philo	*philo;

	if (argc < 4 || argc > 5)
		return (1);
	memset(&ctx, 0, sizeof(t_ctx));
	ctx.rules = init_rules(argv);
	philo = NULL;
	if (create_mutex(&ctx, ctx.rules.nb_of_philo) > 0)
		return (1);
	if (create_thread(&philo, &ctx, ctx.rules.nb_of_philo) == 0)
		wait_thread(philo, ctx.rules.nb_of_philo);
	destroy_mutex(&ctx, ctx.rules.nb_of_philo);
	return (0);
}
