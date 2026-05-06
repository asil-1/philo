/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:30:36 by ldepenne          #+#    #+#             */
/*   Updated: 2026/05/06 13:54:45 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define INT_MAX 2147483647

//colors
# define DEATH_COLOR "\e[38;5;162m"
# define LIGHT_YELLOW "\e[38;5;230m"
# define YELLOW "\e[38;5;222m"
# define DARK_BLUE "\e[38;5;105m"
# define BLUE "\e[38;5;153m"
# define NO_COLOR "\e[0m"

# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

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
	int				flag_death;
	int				fprint_death;
	int				meals;
	pthread_mutex_t	lock;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_fdead;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_meals;
	size_t			time_start;
	t_rules			rules;
}	t_ctx;

typedef struct s_philo
{
	pthread_t	thread;
	size_t		watch;
	int			id;
	int			n_meal;
	int			first_fork;
	int			second_fork;
	size_t		last_timeal;
	t_ctx		*ctx;
}	t_philo;

//parsing.c
long	ft_atol(const char *nptr);
int		parsing(char **argv);

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
int		all_meal(t_philo *philo);
int		someone_dead(t_ctx *ctx);

//print.c
void	print_eat(t_philo *philo);
void	print_fork(t_philo *philo);
void	print_sleep(t_philo *philo);
void	print_think(t_philo *philo);
void	print_death(t_philo *philo);

//time.c
size_t	get_current_time(void);
int		is_dead(t_philo *philo);
void	the_time(t_philo *philo);
void	ft_usleep(size_t time, t_philo *philo);

//eat.c
void	philo_odd_eat(t_philo *philo);
void	philo_even_eat(t_philo *philo);
void	do_we_live_to_eat_or_do_we_eat_to_live(t_philo *philo);

#endif