/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:30:36 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/13 18:00:20 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//colors
# define GREEN "\e[32m"
// # define BLUE "\e[34m"
# define CYAN "\e[36m"
# define NC "\e[0m"

# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_rules
{
	int	nb_of_meal;
	int	nb_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_rules;

typedef struct s_philo
{
	pthread_t	thread;
	int			n_philo;
}	t_philo;

typedef struct ctx
{
	t_rules			rules;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_print;
}	t_ctx;

//muthread.c
void	destroy_mutex(t_ctx *ctx, int mutex_to_destroy);
int		create_thread(t_ctx *ctx, int nb_philo);
int		create_mutex(t_ctx *ctx, int nb_philo);
void	wait_thread(t_ctx *ctx, int nb_philo);


//philo_life.c
void	*routine(void *data);
// int		philo_life(t_ctx *ctx, size_t );

//utils.c
size_t	ft_strlen(char *s);
void	print_error(char *msg);
t_rules	init_rules(char **argv);

#endif