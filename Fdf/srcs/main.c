/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:54:51 by                   #+#    #+#             */
/*   Updated: 2022/01/06 18:38:01 by                  ###   ########.fr       */
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

t_mat4	generate_mvp(t_square *square)
{
	t_mat4	result;
	t_mvp	mvp;

	mvp.model = mat4_translate(mat4_identity(), square->pos);
	mvp.model = mat4_multm4(mvp.model, mat4_rotate(square->rotation));
	mvp.model = mat4_multm4(mvp.model, mat4_scalef(square->scale));
	mvp.view = mat4_identity();
	mvp.proj = mat4_identity();
	result = mvp.proj;
	result = mat4_multm4(result, mvp.view);
	result = mat4_multm4(result, mvp.model);
	return (result);
}

void	draw_square(t_canvas *canvas, t_square *square)
{
	t_mat4	mvp;
	t_vec4	point[4];
	int		i;

	mvp = generate_mvp(square);
	i = 0;
	while (i < 4)
	{
		point[i] = mat4_multv4(mvp, square->points[i]);
		draw_circle(canvas, (t_vec2){point[i].x, point[i].y}, 10, get_color(0, 150, 150, 150));
		i++;
	}
	i = 0;
	while (i < 3)
	{
		draw_line(canvas, (t_vec2){point[i].x, point[i].y}, (t_vec2){point[i + 1].x, point[i + 1].y}, get_color(0, 255, 0, 0));
		i++;
	}
	draw_line(canvas, (t_vec2){point[i].x, point[i].y}, (t_vec2){point[0].x, point[0].y}, get_color(0, 255, 0, 0));
}

void	rotate_square(t_fdf *app, t_square *square)
{
	square->rotation.y += app->delta_time * TWO_PI;
	square->pos.x = ft_sin(square->rotation.y) * 200 + 1920 / 2;
	square->pos.y = ft_cos(square->rotation.y) * 200 + 1080 / 2;
}

int	render(t_fdf *app)
{
	static clock_t	last_time;
	double			elapsed;

	elapsed = ((double)clock() - last_time) / CLOCKS_PER_SEC;
	ft_printf("FPS : %d\n", (int)(1.0 / elapsed));
	app->delta_time = elapsed;
	last_time = clock();
	clear_screen(&app->canvas, get_color(0, 30, 20, 51));
	//elapsed = (double)(clock() - last_time) / CLOCKS_PER_SEC;
	//printf("Clearing took %f seconds\n", elapsed);
	//last_time = clock();
	draw_square(&app->canvas, &app->square);
	//elapsed = (double)(clock() - last_time) / CLOCKS_PER_SEC;
	//printf("Drawing took %f seconds\n", elapsed);
	rotate_square(app, &app->square);
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

t_square	create_square()
{
	t_square	square;

	square.points[0] = vec4(-1, -1, 0, 1);
	square.points[1] = vec4(1, -1, 0, 1);
	square.points[2] = vec4(1, 1, 0, 1);
	square.points[3] = vec4(-1, 1, 0, 1);
	square.pos = vec3(1920 / 2, 1080 / 2, 400);
	square.rotation = vec3(0, 0, PI / 4);
	square.scale = 50;
	return (square);
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
	app->square = create_square();
	app->delta_time = 0;
	init_callbacks(app);
}

void	start_app(t_fdf *app)
{
	mlx_loop(app->mlx);
}

void	close_app(t_fdf *app)
{
	free(app->mlx);
}

int main()
{
	t_fdf	app;

	init_app(&app);
	start_app(&app);
	close_app(&app);
	return (0);
}