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

int	s_get_next(t_stack *stack, int value, int part)
{
	int	next;
	int	i;

	i = s_size(stack) - part;
	next = s_get_max(stack, part);
	while (i < s_size(stack))
	{
		if (s_get(stack, i) > value && s_get(stack, i) < next)
			next = s_get(stack, i);
		i++;
	}
	return (next);
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
	if (part % 2 == 0)
		median = s_get_next(stack, median, part);
	return (median);
}
