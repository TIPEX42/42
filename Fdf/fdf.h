/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:54:33 by                   #+#    #+#             */
/*   Updated: 2022/01/09 15:03:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "Libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct s_mvp
{
	t_mat4	model;
	t_mat4	view;
	t_mat4	proj;
}			t_mvp;

typedef struct s_canvas
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_canvas;

typedef struct s_window
{
	void		*ptr;
	int			width;
	int			height;
}				t_window;

typedef struct s_map_info
{
	int	size_x;
	int	size_z;
	int	lowest_point;
	int	highest_point;
	int	**heights;
}		t_map_info;

typedef struct s_map
{
	t_map_info	infos;
	t_vec4		**verticies;
	t_vec4		**projection;
	int			**colors;
	t_vec3		pos;
	t_vec3		rotation;
	t_vec3		scale;
}				t_map;


typedef struct s_fdf {
	void		*mlx;
	t_window	window;
	t_canvas	canvas;
	int			should_close;
	double		delta_time;
	t_map		map;
}				t_fdf;

//app.c
int	close_app(t_fdf *app);

//map_init.c
t_vec4	**generate_verticies(t_map_info *infos);
t_vec4	**init_projections(t_map_info *infos);
void	create_map(t_map *map, char *file);

//map_draw.c
void	clear_map(t_canvas *canvas, t_map *map, int color);
void	draw_map(t_canvas *canvas, t_map *map);
void 	draw_wf_y(t_canvas *canvas, t_map_info *infos, t_vec4 **proj, int color);
void 	draw_wf_x(t_canvas *canvas, t_map_info *infos, t_vec4 **proj, int color);
void	update_projections(t_map *map, t_map_info *infos);

//mlx_draw.c
void	mlx_set_pixel(t_canvas *canvas, int x, int y, int color);
void	clear_screen(t_canvas *canvas, int color);
void	draw_circle(t_canvas *canvas, t_vec2 pos, int radius, int color);
void	draw_line(t_canvas *canvas, t_vec2 start, t_vec2 end, int color);

//mlx_colors.c
int	get_colorv3(t_vec3 color);
int	get_color(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

//mlx_keys.c
int	key_callback(int key, t_fdf *app);
int	mouse_callback(int button, t_fdf *app);

//parsing.c
void	load_map(t_map_info *infos, char *file);

#endif