#include "push_swap.h"

int	s_top(t_stack *stack)
{
	return (stack->top - 1);
}

int	s_get(t_stack *stack, int index)
{
	if (index > s_size(stack))
		return (stack->items[index - s_size(stack)]);
	return (stack->items[index]);
}

int s_size(t_stack *stack)
{
	return (stack->top);
}
