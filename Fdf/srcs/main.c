/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:54:51 by                   #+#    #+#             */
/*   Updated: 2022/01/09 15:01:57 by                  ###   ########.fr       */
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

int	render(t_fdf *app)
{
	static clock_t	last_time;
	double			elapsed;

	elapsed = ((double)clock() - last_time) / CLOCKS_PER_SEC;
	ft_printf("FPS : %d\n", (int)(1.0 / elapsed));
	app->delta_time = elapsed;
	last_time = clock();
	draw_map(&app->canvas, &app->map);
	mlx_put_image_to_window(app->mlx, app->window.ptr, app->canvas.img, 0, 0);
	clear_map(&app->canvas, &app->map, get_color(0, 30, 20, 51));
	if (app->should_close)
		close_app(app);
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
	mlx_hook(app->window.ptr, 2, 1L<<0, key_callback, app);
	mlx_hook(app->window.ptr, 17, 0, close_app, app);
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
	clear_screen(&app->canvas, get_color(0, 30, 20, 51));
	mlx_loop(app->mlx);
}

int	close_app(t_fdf *app)
{
	int	i;

	app->should_close = 1;
	mlx_destroy_window(app->mlx, app->window.ptr);
	mlx_destroy_image(app->mlx, app->canvas.img);
	i = 0;
	while (i < app->map.infos.size_z)
	{
		free(app->map.infos.heights[i]);
		free(app->map.verticies[i]);
		free(app->map.colors[i]);
		i++;
	}
	free(app->map.verticies);
	free(app->map.infos.heights);
	free(app->map.colors);
	free(app->mlx);
	exit(0);
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
