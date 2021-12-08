#include "push_swap.h"

void	ra(t_stack *stack)
{
	rotate(stack);
	#ifndef NO_OUT
	if (!ft_strncmp(stack->name, "A", 1))
		printf("ra\n");
	else
		printf("rb\n");
	#endif
}

void	rb(t_stack *stack)
{
	rotate(stack);
	#ifndef NO_OUT
	if (!ft_strncmp(stack->name, "A", 1))
		printf("ra\n");
	else
		printf("rb\n");
	#endif
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	#ifndef NO_OUT
	printf("rr\n");
	#endif
}