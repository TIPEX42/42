/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:41:17 by njennes           #+#    #+#             */
/*   Updated: 2021/08/25 13:28:42 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_get_line_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	ft_check_infos(int *infos)
{
	if (infos[MAP_WIDTH] < 1 || infos[MAP_HEIGHT] < 1)
		return (0);
	if (infos[OBSTACLE_CHAR] == infos[EMPTY_CHAR])
		return (0);
	if (infos[EMPTY_CHAR] == infos[FULL_CHAR])
		return (0);
	if (infos[FULL_CHAR] == infos[OBSTACLE_CHAR])
		return (0);
	if (infos[OBSTACLE_CHAR] < 33 || infos[OBSTACLE_CHAR] > 126)
		return (0);
	if (infos[EMPTY_CHAR] < 33 || infos[EMPTY_CHAR] > 126)
		return (0);
	if (infos[FULL_CHAR] < 33 || infos[FULL_CHAR] > 126)
		return (0);
	return (1);
}

char	**ft_allocate_map(int width, int height)
{
	int		i;
	char	**map;

	map = malloc((height + 1) * sizeof(char *));
	if (!map)
		return (0);
	i = 0;
	while (i < height)
	{
		map[i] = malloc((width + 1) * sizeof(char));
		if (!map[i])
			return (0);
		i++;
	}
	map[i] = malloc(1 * sizeof(char));
	if (!map[i])
		return (0);
	map[i] = 0;
	return (map);
}

char	**ft_create_map(int height, char *str)
{
	int		i;
	int		j;
	int		line_length;
	char	**map;

	while (*str != '\n')
		str++;
	str++;
	line_length = ft_get_line_length(str);
	map = ft_allocate_map(height, line_length);
	if (!map)
		return (0);
	i = 0;
	j = 0;
	while (*str != 0)
	{
		map[i][j] = *str;
		str++;
		j++;
		if (*str == '\n')
		{
			map[i][j] = 0;
			str++;
			j = 0;
			i++;
		}
	}
	return (map);
}

void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}
