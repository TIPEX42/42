/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:59:36 by                   #+#    #+#             */
/*   Updated: 2022/01/05 18:14:55 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

t_Vec4	*vec4_divi(t_Vec4 *self, long value)
{
	self->x /= value;
	self->y /= value;
	self->z /= value;
	self->w /= value;
	return (self);
}

t_Vec4	*vec4_divf(t_Vec4 *self, float value)
{
	self->x /= value;
	self->y /= value;
	self->z /= value;
	self->w /= value;
	return (self);
}

t_Vec4	*vec4_divv4(t_Vec4 *self, const t_Vec4 vec)
{
	self->x /= vec.x;
	self->y /= vec.y;
	self->z /= vec.z;
	self->w /= vec.w;
	return (self);
}
