/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/01/06 18:08:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_try_start_eating(t_philo *philo)
{
	struct timeval time;

	pthread_mutex_lock(&philo->lfork->m);
	gettimeofday(&time, NULL);
	printf("%ld %d has taken a fork\n", time.tv_sec * 1000 + time.tv_usec / 1000, philo->id);
	if (!philo->rfork)
	{
		pthread_mutex_unlock(&philo->lfork->m);
		pthread_exit(EXIT_SUCCESS);
	}
	pthread_mutex_lock(&philo->rfork->m);
	gettimeofday(&time, NULL);
	printf("%ld %d has taken a fork\n", time.tv_sec * 1000 + time.tv_usec / 1000, philo->id);
	printf("%ld %d is eating\n", time.tv_sec * 1000 + time.tv_usec / 1000, philo->id);
	set_timestamp(&philo->ts_eat);
	philo_sleep(philo, philo->tt_eat);
	pthread_mutex_unlock(&philo->rfork->m);
	pthread_mutex_unlock(&philo->lfork->m);
	philo->eats++;
	if (philo->eats == philo->max_eats)
	{
		philo->done = 1;
		pthread_exit(EXIT_SUCCESS);
	}
}

void	philo_try_start_sleeping(t_philo *philo)
{
	struct timeval	time;

	set_timestamp(&philo->ts_sleep);
	gettimeofday(&time, NULL);
	printf("%ld %d is sleeping\n", time.tv_sec * 1000 + time.tv_usec / 1000, philo->id);
	philo_sleep(philo, philo->tt_sleep);
}

void	philo_try_start_thinking(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("%ld %d is thinking\n", time.tv_sec * 1000 + time.tv_usec / 1000, philo->id);
}

void	*philo_live(void *ptr)
{
	t_philo			*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
	{
		philo_sleep(philo, 10000);
		philo_try_start_eating(philo);
	}
	while (!philo->is_dead)
	{
		philo_try_start_eating(philo);
		if (philo->is_dead)
			pthread_exit(EXIT_SUCCESS);
		philo_try_start_sleeping(philo);
		if (philo->is_dead)
			pthread_exit(EXIT_SUCCESS);
		philo_try_start_thinking(philo);
	}
	pthread_exit(EXIT_SUCCESS);
}
