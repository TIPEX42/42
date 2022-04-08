/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:29:19 by                   #+#    #+#             */
/*   Updated: 2022/01/25 19:02:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	handle_scale(int key, t_fdf *app)
{
	if (key == 12)
		vec3_add(&app->map.scale, vec3(0.1f, 0.1f, 0.1f));
	else if (key == 14)
		vec3_add(&app->map.scale, vec3(-0.1f, -0.1f, -0.1f));
	vec3_clamp_min(&app->map.scale, 0, 0, 0);
	vec3_clamp_max(&app->map.scale, INT_MAX, INT_MAX, INT_MAX);
}

void	handle_rotate(int key, t_fdf *app)
{
	if (key == 15)
		app->map.rotation.y += PI / 200;
	else if (key == 16)
		app->map.rotation.y -= PI / 200;
	else if (key == 3)
		app->map.rotation.z += PI / 200;
	else if (key == 4)
		app->map.rotation.z -= PI / 200;
	else if (key == 17)
		app->map.rotation.x += PI / 200;
	else if (key == 5)
		app->map.rotation.x -= PI / 200;
	if (app->map.rotation.y > PI)
		app->map.rotation.y -= TWO_PI;
	else if (app->map.rotation.y < -PI)
		app->map.rotation.y += TWO_PI;
	if (app->map.rotation.z > PI)
		app->map.rotation.z -= TWO_PI;
	else if (app->map.rotation.z < -PI)
		app->map.rotation.z += TWO_PI;
	if (app->map.rotation.x > PI)
		app->map.rotation.x -= TWO_PI;
	else if (app->map.rotation.x < -PI)
		app->map.rotation.x += TWO_PI;
}

void	handle_position(int key, t_fdf *app)
{
	if (key == 0)
		app->map.pos.x += 10;
	else if (key == 2)
		app->map.pos.x -= 10;
	else if (key == 13)
		app->map.pos.y -= 10;
	else if (key == 1)
		app->map.pos.y += 10;
	vec3_clamp_min(&app->map.pos, INT_MIN, INT_MIN, INT_MIN);
	vec3_clamp_max(&app->map.pos, INT_MAX, INT_MAX, INT_MAX);
}

int	key_callback(int key, t_fdf *app)
{
	if (key == 53)
		close_app(app);
	handle_scale(key, app);
	handle_rotate(key, app);
	handle_position(key, app);
	return (0);
}
