/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/05/06 19:02:28 by njennes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int64_t	time_diff(struct timeval start, struct timeval end)
{
	int64_t	ut1;
	int64_t	ut2;

	ut1 = start.tv_sec * 1000000 + start.tv_usec;
	ut2 = end.tv_sec * 1000000 + end.tv_usec;
	return (ut2 - ut1);
}

int	my_eat(t_philo *philo, int64_t time)
{
	struct timeval	start;
	struct timeval	current;
	int64_t			elapsed;

	gettimeofday(&start, NULL);
	gettimeofday(&current, NULL);
	elapsed = time_diff(start, current);
	while (elapsed < time)
	{
		if (get_death_switch(philo->data))
		{
			unlock_forks(philo);
			return (0);
		}
		usleep(200);
		gettimeofday(&current, NULL);
		elapsed = time_diff(start, current);
		if (elapsed >= time - 100 && time - elapsed > 0)
		{
			usleep(time - elapsed);
			return (1);
		}
	}
	return (1);
}

int	my_sleep(t_philo *philo, int64_t time)
{
	struct timeval	start;
	struct timeval	current;
	int64_t			elapsed;

	gettimeofday(&start, NULL);
	gettimeofday(&current, NULL);
	elapsed = time_diff(start, current);
	while (elapsed < time)
	{
		if (get_death_switch(philo->data))
			return (0);
		usleep(100);
		gettimeofday(&current, NULL);
		elapsed = time_diff(start, current);
		if (elapsed >= time - 100 && time - elapsed > 0)
		{
			usleep(time - elapsed);
			return (1);
		}
	}
	return (1);
}
