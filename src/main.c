/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:32:13 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/24 15:38:07 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (1);
	if (parcing(argv))
	{
		print_error("invalid argument");
		return (1);
	}
	memset(&ctx, 0, sizeof(t_ctx));
	ctx.rules = init_rules(argv);
	philo = NULL;
	ctx.time_start = get_current_time();
	if (create_mutex(&ctx, ctx.rules.nb_of_philo) > 0)
		return (1);
	if (create_thread(&philo, &ctx, ctx.rules.nb_of_philo) == 0)
		wait_thread(philo, ctx.rules.nb_of_philo);
	destroy_mutex(&ctx, ctx.rules.nb_of_philo);
	return (0);
}
