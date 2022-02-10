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

void	*philo_live(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;


	pthread_exit(EXIT_SUCCESS);
}

t_philo	*init_philos(size_t n, char **argv, int *cycle)
{
	size_t	i;
	t_philo	*philos;

	philos = ft_calloc(n, sizeof(t_philo));
	if (philos == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		philos[i].tb_eat = ft_atoi(argv[2]);
		philos[i].tt_eat = ft_atoi(argv[3]);
		philos[i].tt_sleep = ft_atoi(argv[4]);
		philos[i].cycle = cycle;
		pthread_mutex_init(&philos[i].lfork.m, NULL);
		if (i != 0 && i != n - 1)
			philos[i - 1].rfork = philos[i].lfork;
		if (i != 0 && i == n - 1)
			philos[i].rfork = philos[0].lfork;
		i++;
	}
	i = 0;
	while (i < n)
	{
		philos[i].id = i;
		pthread_create(&philos[i].thread, NULL, philo_live, &philos[i]);
		i++;
	}
	return (philos);
}

void	simulate(t_philo *philos, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		cycle;
	t_philo	*philos;

	if (argc != 5)
		return (1);
	cycle = 0;
	philos = init_philos(ft_atoi(argv[1]), argv, &cycle);
	if (philos == NULL)
		return (1);
	simulate(philos, ft_atoi(argv[1]));
	ft_printf("End\n");
	return (0);
}
