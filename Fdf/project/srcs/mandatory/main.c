/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:54:51 by                   #+#    #+#             */
/*   Updated: 2022/01/22 16:50:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	render(t_fdf *app)
{
	if (app->should_close)
		exit(1);
	if (!app->map.has_scaled)
		scale_map(&app->canvas, &app->map);
	draw_map(&app->canvas, &app->map);
	mlx_put_image_to_window(app->mlx, app->window.ptr, app->canvas.img, 0, 0);
	clear_map(&app->canvas, &app->map);
	return (0);
}

void	start_app(t_fdf *app)
{
	clear_screen(&app->canvas, get_color(0, 30, 20, 51));
	mlx_loop(app->mlx);
}

int	close_app(t_fdf *app)
{
	app->should_close = 1;
	if (app->window.ptr)
		mlx_destroy_window(app->mlx, app->window.ptr);
	if (app->canvas.img)
		mlx_destroy_image(app->mlx, app->canvas.img);
	gc_clean(&app->gc);
	exit(0);
}

void	check_args(int argc)
{
	if (argc < 2)
		ft_error_exit("No map provided\n");
	if (argc > 2)
		ft_error_exit("Too many arguments\n");
}

int	main(int argc, char **argv)
{
	t_fdf	app;

	check_args(argc);
	ft_memset(&app, 0, sizeof(t_fdf));
	gc_init(&app.gc, close_app, &app);
	create_map(&app.gc, &app.map, argv[1]);
	init_app(&app.gc, &app);
	start_app(&app);
	close_app(&app);
	return (0);
}
