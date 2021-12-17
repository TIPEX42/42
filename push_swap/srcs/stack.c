#include "../push_swap.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

t_stack	*create_stack(int capacity, char *name)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = 0;
	new_stack->size = capacity;
	new_stack->items = malloc(capacity * sizeof(int));
	new_stack->name = name;
	if (!new_stack->items)
	{
		free(new_stack);
		return (NULL);
	}
	return (new_stack);
}

void	populate_stack(t_stack *stack, int argc, char **argv)
{
	argc--;
	while (argc > 0)
	{
		push(stack, ft_atol(argv[argc]));
		argc--;
	}
}

void	stack_print(t_stack *stack, int virtual_size)
{
	int	i;

	if (!stack)
		return ;
	i = 0;
	printf("%s%s [%d]: ", KBLU, stack->name, stack->top);
	while (i < stack->top)
	{
		if (i >= s_size(stack) - virtual_size)
			printf("%s%d ", KRED, stack->items[i]);
		else
			printf("%s%d ", KGRN, stack->items[i]);
		i++;
		printf("%s", KYEL);
	}
	printf("\n");
}

void	stack_destroy(t_stack *stack)
{
	free(stack->items);
	free(stack);
}