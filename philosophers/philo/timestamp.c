/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/01/06 18:08:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_timestamp(t_timestamp *timestamp)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	timestamp->usecs = time.tv_usec;
	timestamp->secs = time.tv_sec;
}

int	time_elapsed_since(t_timestamp ts, uint64_t time)
{
	struct timeval	current_time;
	uint64_t		elapsedms;

	gettimeofday(&current_time, NULL);
	elapsedms = (current_time.tv_sec - ts.secs) * 1000;
	if ((int64_t)current_time.tv_usec - (int64_t)ts.usecs < 0)
	{
		elapsedms -= 1000;
		elapsedms += (current_time.tv_usec + 1000000 - ts.usecs) / 1000;
	}
	else
		elapsedms += (current_time.tv_usec - ts.usecs) / 1000;
	if (elapsedms > time / 1000)
		return (1);
	return (0);
}
