/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle_finder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:07:43 by bjeannot          #+#    #+#             */
/*   Updated: 2021/08/25 13:18:20 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*ft_map_error(void)
{
	write(1, "Map Error\n", 10);
	return (0);
}

void	ft_add_to_buffer(int *buffer, int x, int y, int **list)
{
	buffer[0] = x;
	buffer[1] = y;
	list = ft_list_push(list, buffer);
}

int	ft_is_valid_char(char to_check, int *infos)
{
	if (to_check == infos[OBSTACLE_CHAR] \
		|| to_check == infos[FULL_CHAR] \
		|| to_check == infos[EMPTY_CHAR])
		return (1);
	return ((int)ft_map_error());
}

//searchs for 'obstacle_char' in 'parsed_file' & returns a 2D array with coords
int	**ft_get_obstacle(char **parsed_file, int *infos)
{
	int	**res;
	int	j;
	int	i;
	int	buffer[2];

	res = ft_list_create(0, 2);
	i = 0;
	while (parsed_file[i])
	{
		j = 0;
		while (parsed_file[i][j])
		{
			if (ft_is_valid_char(parsed_file[i][j], infos))
			{
				if (parsed_file[i][j] == infos[OBSTACLE_CHAR])
				{
					buffer[0] = i;
					buffer[1] = j;
					ft_add_to_buffer(buffer, i, j, res);
				}
			}
			else
				return (0);
			j++;
		}
		if (j != infos[MAP_WIDTH])
			return ((int **)ft_map_error());
		i++;
	}
	return (res);
}
