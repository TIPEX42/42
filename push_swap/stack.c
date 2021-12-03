#include "push_swap.h"

t_stack	*create_stack(int capacity)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
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

void	stack_print(const char *str, t_stack *stack)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	printf("%s [%d]: ", str, stack->top);
	while (i < stack->top)
	{
		printf("%d ", stack->items[i]);
		i++;
	}
	printf("\n");
}

void	stack_destroy(t_stack *stack)
{
	free(stack->items);
	free(stack);
}