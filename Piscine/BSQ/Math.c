/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:40:28 by njennes           #+#    #+#             */
/*   Updated: 2021/08/25 13:29:53 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_abs(int x)
{
	if (x >= 0)
		return (x);
	return (-x);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int ft_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - 48;
		str++;
	}
	return (result);
}

int	*ft_get_map_info(char *str)
{
	int	*infos;

	infos = malloc(5 * sizeof(int));
	if (!infos)
		return (0);
	infos[MAP_HEIGHT] = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	infos[EMPTY_CHAR] = str[0];
	infos[OBSTACLE_CHAR] = str[1];
	infos[FULL_CHAR] = str[2];
	while (*str != '\n')
		str++;
	str++;
	infos[MAP_WIDTH] = ft_get_line_length(str);
	if (!ft_check_infos(infos))
		return (ft_map_error());
	return (infos);
}
