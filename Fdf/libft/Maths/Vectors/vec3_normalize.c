/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:59:39 by                   #+#    #+#             */
/*   Updated: 2022/01/05 17:59:39 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

t_Vec3	*vec3_normalize(t_Vec3 *vec)
{
	float	magnitude;

	magnitude = vec3_mag(*vec);
	vec->x /= magnitude;
	vec->y /= magnitude;
	vec->z /= magnitude;
	return (vec);
}

t_Vec3	vec3_normalized(t_Vec3 vec)
{
	float	magnitude;
	t_Vec3	normalized;

	magnitude = vec3_mag(vec);
	normalized.x = vec.x / magnitude;
	normalized.y = vec.y / magnitude;
	normalized.z = vec.z / magnitude;
	return (normalized);
}
