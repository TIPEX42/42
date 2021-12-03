#include "push_swap.h"

int	is_stack_sorted_asc(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top - 1)
	{
		if (stack->items[i] > stack->items[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_stack_sorted_dsc(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top - 1)
	{
		if (stack->items[i] < stack->items[i + 1])
			return (0);
		i++;
	}
	return (1);
}
