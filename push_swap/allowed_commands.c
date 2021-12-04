#include "push_swap.h"

void	sa(t_stack *stack)
{
	swap(stack);
	printf("sa\n");
}

void	sb(t_stack *stack)
{
	swap(stack);
	printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	printf("ss\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, pop(stack_b));
	printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, pop(stack_a));
	printf("pb\n");
}