/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:33:16 by njennes           #+#    #+#             */
/*   Updated: 2022/05/07 13:56:03 by njennes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_philo_done(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->running_mutex.m);
	philo->data->running--;
	pthread_mutex_unlock(&philo->data->running_mutex.m);
	pthread_mutex_lock(&philo->done_mutex.m);
	philo->done = 1;
	pthread_mutex_unlock(&philo->done_mutex.m);
	return (0);
}

int	is_philo_done(t_philo *philo)
{
	int	done;

	pthread_mutex_lock(&philo->done_mutex.m);
	done = philo->done;
	pthread_mutex_unlock(&philo->done_mutex.m);
	return (done);
}

int	get_philo_alive(t_data *data)
{
	int	running;

	pthread_mutex_lock(&data->running_mutex.m);
	running = data->running;
	pthread_mutex_unlock(&data->running_mutex.m);
	return (running);
}

void	destroy_data(t_data *data)
{
	pthread_mutex_destroy(&data->running_mutex.m);
	pthread_mutex_destroy(&data->ds_mutex.m);
}
