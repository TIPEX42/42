/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:20:58 by                   #+#    #+#             */
/*   Updated: 2022/01/06 17:06:17 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
#include <math.h>

t_mat4	mat4_rotatex(t_mat4 self, float value)
{
	t_mat4	mat;

	mat = mat4_copy(self);
	mat.m[1][1] = cos(value);
	mat.m[1][2] = -sin(value);
	mat.m[2][1] = sin(value);
	mat.m[2][2] = cos(value);
	return (mat);
}

t_mat4	mat4_rotatey(t_mat4 self, float value)
{
	t_mat4	mat;

	mat = mat4_copy(self);
	mat.m[0][0] = cos(value);
	mat.m[0][2] = sin(value);
	mat.m[2][0] = -sin(value);
	mat.m[2][2] = cos(value);
	return (mat);
}

t_mat4	mat4_rotatez(t_mat4 self, float value)
{
	t_mat4	mat;

	mat = mat4_copy(self);
	mat.m[0][0] = cos(value);
	mat.m[0][1] = -sin(value);
	mat.m[1][0] = sin(value);
	mat.m[1][1] = cos(value);
	return (mat);
}

t_mat4	mat4_rotate(t_vec3 vec)
{
	t_mat4	mat;

	mat = mat4_rotatey(mat4_identity(), vec.y);
	mat = mat4_multm4(mat, mat4_rotatez(mat4_identity(), vec.z));
	mat = mat4_multm4(mat, mat4_rotatex(mat4_identity(), vec.x));
	return (mat);
}
