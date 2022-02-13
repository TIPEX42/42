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
	uint64_t	t;

	t = 0;
	while (t < time)
	{
		usleep(1000);
		if (philo->is_dead)
			return ;
		t += 1000;
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philos;

	if (!check_args(argc, argv))
	{
		ft_printf("Invalid arguments\n");
		return (1);
	}
	if (ft_atoi(argv[1]) == 0)
		return (0);
	philos = init_philos(ft_atoi(argv[1]), argv);
	if (philos == NULL)
		return (1);
	simulate(philos, ft_atoi(argv[1]));
	free(philos);
	return (0);
}
