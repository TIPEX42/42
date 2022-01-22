/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/01/22 16:50:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	mlx_set_pixel(t_canvas *canvas, int x, int y, int color)
{
	char		*dst;

	y = canvas->height - y;
	if (x < 0 || x >= canvas->width || y < 0 || y >= canvas->height)
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

void	draw_line(t_canvas *canvas, t_vertex start, t_vertex end, int use_color)
{
	double	pixels_to_draw;
	double	pixels_drawn;
	t_vec3	pixel_pos;

	pixels_to_draw = ft_sqrt((ft_pow2(start.pos.x)) + ft_pow2(end.pos.y));
	pixels_drawn = 0;
	while (pixels_drawn < pixels_to_draw)
	{
		pixel_pos.x = ft_lerpf(start.pos.x, end.pos.x, pixels_drawn / pixels_to_draw);
		pixel_pos.y = ft_lerpf(start.pos.y, end.pos.y, pixels_drawn / pixels_to_draw);
		pixel_pos.z = ft_lerpf(start.pos.z, end.pos.z, pixels_drawn / pixels_to_draw);
		if ((int)pixel_pos.x < 0 || (int)pixel_pos.x >= canvas->width ||
		(int)pixel_pos.y < 0 || (int)pixel_pos.y >= canvas->height)
			continue ;
		if (!use_color)
			mlx_set_pixel(canvas, pixel_pos.x, pixel_pos.y, get_color(0, 30, 20, 51));
		else if (pixel_pos.z < canvas->depth_buffer[(int)pixel_pos.y][(int)pixel_pos.x])
		{
			canvas->depth_buffer[(int)pixel_pos.y][(int)pixel_pos.x] = pixel_pos.z;
			mlx_set_pixel(canvas, pixel_pos.x, pixel_pos.y, end.col);
		}
		pixels_drawn++;
	}
}
