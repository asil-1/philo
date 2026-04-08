/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:41:54 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/08 10:30:19 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc < 5 || argc > 6)
		return (1);
	if (parcing(argv))
		return (1);
	memset(&ctx, 0, sizeof(t_ctx));
	ctx.rules = init_rules(argv);
	unlink_all_sem();
	ctx.time_start = get_current_time();
	if (open_sem(&ctx))
		return (1);
	if (child_management(&ctx))
		return (1);
	close_sem(&ctx, NB_SEM);
	unlink_all_sem();
	return (0);
}

	// if (create_sem(&ctx) < 0)
	// 	return (1);
	// if (create_process(&philo, &ctx, ctx.rules.nb_of_philo, status) == 0)
	// 	wait_process(philo, ctx.rules.nb_of_philo, status);
	// close_and_unlink(&ctx);
