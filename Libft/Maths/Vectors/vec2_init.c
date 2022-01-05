/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:59:45 by                   #+#    #+#             */
/*   Updated: 2022/01/05 18:30:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

t_Vec2	vec2(float x, float y)
{
	t_Vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_Vec2	vec2_copy(t_Vec2 old)
{
	t_Vec2	vec;

	vec.x = old.x;
	vec.y = old.y;
	return (vec);
}

t_Vec2	vec2_zero(void)
{
	t_Vec2	vec;

	vec.x = 0;
	vec.y = 0;
	return (vec);
}

t_Vec2	vec2_set(float value)
{
	t_Vec2	vec;

	vec.x = value;
	vec.y = value;
	return (vec);
}
