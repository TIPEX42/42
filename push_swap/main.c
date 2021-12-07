#include "push_swap.h"

//#define DEBUG

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
	if (get_item_index(stack_b, s_get_max_value(stack_b)) > s_size(stack_b) / 2)
	{
		while (peek(stack_b) != s_get_max_value(stack_b))
			rb(stack_b);
	}
	else
	{
		while (peek(stack_b) != s_get_max_value(stack_b))
			rrb(stack_b);
	}
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

void	shit_sort(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	while (!is_stack_sorted_dsc(stack_a))
	{
		if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
		{
			if (s_get_max_value(stack_a) == peek(stack_a))
			{
				if (s_get(stack_a, s_top(stack_a) - 1) != s_get_min_value(stack_a))
					sa(stack_a);
			}
			else
				sa(stack_a);
		}
		ra(stack_a);
	}
}

int	find_median(t_stack *stack)
{
	int	number;
	int	median;

	median = s_get_max_value(stack);
	number = 0;
	while (number < s_size(stack) / 2)
	{
		median = s_last_value(stack, median - 1);
		number++;
	}
	return (median);
}

void	half_sort(t_stack *stack_a, t_stack *stack_b, int virtual_size)
{
	(void)stack_b;
	int	median;
	
	printf("HalfSort() -%d-\n", virtual_size);
	if (virtual_size > 2)
	{
		median = find_median(stack_a);
		while (s_get_min_value(stack_a) <= median && get_item_index(stack_a, s_get_min_value(stack_a)) >= s_size(stack_a) - virtual_size)
		{
			if (peek(stack_a) <= median)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		half_sort(stack_a, stack_b, virtual_size / 2);
		half_sort(stack_b, stack_a, virtual_size / 2);
	}
	else if (virtual_size == 2)
	{
		printf("Peek ------\n");
		printf("	");
		stack_print("A", stack_a);
		printf("	");
		stack_print("B", stack_b);
		if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1) && peek(stack_b) < s_get(stack_b, s_top(stack_b) - 1))
			ss(stack_a, stack_b);
		else if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
			sa(stack_a);
		else if (peek(stack_b) < s_get(stack_b, s_top(stack_b) - 1))
			sb(stack_b);
		printf("	");
		stack_print("A", stack_a);
		printf("	");
		stack_print("B", stack_b);
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		printf("	");
		stack_print("A", stack_a);
		printf("	");
		stack_print("B", stack_b);
	}
	printf("Finish\n");
}

void	new_and_improved_sort(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	half_sort(stack_a, stack_b, s_size(stack_a));
	//half_sort(stack_b, stack_a, s_size(stack_b));
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
	stack_print("A", stack_a);
	stack_print("B", stack_b);

	//sort(stack_a, stack_b);
	//new_sort(stack_a, stack_b);
	//shit_sort(stack_a, stack_b);
	new_and_improved_sort(stack_a, stack_b);

	stack_print("A", stack_a);
	stack_print("B", stack_b);

	stack_destroy(stack_a);
	stack_destroy(stack_b);
	return (0);
}

void	print_error_and_exit()
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}