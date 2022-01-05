/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:20:58 by                   #+#    #+#             */
/*   Updated: 2022/01/05 18:20:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../libft.h"

t_Mat4	mat4_rotatex(t_Mat4 self, float value)
{
	t_Mat4	mat;

	mat = mat4_copy(self);
	mat.m[1][1] = ft_cos(value);
	mat.m[1][2] = -ft_sin(value);
	mat.m[2][1] = ft_sin(value);
	mat.m[2][2] = ft_cos(value);
	return (mat);
}

t_Mat4	mat4_rotatey(t_Mat4 self, float value)
{
	t_Mat4	mat;

	mat = mat4_copy(self);
	mat.m[0][0] = ft_cos(value);
	mat.m[0][2] = ft_sin(value);
	mat.m[2][0] = -ft_sin(value);
	mat.m[2][2] = ft_cos(value);
	return (mat);
}

t_Mat4	mat4_rotatez(t_Mat4 self, float value)
{
	t_Mat4	mat;

	mat = mat4_copy(self);
	mat.m[0][0] = ft_cos(value);
	mat.m[0][1] = -ft_sin(value);
	mat.m[1][0] = ft_sin(value);
	mat.m[1][1] = ft_cos(value);
	return (mat);
}

t_Mat4	mat4_rotate(t_Mat4 self, t_Vec3 vec)
{
	t_Mat4	mat;

	mat = mat4_rotateZ(self, vec.z);
	mat = mat4_rotateY(mat, vec.y);
	mat = mat4_rotateX(mat, vec.x);
	return (mat);
}
