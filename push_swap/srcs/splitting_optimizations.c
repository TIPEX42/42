#include "../push_swap.h"

void optimize_sort_3_a_safe(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{
#ifdef DEBUG
	printf("Optimizing sort\n");
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	stack_print(partitions, 0);
	getchar();
#endif
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
			ra(stack_a);
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
		{
			sa(stack_a);
			ra(stack_a);
			ra(stack_a);
			ra(stack_a);
		}
		pop(partitions);
		return ;
	}
	if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
		sa(stack_a);
	ra(stack_a);
	ra(stack_a);
	pop(partitions);
}


//TODO: merge those two ! rrr rr and ss
void optimize_sort_3_a(t_stack *stack_a, t_stack *partitions)
{
	if (peek(stack_a) == s_get_max(stack_a, s_size(stack_a)))
		ra(stack_a);
	if (s_get(stack_a, s_top(stack_a) - 1) == s_get_max(stack_a, s_size(stack_a)))
		rra(stack_a);
	if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
		sa(stack_a);
	pop(partitions);
}
//TODO: make it work
void optimize_sort_3_b(t_stack *stack_b)
{
	if (peek(stack_b) < s_get(stack_b, s_top(stack_b) - 1))
		sb(stack_b);
	if (bpeek(stack_b) == s_get_max(stack_b, s_size(stack_b)))
		rrb(stack_b);
	if (s_get(stack_b, s_top(stack_b) - 1) == s_get_max(stack_b, s_size(stack_b)))
		rb(stack_b);
}