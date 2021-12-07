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

int	get_item_index(t_stack *stack, int item)
{
	int	index;

	index = 0;
	while (index < stack->top && stack->items[index] != item)
		index++;
	return (index);
}

int	s_next_value(t_stack *stack, int value)
{
	int	i;
	int	next;

	next = s_get_max_value(stack);
	if (next < value)
		return (s_get_min_value(stack));
	i = 0;
	while (i < s_size(stack))
	{
		if (s_get(stack, i) >= value && s_get(stack, i) < next)
			next = s_get(stack, i);
		i++;
	}
	return (next);
}

int	s_last_value(t_stack *stack, int value)
{
	int	i;
	int	last;

	last = s_get_min_value(stack);
	if (last > value)
		return (s_get_max_value(stack));
	i = 0;
	while (i < s_size(stack))
	{
		if (s_get(stack, i) <= value && s_get(stack, i) > last)
			last = s_get(stack, i);
		i++;
	}
	return (last);
}

void	send_back(t_stack *stack_a, t_stack *stack_b)
{
	while (peek(stack_b) != s_get_max_value(stack_b))
		rb(stack_b);
	while (!is_empty(stack_b))
		pa(stack_a, stack_b);
}

void	new_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	best_cost;

	if (is_stack_sorted_dsc(stack_a))
		return ;
	pb(stack_a, stack_b);
	while (!is_empty(stack_a))
	{
#ifdef DEBUG
		printf("------------\n");
		stack_print("A", stack_a);
		stack_print("B", stack_b);
#endif
		best_cost = get_best_cost(stack_a, stack_b);
#ifdef DEBUG
		printf("Best cost : %d\n", best_cost);
		printf("------------\n");
		getchar();
#endif
		if (best_cost == 0)
			insert_top_top(stack_a, stack_b);
		else if (best_cost == 1)
			insert_top_bot(stack_a, stack_b);
		else if (best_cost == 2)
			insert_bot_top(stack_a, stack_b);
		else
			insert_bot_bot(stack_a, stack_b);
	}
	send_back(stack_a, stack_b);
}

int main(int argc, char **argv)
{
	check_args(argc, argv);
	t_stack *stack_a = create_stack(argc - 1);
	if (!stack_a)
		print_error_and_exit();
	t_stack *stack_b = create_stack(argc - 1);
	if (!stack_b)
	{
		stack_destroy(stack_a);
		print_error_and_exit();
	}
	populate_stack(stack_a, argc, argv);
	//stack_print("A", stack_a);
	//stack_print("B", stack_b);

	new_sort(stack_a, stack_b);
	//stack_print("A", stack_a);
	//stack_print("B", stack_b);

	stack_destroy(stack_a);
	stack_destroy(stack_b);
	return (0);
}

void	print_error_and_exit()
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}