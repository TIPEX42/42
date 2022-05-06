/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:02:28 by njennes           #+#    #+#             */
/*   Updated: 2022/05/06 19:32:53 by njennes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lock_philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex.m);
}

void	unlock_philo_eat(t_philo *philo)
{
	pthread_mutex_unlock(&philo->eat_mutex.m);
}
