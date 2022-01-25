/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:54:44 by                   #+#    #+#             */
/*   Updated: 2022/01/25 19:02:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	update_projections(t_map *map, t_map_info *infos)
{
	t_mat4	model;
	t_vec3	cam_pos;
	int		i;
	int		j;

	cam_pos = (t_vec3){WIN_WIDTH / 2, WIN_HEIGHT / 2, 0};
	model = mat4_translate(mat4_identity(), cam_pos);
	model = mat4_multm4(model, mat4_translate(mat4_identity(), map->pos));
	model = mat4_multm4(model, mat4_rotate(map->rotation));
	model = mat4_multm4(model, mat4_scalev3(map->scale));
	i = 0;
	while (i < infos->size_z)
	{
		j = 0;
		while (j < infos->size_x)
		{
			map->projection[i][j].pos = mat4_multv4(model,
					map->verticies[i][j].pos);
			map->projection[i][j].col = map->verticies[i][j].col;
			j++;
		}
		i++;
	}
}

void	draw_wf_x(t_canvas *canvas, t_map_info *infos, t_vertex **proj)
{
	int	i;
	int	j;

	i = 0;
	while (i < infos->size_z)
	{
		j = 0;
		while (j < infos->size_x - 1)
		{
			draw_line(canvas, proj[i][j], proj[i][j + 1]);
			j++;
		}
		i++;
	}
}

void	draw_wf_y(t_canvas *canvas, t_map_info *infos, t_vertex **proj)
{
	int	i;
	int	j;

	i = 0;
	while (i < infos->size_z - 1)
	{
		j = 0;
		while (j < infos->size_x)
		{
			draw_line(canvas, proj[i][j], proj[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	draw_map(t_canvas *canvas, t_map *map)
{
	int	i;

	update_projections(map, &map->infos);
	draw_wf_x(canvas, &map->infos, map->projection);
	draw_wf_y(canvas, &map->infos, map->projection);
	i = 0;
	while (i < canvas->height)
	{
		ft_memsetf(canvas->depth_buffer[i], INT_MIN, canvas->width);
		i++;
	}
}
