/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:49:13 by ldepenne          #+#    #+#             */
/*   Updated: 2026/03/13 18:00:15 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_ctx		*ctx;

	ctx = (t_ctx *)arg;
	ctx->philo->thread = pthread_self();
	pthread_mutex_lock(&ctx->m_print);
	printf("i:%s%d%s thread: %s%ld%s\n", GREEN, ctx->philo->n_philo, NC, CYAN, ctx->philo->thread, NC);
	pthread_mutex_unlock(&ctx->m_print);
	return (0);
}

// int	philo_life(t_ctx *ctx, size_t n_philo)
// {
// 	if (pthread_create((ctx->philo + n_philo)->thread, NULL, routine, ctx) != 0)
// 		return (1);
// 	pthread_mutex_lock(&ctx->mutex.mutest);
// 	ctx->philo.t_id = pthread_self();
// 	pthread_mutex_unlock(&ctx->mutex.mutest);
// 	return (ctx->philo.t_id);
// }
