/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/01/06 12:55:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	mlx_set_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	mlx_draw_circle(t_mlx *mlx, t_vec2 pos, int radius, int color)
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
				mlx_set_pixel(mlx, x, y, color);
			x++;
		}
		y++;
	}

}
