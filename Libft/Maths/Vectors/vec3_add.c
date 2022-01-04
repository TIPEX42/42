#include "../../libft.h"

t_Vec3	*vec3_add(t_Vec3 *self, const t_Vec3 other)
{
	self->x += other.x;
	self->y += other.y;
	self->z += other.z;
	return (self);
}
