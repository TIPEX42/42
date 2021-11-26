#include "push_swap.h"

t_stack	*create_stack(int capacity)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	while (!new_stack)
		new_stack = malloc(sizeof(t_stack));
	new_stack->top = 0;
	new_stack->size = capacity;
	new_stack->items = malloc(capacity * sizeof(int));
	if (!new_stack->items)
	{
		free(new_stack);
		return (NULL);
	}
	return (new_stack);
}

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

void	pop(t_stack *stack, int item)
{
	if (!stack)
		return ;
	if (stack->top == 0)
	{
		ft_putstr_fd("Stack underflow\n", 1);
		return ;
	}
	stack->top--;
	return (stack->items[stack->top]);
}

void	stack_print(t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	printf("Stack has %d elements\n", stack->top);
	while (i < stack->top)
	{
		printf("Stack[%d] = %d\n", i,  stack->items[i]);
		i++;
	}
}

void	stack_destroy(t_stack *stack)
{
	free(stack->items);
	free(stack);
}