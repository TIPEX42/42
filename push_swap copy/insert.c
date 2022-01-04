#include "push_swap.h"

void	insert_top_top(t_stack *stack_a, t_stack *stack_b)
{
#ifdef DEBUG
	printf("Insert top top\n");
	getchar();
#endif
	while (s_last_value(stack_b, peek(stack_a)) != peek(stack_b))
		rb(stack_b);
	pb(stack_a, stack_b);
}

void	insert_top_bot(t_stack *stack_a, t_stack *stack_b)
{
#ifdef DEBUG
	printf("Insert top bot\n");
	getchar();
#endif
	while (s_next_value(stack_b, peek(stack_a)) != bpeek(stack_b))
		rrb(stack_b);
	pb(stack_a, stack_b);
}

void	insert_bot_top(t_stack *stack_a, t_stack *stack_b)
{
#ifdef DEBUG
	printf("Insert bot top\n");
	getchar();
#endif
	while (s_last_value(stack_b, bpeek(stack_a)) != peek(stack_b))
		rb(stack_b);
	rra(stack_a);
	pb(stack_a, stack_b);
}

void	insert_bot_bot(t_stack *stack_a, t_stack *stack_b)
{
#ifdef DEBUG
	printf("Insert bot bot\n");
	printf("next of %d is %d\n", bpeek(stack_a), s_next_value(stack_b, bpeek(stack_a)));
	getchar();
#endif
	while (s_next_value(stack_b, bpeek(stack_a)) != bpeek(stack_b))
	{
		rrb(stack_b);
#ifdef DEBUG
		stack_print("B", stack_b);
		printf("bpeek(stack_b) = %d\n", bpeek(stack_b));
		printf("next of %d is %d\n", bpeek(stack_a), s_next_value(stack_b, bpeek(stack_a)));
		getchar();
#endif
	}
	rra(stack_a);
	pb(stack_a, stack_b);
}
