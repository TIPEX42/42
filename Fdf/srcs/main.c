/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:54:51 by                   #+#    #+#             */
/*   Updated: 2022/01/09 15:38:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	render(t_fdf *app)
{
	if (app->should_close)
		exit(1);
	if (!app->map.has_scaled)
		scale_map(&app->canvas, &app->map);
	draw_map(&app->canvas, &app->map, get_color(0, 200, 200, 200));
	mlx_put_image_to_window(app->mlx, app->window.ptr, app->canvas.img, 0, 0);
	clear_map(&app->canvas, &app->map, get_color(0, 30, 20, 51));
	return (0);
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
		free(app->map.projection[i]);
		i++;
	}
	free(app->map.verticies);
	free(app->map.projection);
	free(app->map.infos.heights);
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
	create_map(&app.map, argv[1]);
	init_app(&app);
	start_app(&app);
	close_app(&app);
	return (0);
}
