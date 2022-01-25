/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:33:37 by                   #+#    #+#             */
/*   Updated: 2022/01/25 18:57:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

t_window	create_window(t_gc *gc, void *mlx, int width, int height)
{
	t_window	window;

	window.width = width;
	window.height = height;
	window.ptr = mlx_new_window(mlx, width, height, "fdf");
	if (!window.ptr)
	{
		ft_printf("Couldn't create a window\n");
		gc->callback(gc->param);
	}
	return (window);
}

t_canvas	create_canvas(t_gc *gc, void *mlx, t_window window)
{
	int			i;
	t_canvas	canvas;

	canvas.width = window.width;
	canvas.height = window.height;
	canvas.img = mlx_new_image(mlx, window.width, window.height);
	if (!canvas.img)
	{
		ft_printf("Couldn't create a canvas\n");
		gc->callback(gc->param);
	}
	canvas.depth_buffer = gc_calloc(gc, canvas.height, sizeof (float *));
	i = 0;
	while (i < canvas.height)
	{
		canvas.depth_buffer[i] = gc_calloc(gc, canvas.width, sizeof(float));
		ft_memsetf(canvas.depth_buffer[i], INT_MIN, canvas.width);
		i++;
	}
	canvas.addr = mlx_get_data_addr(canvas.img, &canvas.bits_per_pixel, \
									&canvas.line_length, &canvas.endian);
	return (canvas);
}

void	init_callbacks(t_fdf *app)
{
	mlx_hook(app->window.ptr, 2, 1L << 0, key_callback, app);
	mlx_hook(app->window.ptr, 17, 0, close_app, app);
	mlx_loop_hook(app->mlx, render, app);
}

void	init_app(t_gc *gc, t_fdf *app)
{
	app->mlx = mlx_init();
	if (!app->mlx)
	{
		printf("Couldn't initialize mlx\n");
		gc->callback(gc->param);
	}
	app->window = create_window(gc, app->mlx, WIN_WIDTH, WIN_HEIGHT);
	app->canvas = create_canvas(gc, app->mlx, app->window);
	app->should_close = 0;
	init_callbacks(app);
}
