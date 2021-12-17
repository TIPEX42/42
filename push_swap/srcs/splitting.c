#include "../push_swap.h"

int	push_b_opti(t_stack *stack_a, t_stack *stack_b, t_stack *partitions, int median)
{
	if (peek(stack_a) <= median)
	{
		//if (peek(stack_a) != s_get_min(stack_a, peek(partitions)) || peek(stack_a) >= s_get_min(stack_b, s_size(stack_b)))
		pb(stack_a, stack_b);
		partitions->items[s_top(partitions)]--;
		return (0);
	}
	if (peek(partitions) == s_size(stack_a) && bpeek(stack_a) <= median)
	{
		//if (bpeek(stack_a) != s_get_min(stack_a, peek(partitions)) || bpeek(stack_a) >= s_get_min(stack_b, s_size(stack_b)))
		//{
		rra(stack_a);
		pb(stack_a, stack_b);
		//}
		partitions->items[s_top(partitions)]--;
		return (0);
	}
	ra(stack_a);
	return (1);
}

void	s_push_low(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{
	int	rotations;
	int	median;

	if (s_size(stack_a) <= 3)
	{
		optimize_sort_3_a(stack_a, partitions);
		return ;
	}
	if (peek(partitions) <= 3)
	{
		optimize_sort_3_a_safe(stack_a, stack_b, partitions);
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

	if (s_size(stack_b) == 1)
	{
		partitions->items[s_top(partitions)]++;
		pa(stack_a, stack_b);
		return ;
	}
	if (s_size(stack_a) <= 3)
		optimize_sort_3_a(stack_a, partitions);
	if (s_size(stack_b) <= 3)
		optimize_sort_3_b(stack_b);
	push(partitions, 0);
	median = s_get_median(stack_b, s_size(stack_b));
	while (s_get_max(stack_b, s_size(stack_b)) > median)
		push_a_opti(stack_a, stack_b, partitions, median);
	if (peek(stack_b) > median)
	{
		pa(stack_a, stack_b);
		partitions->items[s_top(partitions)]++;
	}
}