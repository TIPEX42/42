#include "push_swap.h"

int	peek(t_stack *stack)
{
	return (stack->items[stack->top - 1]);
}

int	bpeek(t_stack *stack)
{
	return (stack->items[0]);
}

int	is_empty(t_stack *stack)
{
	if (stack->top == 0)
		return (1);
	return (0);
}
