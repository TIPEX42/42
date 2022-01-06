/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:17:51 by                   #+#    #+#             */
/*   Updated: 2022/01/05 18:17:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

t_Vec2	*vec2_normalize(t_Vec2 *vec)
{
	float	magnitude;

	magnitude = vec2_mag(*vec);
	vec->x /= magnitude;
	vec->y /= magnitude;
	return (vec);
}

t_Vec2	vec2_normalized(t_Vec2 vec)
{
	float	magnitude;
	t_Vec2	normalized;

	magnitude = vec2_mag(vec);
	normalized.x = vec.x / magnitude;
	normalized.y = vec.y / magnitude;
	return (normalized);
}
