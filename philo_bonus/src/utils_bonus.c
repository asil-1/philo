/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:51:45 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/29 15:13:02 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
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
	if (rules.time_to_die < 60 || rules.time_to_eat < 60
		|| rules.time_to_sleep < 60)
	{
		print_error("Error to time");
		rules.flag_meal = -1;
	}
	return (rules);
}

void	finish_process(t_ctx *ctx)
{
	usleep(1);
	unlink_all_sem();
	close_sem(ctx);
	// pthread_join(ctx->thread_me, NULL);
}

void	view_me(t_ctx *ctx)
{
	size_t	time_since_last_meal;

	if (view_n_meals(ctx) > 0)
		time_since_last_meal = get_current_time()
			- view_last_time_meal(ctx);
	else
		time_since_last_meal = get_current_time() - ctx->time_start;
	if (time_since_last_meal > (size_t)ctx->rules.time_to_die)
	{
		sem_wait(ctx->sem[PRINT]);
		print_death(ctx);
		increase_death_status(ctx);
		sem_post(ctx->sem[PRINT]);
	}
}
