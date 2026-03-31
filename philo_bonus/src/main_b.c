/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:41:54 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/29 16:56:12 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_b.h>

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	t_philo	*philo;

	if (argc < 5 || argc > 6)
		return (1);
	if (parcing(argv))
		return (1);
	memset(&ctx, 0, sizeof(t_ctx));
	ctx.rules = init_rules(argv);
	philo = NULL;
	ctx.time_start = get_current_time();
	if (create_sem(&ctx) < 0)
		return (1);
	if (create_process(&philo, &ctx, ctx.rules.nb_of_philo) == 0)
		wait_process(philo, ctx.rules.nb_of_philo);
	destroy_sem(&ctx);
	return (0);
}
