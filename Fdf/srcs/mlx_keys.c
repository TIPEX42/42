/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:29:19 by                   #+#    #+#             */
/*   Updated: 2022/01/09 13:15:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_callback(int key, t_fdf *app)
{
	if (key == 53)
		close_app(app);
	if (key == 13)
		vec3_add(&app->map.scale, (t_vec3){1, 0.1f, 1});
	if (key == 1)
		vec3_add(&app->map.scale, (t_vec3){-1, -0.1f, -1});
	if (key == 12)
		app->map.rotation.y -= TWO_PI;
	if (key == 14)
		app->map.rotation.y += TWO_PI;
	if (key == 3)
		app->map.rotation.z -= TWO_PI;
	if (key == 4)
		app->map.rotation.z += TWO_PI;
	if (key == 17)
		app->map.rotation.x += TWO_PI;
	if (key == 5)
		app->map.rotation.x -= TWO_PI;
	if (key == 0)
		app->map.pos.x += 300;
	if (key == 2)
		app->map.pos.x -= 300;
	return (0);
}

int	mouse_callback(int button, t_fdf *app)
{
	(void)app;
	ft_printf("Pressed button %d\n", button);
	return (0);
}
