/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_generatoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:25:39 by njennes           #+#    #+#             */
/*   Updated: 2021/08/25 13:10:22 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_dist(int x1, int y1, int x2, int y2)
{
	return (ft_max(ft_abs(x1 - x2), ft_abs(y1 - y2)));
}

int	**ft_allocate_heatmap(int width, int height)
{
	int	i;
	int	**heatmap;

	heatmap = malloc(height * sizeof(int *));
	if (!heatmap)
		return (0);
	i = 0;
	while (i < height)
	{
		heatmap[i] = malloc(width * sizeof(int));
		if (!heatmap[i])
			return (0);
		i++;
	}
	return (heatmap);
}

int	ft_get_heat(int x, int y, int **obstacles, int *infos)
{
	int	min;
	int	i;

	min = 2147483647;
	if (infos[MAP_WIDTH] - x < min)
		min = infos[MAP_WIDTH] - x;
	if (x + 1 < min)
		min = x + 1;
	if (infos[MAP_HEIGHT] - y < min)
		min = infos[MAP_HEIGHT] - y;
	if (y + 1 < min)
		min = y + 1;
	i = 0;
	while (i < obstacles[0][0])
	{
		if (ft_dist(x, y, ft_list_get(obstacles,i, 1), ft_list_get(obstacles, i, 0)) < min)
			min = ft_dist(x, y, ft_list_get(obstacles, i, 1), ft_list_get(obstacles, i, 0));
		i++;
	}
	return (min);
}

int	ft_dist_to_wall(int x, int y, int width, int height)
{
	int	min;

	min = 2147483647;
	if (width - x < min)
		min = width - x;
	if (x + 1 < min)
		min = x + 1;
	if (height - y < min)
		min = height - y;
	if (y + 1 < min)
		min = y + 1;
	return (min);
}

int	ft_generate_heatmap(int **obstacles, int *infos, int **list)
{
	int	coords[4];
	
	coords[I] = infos[MAP_HEIGHT] / 2;
	coords[J] = infos[MAP_WIDTH] / 2;
	coords[FACTOR] = 1;
	coords[MAX] = 0;
	while (coords[I] > 0 && coords[J] > 0 && coords[MAX] <= ft_dist_to_wall(coords[I], coords[J], infos[MAP_WIDTH], infos[MAP_HEIGHT]) / 2)
	{
		ft_go_up(coords, obstacles, infos, list);
		ft_go_right(coords, obstacles, infos, list);
		coords[FACTOR]++;
		ft_go_down(coords, obstacles, infos, list);
		ft_go_left(coords, obstacles, infos, list);
		coords[FACTOR]++;
	}
	return (coords[MAX]);
}
