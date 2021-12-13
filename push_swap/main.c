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

int	s_get_index(t_stack *stack, int item)
{
	int	index;

	index = 0;
	while (index < s_size(stack) && s_get(stack, index) != item)
		index++;
	return (index);
}

int	s_get_max(t_stack *stack, int start, int end)
{
	int	max;
	int	i;

	i = start;
	max = s_get(stack, i);
	while (i < end)
	{
		if (s_get(stack, i) > max)
			max = s_get(stack, i);
		i++;
	}
	return (max);
}

int	s_get_min(t_stack *stack, int start, int end)
{
	int	min;
	int	i;

	i = start;
	min = s_get(stack, i);
	while (i < end)
	{
		if (s_get(stack, i) < min)
			min = s_get(stack, i);
		i++;
	}
	return (min);
}

int	s_get_last(t_stack *stack, int value, int start, int end)
{
	int	last;
	int	i;

	i = start;
	last = s_get_min(stack, start, end);
	while (i < end)
	{
		if (s_get(stack, i) < value && s_get(stack, i) > last)
			last = s_get(stack, i);
		i++;
	}
	return (last);
}

int	s_get_median(t_stack *stack, int start, int end)
{
	int	median;
	int	size;
	int	i;

	i = 0;
	size = (end - start) / 2;
	median = s_get_max(stack, start, end);
	while (i < size)
	{
		median = s_get_last(stack, median, start, end);
		i++;
	}
	return (median);
}

void	s_push_low(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	int	rotations;
	int	median;
	int	min;
	int	i;

	median = s_get_median(stack_a, start, end);
	min = s_get(stack_a, start);
	i = 0;
	while (min > median)
	{
		printf("Median : %d\n", median);
		min = s_get(stack_a, start + i++);
	}
	rotations = 0;
	
	printf("Min : %d\n", min);
	while (peek(stack_a) != min)
	{
		if (peek(stack_a) <= median)
			pb(stack_a, stack_b);
		else
		{
			ra(stack_a);
			rotations++;
		}
	}
	if (peek(stack_a) <= median)
			pb(stack_a, stack_b);
	while (rotations--)
		rra(stack_a);
}

void	s_push_high(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	int	rotations;
	int	median;
	int	max;
	int	i;

	if (s_size(stack_b) == 1)
	{
		pa(stack_a, stack_b);
		return ;
	}
	median = s_get_median(stack_b, start, end);
	max = s_get(stack_b, start);
	printf("Max : %d, median : %d\n", max, median);
	i = 0;
	while (max <= median)
		max = s_get(stack_b, start + i++);
	rotations = 0;
	while (peek(stack_b) != max) // peut opti en verifiant si c'est pas mieux de push par le dessous
	{
#ifdef DEBUG
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
#endif
		if (peek(stack_b) > median)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
	if (peek(stack_b) > median)
			pa(stack_a, stack_b);
}

void	partition(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	s_push_low(stack_a, stack_b, start, end);
#ifdef DEBUG
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
#endif
	while (!is_empty(stack_b))
	{
		s_push_high(stack_a, stack_b, 0, s_size(stack_b));
#ifdef DEBUG
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
#endif
	}
	//partition(stack_a, stack_b, (start + end) / 2, end);
	//partition(stack_a, stack_b, start, (start + end) / 2);
}

void	please_work_sort(t_stack *stack_a, t_stack *stack_b)
{
	partition(stack_a, stack_b, 0, s_size(stack_a));
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