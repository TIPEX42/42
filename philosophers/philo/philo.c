/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/05/06 19:30:23 by njennes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_try_start_eating(t_philo *philo)
{
	int	sleep_ret;

	lock_lfork(philo);
	if (!philo->rfork)
	{
		pthread_mutex_unlock(&philo->lfork->m);
		pthread_exit(EXIT_SUCCESS);
	}
	lock_rfork(philo);
	if (!philo_print(philo, "is eating"))
	{
		unlock_forks(philo);
		return (0);
	}
	lock_philo_eat(philo);
	gettimeofday(&philo->ts_eat, NULL);
	unlock_philo_eat(philo);
	sleep_ret = my_eat(philo, philo->tt_eat);
	unlock_forks(philo);
	if (!sleep_ret)
		return (0);
	philo->eats++;
	if (philo->eats == philo->max_eats)
	{
		set_philo_done(philo);
		return (0);
	}
	return (1);
}

int	philo_try_start_sleeping(t_philo *philo)
{
	if (!philo_print(philo, "is sleeping"))
		return (0);
	return (my_sleep(philo, philo->tt_sleep));
}

int	philo_try_start_thinking(t_philo *philo)
{
	return (philo_print(philo, "is thinking"));
}

void	*philo_live(void *ptr)
{
	t_philo			*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		my_sleep(philo, 3000);
	while (!is_philo_done(philo))
	{
		if (!philo_try_start_eating(philo))
			return (NULL);
		if (!philo_try_start_sleeping(philo))
			return (NULL);
		if (!philo_try_start_thinking(philo))
			return (NULL);
	}
	return (NULL);
}
