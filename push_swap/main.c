#include "push_swap.h"

void	print_error_and_exit();

void	populate_stack(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		push(stack, ft_atol(argv[i]));
		i++;
	}
}

int	check_edges(t_stack *stack_a, t_stack *stack_b)
{
	int	max_a;
	int	max_b;

	return (0);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	while (check_edges(stack_a, stack_b))
		check_edges(stack_a, stack_b);
}

int main(int argc, char **argv)
{
	check_args(argc, argv);
	t_stack *stack_a = create_stack(10);
	t_stack *stack_b = create_stack(10);
	populate_stack(stack_a, argc, argv);
	stack_print("A", stack_a);
	stack_print("B", stack_b);

	sort(stack_a, stack_b);

	stack_destroy(stack_a);
	stack_destroy(stack_b);
	return (0);
}

void	print_error_and_exit()
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}