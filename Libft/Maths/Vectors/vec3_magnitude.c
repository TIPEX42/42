#include "../../libft.h"

float	vec3_mag(t_Vec3 vec)
{
	return (ft_sqrt(
			ft_pow2(vec.x) +	\
			ft_pow2(vec.y) +		\
			ft_pow2(vec.z))		\
			);
}