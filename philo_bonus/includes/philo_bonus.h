/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:46:27 by ldepenne          #+#    #+#             */
/*   Updated: 2026/04/07 16:55:06 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

//colors
# define DEATH_COLOR "\e[40;1;31m"
# define HIGH_BLUE "\e[94m"
# define CYAN "\e[96m"
# define BLUE "\e[34m"
# define NC "\e[0m"

# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <semaphore.h>

# define INT_MAX 2147483647
# define NB_SEM 5

typedef enum e_sem
{
	parent,
	DEATH,
	MEAL,
	PRINT,
	FORK
}	t_sem;

typedef struct s_rules
{
	int	flag_meal;
	int	nb_of_meal;
	int	nb_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_rules;

typedef struct s_ctx
{
	sem_t		*sem[NB_SEM];
	int			id;
	pid_t		pid;
	int			status;
	size_t		time_start;
	size_t		last_timeal;
	size_t		watch;
	int			n_meal;
	int			death_flag;
	pthread_t	thread_spy;
	pthread_t	thread_me;
	t_rules		rules;
}	t_ctx;

//parcing_b.c
int		ft_atoi(const char *nptr);
int		parcing(char **argv);

//utils.c
size_t	ft_strlen(char *s);
void	print_error(char *msg);
t_rules	init_rules(char **argv);
void	finish_process(t_ctx *ctx);

//semaphores.c
int		open_sem(t_ctx *ctx);
void	unlink_all_sem(void);
void	close_sem(t_ctx *ctx);

//routine_bonus.c
void	routine(t_ctx *ctx);

//child_management.c
int		child_management(t_ctx *ctx);

//time.c
size_t	the_time(t_ctx *ctx);
size_t	get_current_time(void);
void	ft_usleep(size_t time);

//thread_bonus.c
void	create_threads(t_ctx *ctx);

//print_bonus.c
void	print_eat(t_ctx *ctx);
void	print_fork(t_ctx *ctx);
void	print_sleep(t_ctx *ctx);
void	print_think(t_ctx *ctx);
void	print_death(t_ctx *ctx);

#endif