/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys_bonus.c                                   :+:      :+:    :+:   */
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
		app->map.rotation.y -= PI / 300;
	if (key == 14)
		app->map.rotation.y += PI / 300;
	if (key == 3)
		app->map.rotation.z -= PI / 300;
	if (key == 4)
		app->map.rotation.z += PI / 300;
	if (key == 17)
		app->map.rotation.x += PI / 300;
	if (key == 5)
		app->map.rotation.x -= PI / 300;
	if (key == 0)
		app->map.pos.x += 1;
	if (key == 2)
		app->map.pos.x -= 1;

	printf("X: %f Y: %f Z: %f\n", app->map.rotation.x, app->map.rotation.y, app->map.rotation.z);
	return (0);
}
