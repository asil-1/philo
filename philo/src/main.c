/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:32:13 by ldepenne          #+#    #+#             */
/*   Updated: 2026/05/06 11:47:53 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_ctx	ctx;
	t_philo	*philo;

	if (argc < 5 || argc > 6 || parsing(argv))
		return (1);
	memset(&ctx, 0, sizeof(t_ctx));
	ctx.rules = init_rules(argv);
	if (ctx.rules.flag_meal == -1)
		return (0);
	philo = NULL;
	ctx.time_start = get_current_time();
	if (ctx.time_start == 0)
	{
		print_error("gettimeofday failed");
		return (1);
	}
	if (create_mutex(&ctx, ctx.rules.nb_of_philo) > 0)
		return (1);
	if (create_thread(&philo, &ctx, ctx.rules.nb_of_philo) == 0)
		wait_thread(philo, ctx.rules.nb_of_philo);
	destroy_mutex(&ctx, ctx.rules.nb_of_philo);
	if (ctx.meals >= ctx.rules.nb_of_philo)
		printf("Wow! Everyone’s eaten!\n");
	return (0);
}
