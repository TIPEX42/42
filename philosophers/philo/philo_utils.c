/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:02:52 by njennes           #+#    #+#             */
/*   Updated: 2022/05/06 18:47:38 by njennes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_lfork(t_philo *philo)
{
	pthread_mutex_lock(&philo->lfork->m);
	philo_print(philo, "has taken a fork");
	philo->has_lfork = 1;
}

void	lock_rfork(t_philo *philo)
{
	pthread_mutex_lock(&philo->rfork->m);
	philo_print(philo, "has taken a fork");
	philo->has_rfork = 1;
}

void	unlock_forks(t_philo *philo)
{
	if (philo->has_lfork)
		pthread_mutex_unlock(&philo->lfork->m);
	if (philo->rfork && philo->has_lfork)
		pthread_mutex_unlock(&philo->rfork->m);
}

int	philo_print(t_philo *philo, const char *msg)
{
	struct timeval	time;

	if (get_death_switch(philo->data))
		return (0);
	gettimeofday(&time, NULL);
	printf("%lld %d %s\n",
		time_diff(philo->data->start_ts, time) / 1000, philo->id, msg);
	return (1);
}