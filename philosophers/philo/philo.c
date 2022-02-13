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
	struct timeval new_time;

	gettimeofday(&time, NULL);
	if (!philo->lfork)
		pthread_exit(EXIT_SUCCESS);
	pthread_mutex_lock(&philo->lfork->m);
	gettimeofday(&time, NULL);
	ft_printf("%u %u has taken a fork\n", time.tv_sec * 1000 + time.tv_usec / 1000, philo->id);
	if (!philo->rfork)
		pthread_exit(EXIT_SUCCESS);
	pthread_mutex_lock(&philo->rfork->m);
	gettimeofday(&time, NULL);
	ft_printf("%u %u has taken a fork\n", time.tv_sec * 1000 + time.tv_usec / 1000, philo->id);
	ft_printf("%u %u is eating\n", time.tv_sec * 1000 + time.tv_usec / 1000, philo->id);
	set_timestamp(&philo->ts_eat);
	philo->state  = EATING;
	gettimeofday(&new_time, NULL);
	philo_sleep(philo, philo->tt_eat);
	pthread_mutex_unlock(&philo->rfork->m);
	pthread_mutex_unlock(&philo->lfork->m);
}

void	philo_try_start_sleeping(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	set_timestamp(&philo->ts_sleep);
	philo->state = SLEEPING;
	ft_printf("%u %u is sleeping\n", time.tv_sec * 1000 + time.tv_usec / 1000, philo->id);
	philo_sleep(philo, philo->tt_sleep);
}

void	philo_try_start_thinking(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	philo->state = THINKING;
	ft_printf("%u %u is thinking\n", time.tv_sec * 1000 + time.tv_usec / 1000, philo->id);
}

void	*philo_live(void *ptr)
{
	t_philo			*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0 && philo->state == IDLE)
		philo_try_start_eating(philo);
	else if (philo->id % 2 == 1 && philo->state == IDLE)
		philo_try_start_sleeping(philo);
	while (!philo->is_dead)
	{
		if (philo->state == THINKING)
			philo_try_start_eating(philo);
		else if (philo->state == EATING)
			philo_try_start_sleeping(philo);
		else
			philo_try_start_thinking(philo);
	}
	pthread_exit(EXIT_SUCCESS);
}
