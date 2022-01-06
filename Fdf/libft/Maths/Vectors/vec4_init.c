/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:59:35 by                   #+#    #+#             */
/*   Updated: 2022/01/05 18:32:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

t_Vec4	vec4(float x, float y, float z, float w)
{
	t_Vec4	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;
	return (vec);
}

t_Vec4	vec4_copy(t_Vec4 old)
{
	t_Vec4	vec;

	vec.x = old.x;
	vec.y = old.y;
	vec.z = old.z;
	vec.w = old.w;
	return (vec);
}

t_Vec4	vec4_zero(void)
{
	t_Vec4	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	vec.w = 0;
	return (vec);
}

t_Vec4	vec4_set(float value)
{
	t_Vec4	vec;

	vec.x = value;
	vec.y = value;
	vec.z = value;
	vec.w = value;
	return (vec);
}
