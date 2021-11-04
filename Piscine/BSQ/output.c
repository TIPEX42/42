/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:16:44 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/25 13:25:26 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_set_output(int *center_coords, int size, char **map, int *info)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = center_coords[0] - (size / 2);
	y = center_coords[1] - (size / 2);
	i = 0;
	while (i < x + size)
	{
		j = 0;
		while (j < y + size)
		{
			map[x][y] = info[FULL_CHAR];
			j++;
		}
		i++;
	}
}

void	ft_print_output(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			putchar(map[i][j]);
			j++;
		}
		i++;
	}
}
