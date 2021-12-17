#include "../push_swap.h"

int	s_top(t_stack *stack)
{
	return (stack->top - 1);
}

int s_size(t_stack *stack)
{
	return (stack->top);
}

int	is_empty(t_stack *stack)
{
	if (stack->top == 0)
		return (1);
	return (0);
}

int	s_sum(t_stack *stack)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (i < s_size(stack))
	{
		sum += s_get(stack, i);
		i++;
	}
	return (sum);
}
