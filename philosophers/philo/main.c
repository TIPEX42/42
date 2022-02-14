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

void	philo_sleep(t_philo *philo, uint64_t time)
{
	t_timestamp	ts;

	set_timestamp(&ts);
	while (!time_elapsed_since(ts, time))
	{
		if (philo->is_dead)
			return ;
	}
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
			if (time_elapsed_since(philos[i].ts_eat, philos[i].tmax_since_eat) &&
				!philos[i].is_dead && !philos[i].done)
			{
				gettimeofday(&time, NULL);
				philos[i].is_dead = 1;
				printf("%ld %d died\n", time.tv_sec * 1000 + time.tv_usec / 1000, philos[i].id);
				alive--;
			}
			if (philos[i].done)
				alive--;
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

int	main(int argc, char **argv)
{
	t_philo	*philos;

	if (!check_args(argc, argv))
	{
		printf("Invalid arguments\n");
		return (1);
	}
	if (ft_atoi(argv[1]) == 0)
		return (0);
	philos = init_philos(ft_atoi(argv[1]), argv, argc);
	if (philos == NULL)
		return (1);
	simulate(philos, ft_atoi(argv[1]));
	free(philos);
	return (0);
}
