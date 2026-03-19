/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:30:36 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/19 14:20:07 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

//colors
# define DEATH_COLOR "\e[40;1;31m"
# define BROWN "\e[33m"
# define YELLOW "\e[93m"
# define BLUE "\e[94m"
# define CYAN "\e[96m"
# define NO_COLOR "\e[0m"

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

typedef struct ctx
{
	t_rules			rules;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_print;
}	t_ctx;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	t_ctx		*ctx;
}	t_philo;

//muthread.c
int		create_thread(t_philo **philo, t_ctx *ctx, int nb_philo);
void	destroy_mutex(t_ctx *ctx, int mutex_to_destroy);
void	wait_thread(t_philo *philo, int nb_philo);
int		create_mutex(t_ctx *ctx, int nb_philo);

//philo_life.c
void	*routine(void *data);

//utils.c
size_t	ft_strlen(char *s);
void	print_error(char *msg);
t_rules	init_rules(char **argv);

//print.c
void	print_eat(t_philo *philo);
void	print_fork(t_philo *philo);
void	print_sleep(t_philo *philo);
void	print_think(t_philo *philo);
void	print_death(t_philo *philo);

#endif