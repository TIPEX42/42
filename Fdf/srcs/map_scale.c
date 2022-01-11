/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:54:44 by                   #+#    #+#             */
/*   Updated: 2022/01/09 15:08:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	pixels_outside_canvas(t_canvas *canvas, t_map *map, t_map_info *infos)
{
	t_vec4	**proj;
	int		i;
	int		j;

	proj = map->projection;
	i = 0;
	while (i < infos->size_z)
	{
		j = 0;
		while (j < infos->size_x)
		{
			if (proj[i][j].x >= canvas->width - 50 || proj[i][j].x < 50 ||
				proj[i][j].y >= canvas->height - 50 || proj[i][j].y < 50)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	scale_map(t_canvas *canvas, t_map *map)
{
	t_vec3	increment;
	t_vec3	decrement;

	increment = (t_vec3){1.0f, 0.1f, 1.0f};
	decrement = (t_vec3){-1.0f, -0.1f, -1.0f};
	update_projections(map, &map->infos);
	while (!pixels_outside_canvas(canvas, map, &map->infos))
	{
		vec3_add(&map->scale, increment);
		update_projections(map, &map->infos);
	}
	while (pixels_outside_canvas(canvas, map, &map->infos))
	{
		vec3_add(&map->scale, decrement);
		update_projections(map, &map->infos);
	}
	map->has_scaled = 1;
}
