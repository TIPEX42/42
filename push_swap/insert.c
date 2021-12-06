#include "push_swap.h"

void	insert_top_top(t_stack *stack_a, t_stack *stack_b)
{
	while (peek(stack_a) < peek(stack_b))
		rb(stack_b);
	pb(stack_a, stack_b);
}

void	insert_top_bot(t_stack *stack_a, t_stack *stack_b)
{
	while (peek(stack_a) > bpeek(stack_b))
		rrb(stack_b);
	pb(stack_a, stack_b);
}

void	insert_bot_top(t_stack *stack_a, t_stack *stack_b)
{
	while (bpeek(stack_a) < peek(stack_b))
		rb(stack_b);
	rra(stack_a);
	pb(stack_a, stack_b);
}

void	insert_bot_bot(t_stack *stack_a, t_stack *stack_b)
{
	
	while (bpeek(stack_a) > bpeek(stack_b))
		rrb(stack_b);
	rra(stack_a);
	pb(stack_a, stack_b);
}
