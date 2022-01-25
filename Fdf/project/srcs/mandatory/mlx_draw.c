/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/01/25 18:54:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static int	pixel_in_canvas(t_canvas *canvas, int x, int y)
{
	if (x < 0 || x >= canvas->width || y < 0 || y >= canvas->height)
		return (0);
	return (1);
}

void	mlx_set_pixel(t_canvas *canvas, int x, int y, int color)
{
	char		*dst;

	if (!pixel_in_canvas(canvas, x, y))
		return ;
	dst = canvas->addr + (y * canvas->line_length + \
							x * (canvas->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	clear_screen(t_canvas *canvas, int color)
{
	int			i;
	int			total;
	int			bytes_pp;

	i = 0;
	total = canvas->width * canvas->height;
	bytes_pp = canvas->bits_per_pixel / 8;
	while (i < total)
	{
		*((unsigned int *)(canvas->addr + i * bytes_pp)) = color;
		i++;
	}
}

int	color_lerp(int col1, int col2, float value)
{
	t_vec3	new_color;

	new_color.x = get_r(col1) + value * (get_r(col2) - get_r(col1));
	new_color.y = get_g(col1) + value * (get_g(col2) - get_g(col1));
	new_color.z = get_b(col1) + value * (get_b(col2) - get_b(col1));
	return (get_color(0, new_color.x, new_color.y, new_color.z));
}

void	draw_line(t_canvas *canvas, t_vertex start, t_vertex end)
{
	double	pixels_to_draw;
	double	pixels_drawn;
	t_vec3	ppos;
	t_vec3	delta;

	pixels_to_draw = ft_sqrt((ft_pow2(end.pos.x - start.pos.x)) + \
			ft_pow2(end.pos.y - start.pos.y));
	delta.x = (end.pos.x - start.pos.x) / pixels_to_draw;
	delta.y = (end.pos.y - start.pos.y) / pixels_to_draw;
	delta.z = (end.pos.z - start.pos.z) / pixels_to_draw;
	ppos = vec3(start.pos.x, start.pos.y, start.pos.z);
	pixels_drawn = 0;
	while (pixels_drawn < pixels_to_draw)
	{
		vec3_add(&ppos, delta);
		if (pixel_in_canvas(canvas, (int)ppos.x, (int)ppos.y) && \
		ppos.z > canvas->depth_buffer[(int)ppos.y][(int)ppos.x])
		{
			canvas->depth_buffer[(int)ppos.y][(int)ppos.x] = ppos.z;
			mlx_set_pixel(canvas, ppos.x, ppos.y,
				color_lerp(start.col, end.col, pixels_drawn / pixels_to_draw));
		}
		pixels_drawn++;
	}
}
