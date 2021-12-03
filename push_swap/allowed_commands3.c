#include "push_swap.h"

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	printf("rra\n");
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	printf("rrr\n");
}