#include "push_swap.h"

void	print_error_and_exit();

void	populate_stack(t_stack *stack, int argc, char **argv)
{
	argc--;
	while (argc > 0)
	{
		push(stack, ft_atol(argv[argc]));
		argc--;
	}
}

int	s_get_max_value(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = INT_MIN;
	while (i < s_size(stack))
	{
		if (s_get(stack, i) > max)
			max = s_get(stack, i);
		i++;
	}
	return (max);
}

int	s_get_min_value(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = INT_MAX;
	while (i < stack->top)
	{
		if (stack->items[i] < min)
			min = stack->items[i];
		i++;
	}
	return (min);
}

int	s_get_index(t_stack *stack, int item)
{
	int	index;

	index = 0;
	while (index < s_size(stack) && s_get(stack, index) != item)
		index++;
	return (index);
}



please_work_sort(t_stack *stack_a, t_stack *stack_b)
{

}

int main(int argc, char **argv)
{
	check_args(argc, argv);
	t_stack *stack_a = create_stack(argc - 1, "A");
	if (!stack_a)
		print_error_and_exit();
	t_stack *stack_b = create_stack(argc - 1, "B");
	if (!stack_b)
	{
		stack_destroy(stack_a);
		print_error_and_exit();
	}
	populate_stack(stack_a, argc, argv);
#ifdef DEBUG
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
#endif

	please_work_sort(stack_a, stack_b);

#ifdef DEBUG
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
#endif

	stack_destroy(stack_a);
	stack_destroy(stack_b);
	return (0);
}

void	print_error_and_exit()
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}