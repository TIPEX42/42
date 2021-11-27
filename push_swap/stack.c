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

void	stack_print(t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	i = stack->top - 1;
	printf("Stack has %d elements\n", stack->top);
	while (i >= 0)
	{
		printf("Stack[%d] = %d\n", i,  stack->items[i]);
		i--;
	}
}

void	stack_destroy(t_stack *stack)
{
	free(stack->items);
	free(stack);
}