/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:26:50 by                   #+#    #+#             */
/*   Updated: 2022/01/22 14:36:19 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

t_vertex	**generate_verticies(t_gc *gc, t_map_info *infos)
{
	t_vertex	**tab;
	int		i;
	int		j;

	tab = gc_calloc(gc, infos->size_z, sizeof(t_vertex));
	i = 0;
	while (i < infos->size_z)
	{
		tab[i] = gc_calloc(gc, infos->size_x, sizeof(t_vertex));
		j = 0;
		while (j < infos->size_x)
		{
			tab[i][j].pos = vec4(j - infos->size_x / 2, infos->heights[i][j], \
							infos->size_z / 2 - i, 1);
			tab[i][j].col = infos->colors[i][j];
			j++;
		}
		i++;
	}
	return (tab);
}

t_vertex	**init_projections(t_gc *gc, t_map_info *infos)
{
	t_vertex	**tab;
	int		i;

	tab = gc_calloc(gc, infos->size_z, sizeof(t_vertex));
	i = 0;
	while (i < infos->size_z)
	{
		tab[i] = gc_calloc(gc, infos->size_x, sizeof(t_vertex));
		i++;
	}
	return (tab);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	create_map(t_gc *gc, t_map *map, char *file)
{
	t_vec3	base_color;
	t_vec3	high_color;

	base_color = vec3(200, 200, 200);
	high_color = vec3(255, 100, 100);
	load_map(gc, &map->infos, file);
	map->pos = vec3_zero();
	map->rotation = vec3(0, PI / 4, PI / 6);
	map->scale = vec3(1, 1, 1);
	map->has_scaled = 0;
	map->verticies = generate_verticies(gc, &map->infos);
	map->projection = init_projections(gc, &map->infos);
}
