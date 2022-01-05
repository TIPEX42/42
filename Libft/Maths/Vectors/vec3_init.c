/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:59:42 by                   #+#    #+#             */
/*   Updated: 2022/01/05 18:31:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

t_Vec3	vec3(float x, float y, float z)
{
	t_Vec3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_Vec3	vec3_copy(t_Vec3 old)
{
	t_Vec3	vec;

	vec.x = old.x;
	vec.y = old.y;
	vec.z = old.z;
	return (vec);
}

t_Vec3	vec3_zero(void)
{
	t_Vec3	vec;

	vec.x = 0;
	vec.y = 0;
	vec.z = 0;
	return (vec);
}

t_Vec3	vec3_set(float value)
{
	t_Vec3	vec;

	vec.x = value;
	vec.y = value;
	vec.z = value;
	return (vec);
}
