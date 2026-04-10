/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 09:47:06 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/10 16:44:31 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static int	all_meal(t_ctx *ctx)
{
	/* si c'est == a l'objectif alors j'incremente le semaphore
	je verif si la taille du semaphore est == au nb de philo
	si c'est le cas tout le monde a asser mangé, faut partir*/
	if (ctx->n_meal == ctx->rules.nb_of_meal)
		ctx->sem[MEAL]++;
	printf("sem[MEAL]_size: %ld\n", ctx->sem[MEAL]->__align);
	if (ctx->sem[MEAL]->__align == ctx->rules.nb_of_philo)
	{
		sem_post(ctx->sem[DEATH]);
		return (1);
	}
	return (0);
}

static void	alone(t_ctx *ctx)
{
	print_fork(ctx);
	while (1)
	{
		if (ctx->death_flag > 0)
			break ;
	}
}

static void	philo_eat(t_ctx *ctx)
{
	if (!(ctx->id % 2))
	{
		print_think(ctx);
		ft_usleep(10);
		if (ctx->death_flag > 0)
			return ;
	}
	sem_wait(ctx->sem[FORK]);
	if (ctx->death_flag > 0)
		return ;
	print_fork(ctx);
	sem_wait(ctx->sem[FORK]);
	if (ctx->death_flag > 0)
		return ;
	print_fork(ctx);
	print_eat(ctx);
	ctx->n_meal++;
	ft_usleep(ctx->rules.time_to_eat);
	if (ctx->death_flag > 0)
		return ;
	sem_post(ctx->sem[FORK]);
	sem_post(ctx->sem[FORK]);
}

static void	philo_sleep(t_ctx *ctx)
{
	print_sleep(ctx);
	ft_usleep(ctx->rules.time_to_sleep);
	if (ctx->death_flag > 0)
		return ;
	if (ctx->id % 2)
	{
		print_think(ctx);
		ft_usleep(10);
	}
}

void	routine(t_ctx *ctx)
{
	if (ctx->rules.nb_of_philo == 1)
	{
		alone(ctx);
		close_sem(ctx);
		unlink_all_sem();
		exit (0);
	}
	create_threads(ctx);
	while (ctx->death_flag < 1)
	{
		if (ctx->rules.flag_meal == 1)
		{
			if (all_meal(ctx) == 1)
			{
				finish_process(ctx);
				exit (0);
			}
		}
		philo_eat(ctx);
		if (ctx->death_flag > 0)
			break ;
		philo_sleep(ctx);
	}
	finish_process(ctx);
	exit(0);
}


// int	routine(t_ctx *ctx)
// {
// 	// sem_wait(ctx->sem[PRINT]);
// 	// ctx->watch = the_time(ctx);
// 	// printf("test id: %d what time is it in my watch ? %zu\n", ctx->id, ctx->watch);
// 	// printf("%d\n", ctx->death_flag);
// 	// sem_post(ctx->sem[PRINT]);
// 	someone_dead(ctx);
// 	i_m_dead(ctx);
// 	if (ctx->id == 2)
// 	{
// 		print_death(ctx);
// 		sem_post(ctx->sem[DEATH]);
// 	}
// 	while (1)
// 	{
// 		if (ctx->death_flag > 0)
// 		{
// 			// sem_post(ctx->sem[parent]);
// 			// print_death(ctx);
// 			pthread_join(ctx->thread, NULL);
// 			close_sem(ctx, NB_SEM);
// 			exit (0);
// 		}
// 		philo_sleep(ctx);
// 	}
// 	printf("%d\n", ctx->death_flag);
// 	// sem_post(ctx->sem[parent]);
// 	close_sem(ctx, NB_SEM);
// 	pthread_join(ctx->thread, NULL);
// 	exit(0);
// }
