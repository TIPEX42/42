/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:33:37 by                   #+#    #+#             */
/*   Updated: 2022/01/09 15:34:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	app->window = create_window(app->mlx, WIN_WIDTH, WIN_HEIGHT, "Fdf YAYYYY !");
	app->canvas = create_canvas(app->mlx, app->window);
	app->should_close = 0;
	init_callbacks(app);
}
