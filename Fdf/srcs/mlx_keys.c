/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 13:29:19 by                   #+#    #+#             */
/*   Updated: 2022/01/06 17:21:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_callback(int key, t_fdf *app)
{
	if (key == 53)
		app->should_close = 1;
	ft_printf("Pressed %d\n", key);
	return (0);
}

int	mouse_callback(int button, t_fdf *app)
{
	(void)app;
	ft_printf("Pressed button %d\n", button);
	return (0);
}
