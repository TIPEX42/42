/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:54:51 by                   #+#    #+#             */
/*   Updated: 2022/01/08 15:02:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

//TODO: Gerer les events de la fenetre (close, minimize...)

void	printmat(t_mat4 mat)
{
	printf("Matrix :\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%f ", mat.m[i][j]);
		}
		printf("\n");
	}
}

void	printpoint(t_vec4 point)
{
	printf("Point : x[%f] y[%f] z[%f] w[%f]\n", point.x, point.y, point.z, point.w);
}

t_mat4	generate_mvp(t_map *map)
{
	t_mat4	result;
	t_mvp	mvp;

	mvp.model = mat4_translate(mat4_identity(), map->pos);
	mvp.model = mat4_multm4(mvp.model, mat4_rotate(map->rotation));
	mvp.model = mat4_multm4(mvp.model, mat4_scalev3(map->scale));
	mvp.view = mat4_identity();
	mvp.proj = mat4_identity();
	result = mvp.proj;
	result = mat4_multm4(result, mvp.view);
	result = mat4_multm4(result, mvp.model);
	return (result);
}

void	update_projections(t_map *map, t_map_info *infos)
{
	t_mat4	mvp;
	int		i;
	int		j;

	mvp = generate_mvp(map);
	i = 0;
	while (i < infos->size_z)
	{
		j = 0;
		while (j < infos->size_x)
		{
			map->projection[i][j] = mat4_multv4(mvp, map->verticies[i][j]);
			j++;
		}
		i++;
	}
}

void draw_wires_x(t_canvas *canvas, t_map_info *infos, t_vec4 **projection)
{
	int	i;
	int	j;

	i = 0;
	while (i < infos->size_z)
	{
		j = 0;
		while (j < infos->size_x - 1)
		{
			draw_line(canvas, (t_vec2){projection[i][j].x, projection[i][j].y},
					  (t_vec2){projection[i][j + 1].x, projection[i][j + 1].y},
					  get_color(0, 200, 200, 200));
			j++;
		}
		i++;
	}
}

void draw_wires_y(t_canvas *canvas, t_map_info *infos, t_vec4 **projection)
{
	int	i;
	int	j;

	i = 0;
	while (i < infos->size_z - 1)
	{
		j = 0;
		while (j < infos->size_x)
		{
			draw_line(canvas, (t_vec2){projection[i][j].x, projection[i][j].y},
					  (t_vec2){projection[i + 1][j].x, projection[i + 1][j].y},
					  get_color(0, 200, 200, 200));
			j++;
		}
		i++;
	}
}

void	draw_map(t_canvas *canvas, t_map *map)
{
	update_projections(map, &map->infos);
	draw_wires_x(canvas, &map->infos, map->projection);
	draw_wires_y(canvas, &map->infos, map->projection);
}

void	rotate_map(t_fdf *app, t_map *map)
{
	map->rotation.y += app->delta_time * HALF_PI;
	map->rotation.x += app->delta_time * HALF_PI / 2;
}

int	render(t_fdf *app)
{
	static clock_t	last_time;
	double			elapsed;

	elapsed = ((double)clock() - last_time) / CLOCKS_PER_SEC;
	//ft_printf("FPS : %d\n", (int)(1.0 / elapsed));
	app->delta_time = elapsed;
	last_time = clock();
	clear_screen(&app->canvas, get_color(0, 30, 20, 51));
	//elapsed = (double)(clock() - last_time) / CLOCKS_PER_SEC;
	//printf("Clearing took %f seconds\n", elapsed);
	//last_time = clock();
	draw_map(&app->canvas, &app->map);
	//elapsed = (double)(clock() - last_time) / CLOCKS_PER_SEC;
	//printf("Drawing took %f seconds\n", elapsed);
	rotate_map(app, &app->map);
	mlx_put_image_to_window(app->mlx, app->window.ptr, app->canvas.img, 0, 0);
	if (app->should_close)
	{
		mlx_destroy_image(app->mlx, app->canvas.img);
		mlx_destroy_window(app->mlx, app->window.ptr);
		free(app->mlx);
		exit(0);
	}
	return (0);
}

t_window	create_window(void *mlx, int width, int height, char *title)
{
	t_window	window;

	window.width = width;
	window.height = height;
	window.ptr = mlx_new_window(mlx, width, height, title);
	if (!window.ptr)
	{
		ft_printf("Couldn't create a window\n");
		exit(1);
	}
	return (window);
}

t_canvas	create_canvas(void *mlx, t_window window)
{
	t_canvas	canvas;

	canvas.width = window.width;
	canvas.height = window.height;
	canvas.img = mlx_new_image(mlx, window.width, window.height);
	if (!canvas.img)
	{
		ft_printf("Couldn't create a canvas\n");
		exit(1);
	}
	canvas.addr = mlx_get_data_addr(canvas.img, &canvas.bits_per_pixel,
									&canvas.line_length, &canvas.endian);
	return (canvas);
}

void	init_callbacks(t_fdf *app)
{
	mlx_key_hook(app->window.ptr, key_callback, app);
	mlx_mouse_hook(app->window.ptr, mouse_callback, app);
	mlx_loop_hook(app->mlx, render, app);
}

void	init_app(t_fdf *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
	{
		printf("Couldn't initialize mlx\n");
		exit(1);
	}
	app->window = create_window(app->mlx, 1920, 1080, "Fdf YAYYYY !");
	app->canvas = create_canvas(app->mlx, app->window);
	app->should_close = 0;
	app->delta_time = 0;
	init_callbacks(app);
}

void	start_app(t_fdf *app)
{
	mlx_loop(app->mlx);
}

void	close_app(t_fdf *app)
{
	int	i;

	i = 0;
	while (i < app->map.infos.size_z)
	{
		free(app->map.infos.heights[i]);
		free(app->map.verticies[i]);
		i++;
	}
	free(app->map.verticies);
	free(app->map.infos.heights);
	free(app->mlx);
}

t_vec4	**generate_verticies(t_map_info *infos)
{
	t_vec4	**tab;
	int		i;
	int		j;

	tab = ft_calloc(infos->size_z, sizeof(t_vec4));
	if (!tab)
		ft_error_exit("Allocation error\n");
	i = 0;
	while (i < infos->size_z)
	{
		tab[i] = ft_calloc(infos->size_x, sizeof(t_vec4));
		if (!tab[i])
			ft_error_exit("Allocation error\n");
		j = 0;
		while (j < infos->size_x)
		{
			tab[i][j] = vec4(j - infos->size_x / 2, infos->heights[i][j], i - infos->size_z / 2, 1);
			j++;
		}
		i++;
	}
	return (tab);
}

t_vec4	**init_projections(t_map_info *infos)
{
	t_vec4	**tab;
	int		i;

	tab = ft_calloc(infos->size_z, sizeof(t_vec4));
	if (!tab)
		ft_error_exit("Allocation error\n");
	i = 0;
	while (i < infos->size_z)
	{
		tab[i] = ft_calloc(infos->size_x, sizeof(t_vec4));
		if (!tab[i])
			ft_error_exit("Allocation error\n");
		i++;
	}
	return (tab);
}

void	create_map(t_map *map, char *file)
{
	load_map(&map->infos, file);
	map->pos = vec3(1920 / 2, 1080 / 2, 0);
	map->rotation = vec3_zero();
	map->scale = vec3(50, 5, 50);
	map->verticies = generate_verticies(&map->infos);
	map->projection = init_projections(&map->infos);
}

void	check_args(int argc)
{
	if (argc < 2)
		ft_error_exit("No map provided\n");
	if (argc > 2)
		ft_error_exit("Too many arguments\n");
}

int main(int argc, char **argv)
{
	t_fdf	app;

	check_args(argc);
	create_map(&app.map, argv[1]);
	init_app(&app);
	start_app(&app);
	close_app(&app);
	return (0);
}
