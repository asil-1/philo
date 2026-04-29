/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:41:54 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/29 14:15:20 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	main(int argc, char **argv)
{
	t_ctx	ctx;

	if (argc < 5 || argc > 6)
		return (1);
	if (parsing(argv))
		return (1);
	memset(&ctx, 0, sizeof(t_ctx));
	ctx.rules = init_rules(argv);
	if (ctx.rules.flag_meal == -1)
		return (0);
	unlink_all_sem();
	ctx.time_start = get_current_time();
	if (open_sem(&ctx))
		return (1);
	if (child_management(&ctx))
		return (1);
	close_sem(&ctx);
	unlink_all_sem();
	return (0);
}
