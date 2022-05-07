/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:40:35 by njennes           #+#    #+#             */
/*   Updated: 2022/05/07 13:56:51 by njennes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_philo *philo, int argc, char **argv, t_data *data)
{
	philo->tmax_since_eat = ft_atoi(argv[2]) * 1000;
	philo->tt_eat = ft_atoi(argv[3]) * 1000;
	philo->tt_sleep = ft_atoi(argv[4]) * 1000;
	philo->data = data;
	init_mutex(&philo->eat_mutex);
	if (argc == 6)
		philo->max_eats = ft_atoi(argv[5]);
	else
		philo->max_eats = -1;
}

void	init_philo_2(t_philo *philos, size_t i, size_t n, t_mutex *forks)
{
	philos[i].lfork = &forks[i];
	if (i > 0)
		philos[i - 1].rfork = &forks[i];
	if (i == n - 1 && i != 0)
		philos[i].rfork = &forks[0];
}

int	init_forks_philos(t_mutex **forks, t_philo **philos, size_t n)
{
	*forks = init_forks(n);
	if (!*forks)
		return (0);
	*philos = ft_calloc(n, sizeof(t_philo));
	if (*philos == NULL)
	{
		destroy_forks(*forks, n);
		return (0);
	}
	return (1);
}

void	init_data(t_data *data, int running)
{
	gettimeofday(&data->start_ts, NULL);
	data->death_switch = 0;
	data->running = running;
	init_mutex(&data->ds_mutex);
	init_mutex(&data->running_mutex);
}
