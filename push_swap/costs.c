#include "push_swap.h"

int	get_cost_top_top(t_stack *stack_a, t_stack *stack_b)
{
	int	cost;

	cost = 0;
	while (cost < s_size(stack_b) && s_get(stack_b, s_top(stack_b) - cost) != s_last_value(stack_b, peek(stack_a)))
		cost++;
	return (cost + 1);
}

int	get_cost_top_bot(t_stack *stack_a, t_stack *stack_b)
{
	int	cost;

	cost = 0;
	while (cost < s_size(stack_b) && s_get(stack_b, cost) != s_next_value(stack_b, peek(stack_a)))
		cost++;
	return (cost + 1);
}

int	get_cost_bot_top(t_stack *stack_a, t_stack *stack_b)
{
	int	cost;

	cost = 0;
	while (cost < s_size(stack_b) && s_get(stack_b, s_top(stack_b) - cost) != s_last_value(stack_b, bpeek(stack_a)))
		cost++;
	return (cost + 2);
}

int	get_cost_bot_bot(t_stack *stack_a, t_stack *stack_b)
{
	int	cost;

	cost = 0;
	while (cost < s_size(stack_b) && s_get(stack_b, cost) != s_next_value(stack_b, bpeek(stack_a)))
		cost++;
	return (cost + 2);
}


int	get_best_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	costs[4];
	int	best;
	int	i;

	costs[0] = get_cost_top_top(stack_a, stack_b);
	costs[1] = get_cost_top_bot(stack_a, stack_b);
	costs[2] = get_cost_bot_top(stack_a, stack_b);
	costs[3] = get_cost_bot_bot(stack_a, stack_b);
	best = 0;
	i = 0;
	while (i < 4)
	{
		printf("Cost %d : %d\n", i, costs[i]);
		if (costs[best] > costs[i])
			best++;
		i++;
	}
	return (best);
}