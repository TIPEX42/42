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

void	optimize_sort(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{
	if (peek(partitions) == 3)
	{
		if (s_get_max(stack_a, peek(partitions)) == peek(stack_a))
		{
			pb(stack_a, stack_b);
			if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
				sa(stack_a);
			ra(stack_a);
			ra(stack_a);
			pa(stack_a, stack_b);
		}
		else if (s_get_max(stack_a, peek(partitions)) == s_get(stack_a, s_top(stack_a) - 1))
		{
			ra(stack_a);
			pb(stack_a, stack_b);
			if (peek(stack_a) < bpeek(stack_a))
			{
				rra(stack_a);
				sa(stack_a);
				ra(stack_a);
			}
			ra(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
			sa(stack_a);
		pop(partitions);
		return ;
	}
	if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
		sa(stack_a);
	ra(stack_a);
	ra(stack_a);
	pop(partitions);
	return ;
}

int	push_b_opti(t_stack *stack_a, t_stack *stack_b, t_stack *partitions, int median)
{
	if (peek(stack_a) <= median)
	{
		pb(stack_a, stack_b);
		partitions->items[s_top(partitions)]--;
		return (0);
	}
	if (peek(partitions) == s_size(stack_a) && bpeek(stack_a) <= median)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
		partitions->items[s_top(partitions)]--;
		return (0);
	}
	ra(stack_a);
	return (1);
}

void	smart_rotate(t_stack *stack_a, t_stack *partitions)
{
	int	i;
	int	sorted_elements;

	i = s_top(partitions);
	sorted_elements = 0;
	while (i && is_stack_sorted_dsc(stack_a, s_get(partitions, i) + sorted_elements))
	{
		sorted_elements += s_get(partitions, i);
		i--;
	}
	if (sorted_elements < s_size(stack_a))
	{
		while (peek(partitions))
		{
			ra(stack_a);
			partitions->items[s_top(partitions)]--;
		}
		pop(partitions);
		return ;
	}
	while (s_size(stack_a) - sorted_elements)
	{
		rra(stack_a);
		sorted_elements++;
	}
	while (i--)
		pop(partitions);
}

void	s_push_low(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{
	int	rotations;
	int	median;

	if (peek(partitions) <= 3)
	{
		optimize_sort(stack_a, stack_b, partitions);
		return ;
	}
	median = s_get_median(stack_a, peek(partitions));
	rotations = 0;
	while (peek(partitions) - rotations > 0 && s_get_min(stack_a, peek(partitions) - rotations) <= median)
		rotations += push_b_opti(stack_a, stack_b, partitions, median);
	if (peek(partitions) == s_size(stack_a))
		return ;
	while (rotations--)
		rra(stack_a);
}

void	push_a_opti(t_stack *stack_a, t_stack *stack_b, t_stack *partitions, int median)
{
	if (peek(stack_b) > median && bpeek(stack_b) > median)
	{
		if (bpeek(stack_b) > peek(stack_b))
			rrb(stack_b);
		pa(stack_a, stack_b);
		partitions->items[s_top(partitions)]++;
	}
	else if (peek(stack_b) > median)
	{
		pa(stack_a, stack_b);
		partitions->items[s_top(partitions)]++;
	}
	else if (bpeek(stack_b) > median)
	{
		rrb(stack_b);
		pa(stack_a, stack_b);
		partitions->items[s_top(partitions)]++;
	}
	else
		rb(stack_b);
	return ;
}

void	s_push_high(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{
	int	median;

	push(partitions, 0);
	if (s_size(stack_b) == 1)
	{
		partitions->items[s_top(partitions)]++;
		pa(stack_a, stack_b);
		return ;
	}
	median = s_get_median(stack_b, s_size(stack_b));
	while (s_get_max(stack_b, s_size(stack_b)) > median)
		push_a_opti(stack_a, stack_b, partitions, median);
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

int	worth_rotating_a(t_stack *stack)
{
	int	i;
	int	ras;
	int	rras;

	ras = 0;
	while (!is_stack_sorted_dsc(stack, s_size(stack)) && ras++ < s_size(stack))
		rotate(stack);
	i = ras;
	while (i--)
		reverse_rotate(stack);
	rras = 0;
	while (!is_stack_sorted_dsc(stack, s_size(stack)) && rras++ < s_size(stack))
		reverse_rotate(stack);
	i = rras;
	while (i--)
		rotate(stack);
	if (ras >= s_size(stack) && rras >= s_size(stack))
		return (0);
	if (ras <= rras)
		return (1);
	return (2);
}

int	try_rotate(t_stack *stack_a)
{
	if (worth_rotating_a(stack_a) == 1)
	{
		while (!is_stack_sorted_dsc(stack_a, s_size(stack_a)))
			ra(stack_a);
		return (1);
	}
	if (worth_rotating_a(stack_a) == 2)
	{
		while (!is_stack_sorted_dsc(stack_a, s_size(stack_a)))
			rra(stack_a);
		return (1);
	}
	if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
	{
		sa(stack_a);
		return (try_rotate(stack_a));
	}
	return (0);
}

void	rotate_already_sorted(t_stack *stack_a, t_stack *partitions)
{
#ifdef DEBUG
	if (peek(stack_a) == s_get_min(stack_a, peek(partitions)))
		printf("Rotating already sorted\n");
#endif
	while (peek(stack_a) == s_get_min(stack_a, peek(partitions)))
	{
		ra(stack_a);
		partitions->items[s_top(partitions)]--;
	}
}

void	please_work_sort(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{
	if (s_size(stack_a) <= 1)
		return ;
	if (try_rotate(stack_a))
		return ;
	rotate_already_sorted(stack_a, partitions);
	while (!is_stack_sorted_dsc(stack_a, s_size(stack_a)) || !is_empty(stack_b))
	{
#ifdef DEBUG
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	stack_print(partitions, 0);
	getchar();
#endif
		if (try_rotate(stack_a))
			return ;
		if (is_stack_sorted_dsc(stack_a, peek(partitions)))
		{
#ifdef DEBUG
	printf("Push sorted partition\n");
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	stack_print(partitions, 0);
	getchar();
#endif
			smart_rotate(stack_a, partitions);
		}
		else
		{
#ifdef DEBUG
	printf("Push low\n");
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	stack_print(partitions, 0);
	getchar();
#endif
			rotate_already_sorted(stack_a, partitions);
			s_push_low(stack_a, stack_b, partitions);
			while (!is_empty(stack_b))
			{
#ifdef DEBUG
	printf("Push high\n");
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	getchar();
#endif
				s_push_high(stack_a, stack_b, partitions);
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