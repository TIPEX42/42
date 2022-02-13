/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/01/06 18:08:08 by                  ###   ########.fr       */
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
		forks[i].init = 1;
		pthread_mutex_init(&forks[i].m, NULL);
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

t_philo	*init_philos(size_t n, char **argv)
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
		set_timestamp(&philos[i].ts_eat);
		set_timestamp(&philos[i].ts_sleep);
		philos[i].lfork = &forks[i];
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
		pthread_create(&philos[i].thread, NULL, philo_live, &philos[i]);
		i++;
	}
	return (philos);
}

void	simulate(t_philo *philos, size_t n)
{
	size_t			i;
	size_t			alive;
	struct timeval	time;

	alive = n;
	while (alive)
	{
		i = 0;
		while (i < n)
		{
			if (time_elapsed_since(philos[i].ts_sleep, philos[i].tmax_since_eat) &&
				!philos[i].is_dead)
			{
				gettimeofday(&time, NULL);
				philos[i].is_dead = 1;
				ft_printf("%u %d died\n", (unsigned int)(time.tv_sec * 1000 + time.tv_usec / 1000), philos[i].id);
				alive--;
			}
			i++;
		}
	}
	i = 0;
	while (i < n)
	{
		pthread_join(philos[i].thread, NULL);
		pthread_detach(philos[i].thread);
		pthread_mutex_destroy(&philos[i].lfork->m);
		i++;
	}
	destroy_forks(philos->lfork, n);
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
