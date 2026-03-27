/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_b.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 15:46:27 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/27 15:57:30 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_B_H
# define PHILO_B_H

# define INT_MAX 2147483647

//colors
# define DEATH_COLOR "\e[40;1;31m"
# define HIGH_BLUE "\e[94m"
# define PURPLE "\e[95m"
# define CYAN "\e[96m"
# define BLUE "\e[34m"
# define NC "\e[0m"

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
	// int				meals;
	size_t			time_start;
	t_rules			rules;
}	t_ctx;

typedef struct s_philo
{
	pthread_t	thread;
	size_t		watch;
	int			id;
	int			n_meal;
	size_t		last_timeal;
	t_ctx		*ctx;
}	t_philo;

//parcing.c
int		ft_atoi(const char *nptr);
int		parcing(char **argv);

//philo_life.c
// void	*routine(void *data);

//utils.c
size_t	ft_strlen(char *s);
void	print_error(char *msg);
t_rules	init_rules(char **argv);
// int		all_meal(t_philo *philo);
// int		someone_dead(t_ctx *ctx);

//print.c
// void	print_eat(t_philo *philo);
// void	print_fork(t_philo *philo);
// void	print_sleep(t_philo *philo);
// void	print_think(t_philo *philo);
// void	print_death(t_philo *philo);

//time.c
size_t	get_current_time(void);
// int		is_dead(t_philo *philo);
// void	the_time(t_philo *philo);
void	ft_usleep(size_t time, t_ctx *ctx);

//eat.c
// void	philo_odd_eat(t_philo *philo);
// void	philo_even_eat(t_philo *philo);
// void	do_we_live_to_eat_or_do_we_eat_to_live(t_philo *philo);

#endif