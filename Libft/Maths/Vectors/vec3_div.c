#include "../../libft.h"

t_Vec3	*vec3_divi(t_Vec3 *self, long value)
{
	self->x /= value;
	self->y /= value;
	self->z /= value;
	return (self);
}

t_Vec3	*vec3_divf(t_Vec3 *self, float value)
{
	self->x /= value;
	self->y /= value;
	self->z /= value;
	return (self);
}

t_Vec3	*vec3_divv3(t_Vec3 *self, const t_Vec3 vec)
{
	self->x /= vec.x;
	self->y /= vec.y;
	self->z /= vec.z;
	return (self);
}