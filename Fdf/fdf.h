/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:54:33 by                   #+#    #+#             */
/*   Updated: 2022/01/06 11:31:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct s_mlx {
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx;

//mlx_draw.c
void	mlx_set_pixel(t_mlx *mlx, int x, int y, int color);
void	mlx_set_pixel(t_mlx *mlx, int x, int y, int color)

#endif