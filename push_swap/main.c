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

int abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	s_get_index(t_stack *stack, int item)
{
	int	index;

	index = 0;
	while (index < s_size(stack) && s_get(stack, index) != item)
		index++;
	return (index);
}

int	s_get_max(t_stack *stack, int part)
{
	int	max;
	int	i;

	i = s_size(stack) - part;
	max = s_get(stack, i);
	while (i < s_size(stack))
	{
		if (s_get(stack, i) > max)
			max = s_get(stack, i);
		i++;
	}
	return (max);
}

int	s_get_min(t_stack *stack, int part)
{
	int	min;
	int	i;

	i = s_size(stack) - part;
	min = s_get(stack, i);
	while (i < s_size(stack))
	{
		if (s_get(stack, i) < min)
			min = s_get(stack, i);
		i++;
	}
	return (min);
}

int	s_get_last(t_stack *stack, int value, int part)
{
	int	last;
	int	i;

	i = s_size(stack) - part;
	last = s_get_min(stack, part);
	while (i < s_size(stack))
	{
		if (s_get(stack, i) < value && s_get(stack, i) > last)
			last = s_get(stack, i);
		i++;
	}
	return (last);
}

int	s_get_median(t_stack *stack, int part)
{
	int	median;
	int	i;

	i = 0;
	median = s_get_max(stack, part);
	while (i < part / 2)
	{
		median = s_get_last(stack, median, part);
		i++;
	}
	return (median);
}

void	optimize_sort(t_stack *stack_a, t_stack *stack_b, int part)
{
	if (part == 3)
	{
		if (s_get_max(stack_a, part) == peek(stack_a))
		{
			pb(stack_a, stack_b);
			ra(stack_a);
			ra(stack_a);
			pa(stack_a, stack_b);
			rra(stack_a);
			rra(stack_a);
		}
		else if (s_get_max(stack_a, part) == s_get(stack_a, s_top(stack_a) - 1))
		{
			ra(stack_a);
			pb(stack_a, stack_b);
			ra(stack_a);
			pa(stack_a, stack_b);
			rra(stack_a);
			rra(stack_a);
		}
	}
	if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
		sa(stack_a);
}

void	s_push_low(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{
	int	rotations;
	int	median;
	int	min;
	int	i;

	if (peek(partitions) <= 3)
	{
		optimize_sort(stack_a, stack_b, peek(partitions));
		return ;
	}
	median = s_get_median(stack_a, peek(partitions));
	min = s_get(stack_a, s_size(stack_a) - peek(partitions));
	i = 0;
	while (min > median)
		min = s_get(stack_a, s_size(stack_a) - peek(partitions) + i++);
	rotations = 0;

	while (peek(stack_a) != min)
	{
		if (peek(stack_a) <= median)
		{
			pb(stack_a, stack_b);
			partitions->items[s_top(partitions)]--;
		}
		else
		{
			ra(stack_a);
			rotations++;
		}
	}
	if (peek(stack_a) <= median)
	{
		pb(stack_a, stack_b);
		partitions->items[s_top(partitions)]--;
	}
	while (rotations--)
		rra(stack_a);
}

void	s_push_high(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{
	int	rotations;
	int	median;
	int	max;
	int	i;

	push(partitions, 0);
	if (s_size(stack_b) == 1)
	{
		partitions->items[s_top(partitions)]++;
		pa(stack_a, stack_b);
		return ;
	}
	median = s_get_median(stack_b, s_size(stack_b));
	max = s_get(stack_b, 0);
	i = 0;
	while (max <= median)
		max = s_get(stack_b, i++);
	rotations = 0;
	while (peek(stack_b) != max)
	{
		if (peek(stack_b) > median)
		{
			pa(stack_a, stack_b);
			partitions->items[s_top(partitions)]++;
		}
		else
			rb(stack_b);
	}
	if (peek(stack_b) > median)
	{
			pa(stack_a, stack_b);
			partitions->items[s_top(partitions)]++;
	}
}

int	is_part_sorted(t_stack *stack, int start, int end)
{
	int	i;

	i = start;
	while (i < end - 1)
	{
		if (s_get(stack, i) > s_get(stack, i + 1))
			return (0);
		i++;
	}
	return (1);
}

void	please_work_sort(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{

	while (!is_stack_sorted_dsc(stack_a, s_size(stack_a)) || !is_empty(stack_b))
	{
#ifdef DEBUG
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	stack_print(partitions, 0);
	getchar();
#endif
		if (is_stack_sorted_dsc(stack_a, peek(partitions)))
		{
#ifdef DEBUG
	printf("Push sorted partition\n");
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	stack_print(partitions, 0);
	getchar();
#endif
			while (peek(partitions))
			{
				ra(stack_a);
				partitions->items[s_top(partitions)]--;
			}
			pop(partitions);
		}
		else
		{
			s_push_low(stack_a, stack_b, partitions);
#ifdef DEBUG
	printf("Push low\n");
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	stack_print(partitions, 0);
	getchar();
#endif
			while (!is_empty(stack_b))
			{
				s_push_high(stack_a, stack_b, partitions);
#ifdef DEBUG
	printf("Push high\n");
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	getchar();
#endif
			}
		}
		
	}
}

int main(int argc, char **argv)
{
	t_stack	*partitions;
	t_stack	*stack_a;
	t_stack	*stack_b;

	check_args(argc, argv);
	stack_a = create_stack(argc - 1, "A");
	if (!stack_a)
		print_error_and_exit();
	stack_b = create_stack(argc - 1, "B");
	if (!stack_b)
	{
		stack_destroy(stack_a);
		print_error_and_exit();
	}
	partitions = create_stack(argc - 1, "P");
	if (!partitions)
	{
		stack_destroy(stack_a);
		stack_destroy(stack_b);
		print_error_and_exit();
	}
	populate_stack(stack_a, argc, argv);
	push(partitions, argc - 1);
#ifdef DEBUG
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
#endif

	please_work_sort(stack_a, stack_b, partitions);

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