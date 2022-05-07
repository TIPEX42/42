/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/05/07 13:52:55 by njennes          ###   ########.fr       */
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

	if (!init_forks_philos(&forks, &philos, n))
		return (NULL);
	i = 0;
	gettimeofday(&time, NULL);
	while (i < n)
	{
		init_philo(&philos[i], args, argv, data);
		init_philo_2(philos, i, n, forks);
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
