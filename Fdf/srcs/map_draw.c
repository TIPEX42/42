/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:54:44 by                   #+#    #+#             */
/*   Updated: 2022/01/09 15:08:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	update_projections(t_map *map, t_map_info *infos)
{
	t_mat4	model;
	int		i;
	int		j;

	model = mat4_translate(mat4_identity(), map->pos);
	model = mat4_multm4(model, mat4_rotate(map->rotation));
	model = mat4_multm4(model, mat4_scalev3(map->scale));
	i = 0;
	while (i < infos->size_z)
	{
		j = 0;
		while (j < infos->size_x)
		{
			map->projection[i][j] = mat4_multv4(model, map->verticies[i][j]);
			j++;
		}
		i++;
	}
}

void draw_wf_x(t_canvas *canvas, t_map_info *infos, t_vec4 **proj, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < infos->size_z)
	{
		j = 0;
		while (j < infos->size_x - 1)
		{
			draw_line(canvas, (t_vec2){proj[i][j].x, proj[i][j].y},
					  (t_vec2){proj[i][j + 1].x, proj[i][j + 1].y},
					  color);
			j++;
		}
		i++;
	}
}

void draw_wf_y(t_canvas *canvas, t_map_info *infos, t_vec4 **proj, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < infos->size_z - 1)
	{
		j = 0;
		while (j < infos->size_x)
		{
			draw_line(canvas, (t_vec2){proj[i][j].x, proj[i][j].y},
					  (t_vec2){proj[i + 1][j].x, proj[i + 1][j].y},
					  color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_canvas *canvas, t_map *map, int color)
{
	update_projections(map, &map->infos);
	draw_wf_x(canvas, &map->infos, map->projection, color);
	draw_wf_y(canvas, &map->infos, map->projection, color);
}

void	clear_map(t_canvas *canvas, t_map *map, int color)
{
	draw_wf_x(canvas, &map->infos, map->projection, color);
	draw_wf_y(canvas, &map->infos, map->projection, color);
}
