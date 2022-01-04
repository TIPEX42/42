#include "../../libft.h"

t_Vec2	*vec2_divi(t_Vec2 *self, long value)
{
	self->x /= value;
	self->y /= value;
	return (self);
}

t_Vec2	*vec2_divf(t_Vec2 *self, float value)
{
	self->x /= value;
	self->y /= value;
	return (self);
}

t_Vec2	*vec2_divv2(t_Vec2 *self, const t_Vec2 vec)
{
	self->x /= vec.x;
	self->y /= vec.y;
	return (self);
}