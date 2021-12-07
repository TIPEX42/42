#include "push_swap.h"

void	push(t_stack *stack, int item)
{
	if (!stack)
		return ;
	if (stack->top == stack->size)
	{
		ft_putstr_fd("Stack overflow\n", 1);
		return ;
	}
	stack->items[stack->top] = item;
	stack->top++;
}

int	pop(t_stack *stack)
{
	if (!stack)
		return (0);
	if (stack->top == 0)
	{
		ft_putstr_fd("Stack underflow\n", 1);
		return (0);
	}
	stack->top--;
	return (stack->items[stack->top]);
}

void	swap(t_stack *stack)
{
	int	temp_item;

	if (s_size(stack) < 2)
		return ;
	temp_item = peek(stack);
	stack->items[s_top(stack)] = stack->items[s_top(stack) - 1];
	stack->items[s_top(stack) - 1] = temp_item;
}

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	temp_last_item;

	temp_last_item = stack->items[0];
	i = 0;
	while (i < stack->top - 1)
	{
		stack->items[i] = stack->items[i + 1];
		i++;
	}
	stack->items[stack->top - 1] = temp_last_item;
}

void	rotate(t_stack *stack)
{
	int	i;
	int	temp_first_item;

	temp_first_item = stack->items[stack->top - 1];
	i = stack->top - 1;
	while (i > 0)
	{
		stack->items[i] = stack->items[i - 1];
		i--;
	}
	stack->items[0] = temp_first_item;
}