/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:58:52 by                   #+#    #+#             */
/*   Updated: 2022/01/05 17:58:52 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_Mat4	mat4(float value)
{
	t_Mat4	mat;

	mat = mat4_zero();
	mat.m[0][0] = value;
	mat.m[1][1] = value;
	mat.m[2][2] = value;
	mat.m[3][3] = value;
	return (mat);
}

t_Mat4	mat_copy(t_Mat4 old)
{
	t_Mat4	mat;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mat.m[i][j] = old.m[i][j];
			j++;
		}
		i++;
	}
	return (mat);
}

t_Mat4	mat4_identity(void)
{
	return (mat4(1.0f));
}

t_Mat4	mat4_zero(void)
{
	t_Mat4	mat;

	mat.m[0][0] = 0;
	mat.m[0][1] = 0;
	mat.m[0][2] = 0;
	mat.m[0][3] = 0;
	mat.m[1][0] = 0;
	mat.m[1][1] = 0;
	mat.m[1][2] = 0;
	mat.m[1][3] = 0;
	mat.m[2][0] = 0;
	mat.m[2][1] = 0;
	mat.m[2][2] = 0;
	mat.m[2][3] = 0;
	mat.m[3][0] = 0;
	mat.m[3][1] = 0;
	mat.m[3][2] = 0;
	mat.m[3][3] = 0;
	return (mat);
}
