/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:59:33 by                   #+#    #+#             */
/*   Updated: 2022/01/05 18:13:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

t_Vec4	*vec4_multi(t_Vec4 *self, long value)
{
	self->x *= value;
	self->y *= value;
	self->z *= value;
	self->w *= value;
	return (self);
}

t_Vec4	*vec4_multf(t_Vec4 *self, float value)
{
	self->x *= value;
	self->y *= value;
	self->z *= value;
	self->w *= value;
	return (self);
}

t_Vec4	*vec4_multv4(t_Vec4 *self, const t_Vec4 vec)
{
	self->x *= vec.x;
	self->y *= vec.y;
	self->z *= vec.z;
	self->w *= vec.w;
	return (self);
}
