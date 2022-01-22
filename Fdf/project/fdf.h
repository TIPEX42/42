/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:54:33 by                   #+#    #+#             */
/*   Updated: 2022/01/22 17:01:33 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include <mlx.h>

# define WIN_WIDTH 900
# define WIN_HEIGHT 600

typedef struct s_canvas
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	float		**depth_buffer;
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
	int			size_x;
	int			size_z;
	int			lowest_point;
	int			highest_point;
	int			**heights;
	int			**colors;
}				t_map_info;

typedef struct s_vertex
{
	t_vec4		pos;
	int			col;
}				t_vertex;

typedef struct s_map
{
	t_map_info	infos;
	t_vertex	**verticies;
	t_vertex	**projection;
	t_vec3		pos;
	t_vec3		rotation;
	t_vec3		scale;
	int			has_scaled;
}				t_map;

typedef struct s_fdf {
	void		*mlx;
	t_window	window;
	t_canvas	canvas;
	int			should_close;
	t_map		map;
	t_gc		gc;
}				t_fdf;

//main.c
int			close_app(t_fdf *app);
int			render(t_fdf *app);

//app_init.c
void		init_app(t_gc *gc, t_fdf *app);
void		init_callbacks(t_fdf *app);
t_canvas	create_canvas(t_gc *gc, void *mlx, t_window window);
t_window	create_window(t_gc *gc, void *mlx, int width, int height, char *title);

//map_init.c
t_vertex	**generate_verticies(t_gc *gc, t_map_info *infos);
t_vertex	**init_projections(t_gc *gc, t_map_info *infos);
void		create_map(t_gc *gc, t_map *map, char *file);

//map_draw.c
void		clear_map(t_canvas *canvas, t_map *map);
void		draw_map(t_canvas *canvas, t_map *map);
void		draw_wf_y(t_canvas *canvas, t_map_info *infos, \
				t_vertex **proj, int use_color);
void		draw_wf_x(t_canvas *canvas, t_map_info *infos, \
				t_vertex **proj, int use_color);
void		update_projections(t_map *map, t_map_info *infos);

//map_scale.c
void		scale_map(t_canvas *canvas, t_map *map);

//mlx_draw.c
void		mlx_set_pixel(t_canvas *canvas, int x, int y, int color);
void		clear_screen(t_canvas *canvas, int color);
void		draw_line(t_canvas *canvas, t_vertex start, t_vertex end, int use_color);

//mlx_colors.c
int			get_color(int t, int r, int g, int b);

//mlx_keys.c
int			key_callback(int key, t_fdf *app);

//parsing.c
void		load_map(t_gc *gc, t_map_info *infos, char *file);

#endif