#include "../../libft.h"

t_Vec4 	*vec4_add(t_Vec4 *self, const t_Vec4 other)
{
	self->x += other.x;
	self->y += other.y;
	self->z += other.z;
	self->w += other.w;
	return (self);
}
