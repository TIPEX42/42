/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/01/06 18:08:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	mlx_set_pixel(t_canvas *canvas, int x, int y, int color)
{
	char		*dst;

	if (x < 0 || x > canvas->width || y < 0 || y > canvas->height)
		return ;
	dst = canvas->addr + (y * canvas->line_length + x * (canvas->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//TODO: Just re-draw all models where they were last time they were drawn with the "clear color"
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
		*((unsigned int*)(canvas->addr + i * bytes_pp)) = color;
		i++;
	}
}

void	draw_circle(t_canvas *canvas, t_vec2 pos, int radius, int color)
{
	int	x;
	int	y;

	y = pos.y - radius;
	while (y <= pos.y + radius)
	{
		x = pos.x - radius;
		while (x <= pos.x + radius)
		{
			if (ft_pow2(pos.x - x) + ft_pow2(pos.y - y) < ft_pow2(radius))
				mlx_set_pixel(canvas, x, y, color);
			x++;
		}
		y++;
	}

}

void	draw_line(t_canvas *canvas, t_vec2 start, t_vec2 end, int color)
{
	double	delta_x;
	double	delta_y;
	double	pixels_x;
	double	pixels_y;
	double	pixels;

	delta_x = end.x - start.x;
	delta_y = end.y - start.y;
	pixels = ft_sqrt((ft_pow2(delta_x)) + ft_pow2(delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixels_x = start.x;
	pixels_y = start.y;
	while (pixels >= 0)
	{
		mlx_set_pixel(canvas, pixels_x, pixels_y, color);
		pixels_x += delta_x;
		pixels_y += delta_y;
		pixels--;
	}
}
