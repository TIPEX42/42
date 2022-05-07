/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/05/07 13:58:26 by njennes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	close_philos_forks(t_data *data, t_philo *philos, size_t n);

void	simulate(t_data *data, t_philo *philos, size_t n)
{
	size_t			i;
	struct timeval	time;

	while (!get_death_switch(data) && get_philo_alive(data) > 0)
	{
		i = 0;
		gettimeofday(&time, NULL);
		lock_philo_eat(&philos[i]);
		if (time_diff(philos[i].ts_eat, time) > philos[i].tmax_since_eat
			&& !is_philo_done(&philos[i]))
		{
			unlock_philo_eat(&philos[i]);
			set_death_switch(philos[i].data, 1);
			printf("%lld %d died\n",
				time_diff(philos[i].data->start_ts, time) / 1000,
				philos[i].id);
			break ;
		}
		else
			unlock_philo_eat(&philos[i]);
		i++;
		if (i == n)
			i = 0;
	}
	close_philos_forks(data, philos, n);
}

void	close_philos_forks(t_data *data, t_philo *philos, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		pthread_join(philos[i].thread, NULL);
		pthread_detach(philos[i].thread);
		pthread_mutex_destroy(&philos[i].lfork->m);
		pthread_mutex_destroy(&philos[i].eat_mutex.m);
		i++;
	}
	destroy_forks(philos->lfork, n);
	destroy_data(data);
}

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_data	data;

	if (!check_args(argc, argv))
	{
		printf("Invalid arguments\n");
		return (1);
	}
	if (ft_atoi(argv[1]) == 0)
		return (0);
	init_data(&data, ft_atoi(argv[1]));
	philos = init_philos(ft_atoi(argv[1]), argv, argc, &data);
	if (philos == NULL)
		return (1);
	simulate(&data, philos, ft_atoi(argv[1]));
	free(philos);
	return (0);
}

void	set_death_switch(t_data *data, int status)
{
	pthread_mutex_lock(&data->ds_mutex.m);
	data->death_switch = status;
	pthread_mutex_unlock(&data->ds_mutex.m);
}

int	get_death_switch(t_data *data)
{
	int	status;

	pthread_mutex_lock(&data->ds_mutex.m);
	status = data->death_switch;
	pthread_mutex_unlock(&data->ds_mutex.m);
	return (status);
}
