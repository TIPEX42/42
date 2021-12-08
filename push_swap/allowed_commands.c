#include "push_swap.h"

void	sa(t_stack *stack)
{
	swap(stack);
	//#ifndef NO_OUT
	printf("sa\n");
	//#endif
}

void	sb(t_stack *stack)
{
	swap(stack);
	//#ifndef NO_OUT
	printf("sb\n");
	//#endif
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	//#ifndef NO_OUT
	printf("ss\n");
	//#endif
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, pop(stack_b));
	#ifndef NO_OUT
	printf("pa\n");
	#endif
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, pop(stack_a));
	#ifndef NO_OUT
	printf("pb\n");
	#endif
}