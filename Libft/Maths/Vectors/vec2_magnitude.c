#include "../../libft.h"

float	vec2_mag(t_Vec2 vec)
{
	return (ft_sqrt(ft_pow2(vec.x) + ft_pow2(vec.y)));
}