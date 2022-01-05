/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:59:40 by                   #+#    #+#             */
/*   Updated: 2022/01/05 17:59:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

t_Vec3	*vec3_multi(t_Vec3 *self, long value)
{
	self->x *= value;
	self->y *= value;
	self->z *= value;
	return (self);
}

t_Vec3	*vec3_multf(t_Vec3 *self, float value)
{
	self->x *= value;
	self->y *= value;
	self->z *= value;
	return (self);
}

t_Vec3	*vec3_multv3(t_Vec3 *self, const t_Vec3 vec)
{
	self->x *= vec.x;
	self->y *= vec.y;
	self->z *= vec.z;
	return (self);
}
