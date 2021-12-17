#include "../push_swap.h"

int	s_get_index(t_stack *stack, int item)
{
	int	index;

	index = 0;
	while (index < s_size(stack) && s_get(stack, index) != item)
		index++;
	return (index);
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

//TODO: test this
int s_find_longest_dsc_b(t_stack *stack_b)
{
	int i;
	int j;
	int longest_index;
	int longest_length;

	j = 0;
	longest_index = s_top(stack_b);
	longest_length = 0;
	while (j < s_size(stack_b))
	{
		i = j;
		while (i < s_top(stack_b) && s_get(stack_b, i) < s_get(stack_b, i + 1))
			i++;
		if (i - j > longest_length)
		{
			longest_length = i - j;
			longest_index = j + longest_length - 1;
			printf("Longest : %d, index : %d\n", longest_length, longest_index);
		}
		j++;
	}
	return (longest_index);
}
