#include "../../libft.h"

t_Vec2	*vec2_add(t_Vec2 *self, const t_Vec2 other)
{
	self->x += other.x;
	self->y += other.y;
	return (self);
}
