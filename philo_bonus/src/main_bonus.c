/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:41:54 by ldepenne          #+#    #+#             */
/*   Updated: 2026/05/06 11:47:32 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc < 5 || argc > 6 || parsing(argv))
		return (1);
	memset(&ctx, 0, sizeof(t_ctx));
	ctx.rules = init_rules(argv);
	if (ctx.rules.flag_meal == -1)
		return (0);
	unlink_all_sem();
	ctx.time_start = get_current_time();
	if (ctx.time_start == 0)
	{
		print_error("gettimeofday failed");
		return (1);
	}
	if (open_sem(&ctx))
		return (1);
	if (child_management(&ctx))
		return (1);
	close_sem(&ctx);
	unlink_all_sem();
	return (0);
}
