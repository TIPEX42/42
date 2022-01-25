/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:54:44 by                   #+#    #+#             */
/*   Updated: 2022/01/22 15:55:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	pixels_outside_canvas(t_canvas *canvas, t_map *map, t_map_info *infos)
{
	t_vertex	**proj;
	int			i;
	int			j;

	proj = map->projection;
	i = 0;
	while (i < infos->size_z)
	{
		j = 0;
		while (j < infos->size_x)
		{
			if (proj[i][j].pos.x >= canvas->width - 10 ||
				proj[i][j].pos.x < 10 ||
				proj[i][j].pos.y >= canvas->height - 10 ||
				proj[i][j].pos.y < 10)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	scale_map(t_canvas *canvas, t_map *map)
{
	update_projections(map, &map->infos);
	while (!pixels_outside_canvas(canvas, map, &map->infos))
	{
		vec3_multf(&map->scale, 2.0f);
		update_projections(map, &map->infos);
	}
	while (pixels_outside_canvas(canvas, map, &map->infos))
	{
		vec3_multf(&map->scale, 0.9f);
		update_projections(map, &map->infos);
	}
	map->has_scaled = 1;
}
