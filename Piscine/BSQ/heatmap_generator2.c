/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap_generator2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:13:04 by njennes           #+#    #+#             */
/*   Updated: 2021/08/25 11:13:12 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_go_up(int *coords, int **obstacles, int *infos, int **list)
{
	int	i;
	int	heat;

	i = 0;
	while (i < coords[FACTOR])
		{
			heat = ft_get_heat(coords[J], coords[I], obstacles, infos);
			if (heat > coords[MAX])
			{
				coords[MAX] = heat;
				ft_list_free(list);
				list = ft_list_create(0, 2);
				list = ft_list_push(list, coords);
			}
			else if (heat == coords[MAX])
				list = ft_list_push(list, coords);
			coords[I]--;
			i++;
		}
}

void	ft_go_down(int *coords, int **obstacles, int *infos, int **list)
{
	int	i;
	int	heat;

	i = 0;
	while (i < coords[FACTOR])
		{
			heat = ft_get_heat(coords[J], coords[I], obstacles, infos);
			if (heat > coords[MAX])
			{
				coords[MAX] = heat;
				ft_list_free(list);
				list = ft_list_create(0, 2);
				list = ft_list_push(list, coords);
			}
			else if (heat == coords[MAX])
				list = ft_list_push(list, coords);
			coords[I]++;
			i++;
		}
}

void	ft_go_left(int *coords, int **obstacles, int *infos, int **list)
{
	int	i;
	int	heat;

	i = 0;
	while (i < coords[FACTOR])
		{
			heat = ft_get_heat(coords[J], coords[I], obstacles, infos);
			if (heat > coords[MAX])
			{
				coords[MAX] = heat;
				ft_list_free(list);
				list = ft_list_create(0, 2);
				list = ft_list_push(list, coords);
			}
			else if (heat == coords[MAX])
				list = ft_list_push(list, coords);
			coords[J]--;
			i++;
		}
}

void	ft_go_right(int *coords, int **obstacles, int *infos, int **list)
{
	int	i;
	int	heat;

	i = 0;
	while (i < coords[FACTOR])
	{
		heat = ft_get_heat(coords[J], coords[I], obstacles, infos);
		if (heat > coords[MAX])
		{
			coords[MAX] = heat;
			ft_list_free(list);
			list = ft_list_create(0, 2);
			list = ft_list_push(list, coords);
		}
		else if (heat == coords[MAX])
			list = ft_list_push(list, coords);
		coords[J]++;
		i++;
	}
}
