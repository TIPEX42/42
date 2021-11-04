/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:28:56 by njennes           #+#    #+#             */
/*   Updated: 2021/08/16 11:29:19 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str);

int	ft_atoi(char *str)
{
	int	nb;
	int	moins;

	nb = 0;
	moins = 1;
	while (*str != '+' && *str != '-' && *str < 33)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			moins *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + ((int)*str - '0');
		str++;
	}
	return (nb * moins);
}
