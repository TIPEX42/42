/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/05/06 16:26:29 by njennes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mutex	*init_forks(size_t n)
{
	size_t	i;
	t_mutex	*forks;

	forks = ft_calloc(n, sizeof (t_mutex));
	if (!forks)
		return (NULL);
	i = 0;
	while (i < n)
	{
		init_mutex(&forks[i]);
		i++;
	}
	return (forks);
}

void	destroy_forks(t_mutex *forks, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&forks[i].m);
		i++;
	}
	free(forks);
}

t_philo	*init_philos(size_t n, char **argv, int args, t_data *data)
{
	size_t			i;
	t_philo			*philos;
	t_mutex			*forks;
	struct timeval	time;

	forks = init_forks(n);
	if (!forks)
		return (NULL);
	philos = ft_calloc(n, sizeof(t_philo));
	if (philos == NULL)
	{
		destroy_forks(forks, n);
		return (NULL);
	}
	i = 0;
	gettimeofday(&time, NULL);
	while (i < n)
	{
		philos[i].tmax_since_eat = ft_atoi(argv[2]) * 1000;
		philos[i].tt_eat = ft_atoi(argv[3]) * 1000;
		philos[i].tt_sleep = ft_atoi(argv[4]) * 1000;
		init_mutex(&philos[i].eat_mutex);
		philos[i].lfork = &forks[i];
		philos[i].data = data;
		if (args == 6)
			philos[i].max_eats = ft_atoi(argv[5]);
		else
			philos[i].max_eats = -1;
		if (i > 0)
			philos[i - 1].rfork = &forks[i];
		if (i == n - 1 && i != 0)
			philos[i].rfork = &forks[0];
		i++;
	}
	i = 0;
	while (i < n)
	{
		philos[i].id = i + 1;
		gettimeofday(&philos[i].ts_eat, NULL);
		pthread_create(&philos[i].thread, NULL, philo_live, &philos[i]);
		i++;
	}
	return (philos);
}

int	check_args(size_t argc, char **argv)
{
	size_t	i;
	size_t	j;

	if (argc < 5 || argc > 6)
		return (0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	init_mutex(t_mutex *mutex)
{
	mutex->init = 1;
	pthread_mutex_init(&mutex->m, NULL);
}
