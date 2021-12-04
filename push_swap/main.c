#include "push_swap.h"

void	print_error_and_exit();

void	populate_stack(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		push(stack, ft_atol(argv[i]));
		i++;
	}
}

int	get_max_value_in_stack(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = INT_MIN;
	while (i < stack->top)
	{
		if (stack->items[i] > max)
			max = stack->items[i];
		i++;
	}
	return (max);
}

int	get_min_value_in_stack(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = INT_MAX;
	while (i < stack->top)
	{
		if (stack->items[i] < min)
			min = stack->items[i];
		i++;
	}
	return (min);
}

int	get_item_index(t_stack *stack, int item)
{
	int	index;

	index = 0;
	while (index < stack->top && stack->items[index] != item)
		index++;
	return (index);
}

void	send_item_up(t_stack *stack_a, t_stack *stack_b, int index, int amount)
{
	int	i;
	int	item;

	if (index + amount >= stack_a->top)
	{
		printf("(send_item_up) : sending too much up in stack_a\n");
		return ;
	}
	if (index == stack_a->top - 2)
		return (sa(stack_a));
	item = stack_a->items[index];
	i = stack_a->top;
	while (i-- > index)
		pb(stack_a, stack_b);
	i = 0;
	rb(stack_b);
	while (i++ < amount)
		pa(stack_a, stack_b);
	rrb(stack_b);
	while (stack_b->top)
		pa(stack_a, stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;
	int	c;

	while (stack_a->top)
	{
		c = 0;
		temp = stack_a->items[stack_a->top - 1];
		if (stack_b->top && temp < stack_b->items[stack_b->top - 1])
		{
			c = 1;
			pb(stack_a, stack_b);
			rb(stack_b);
		}
		while (stack_b->top && temp < stack_b->items[stack_b->top - 1])
		{
			pa(stack_a, stack_b);
		}
		if (c)
			rrb(stack_b);
		pb(stack_a, stack_b);
	}
}

int main(int argc, char **argv)
{
	check_args(argc, argv);
	t_stack *stack_a = create_stack(10);
	t_stack *stack_b = create_stack(10);
	populate_stack(stack_a, argc, argv);
	stack_print("A", stack_a);
	stack_print("B", stack_b);

	sort(stack_a, stack_b);

	stack_destroy(stack_a);
	stack_destroy(stack_b);
	return (0);
}

void	print_error_and_exit()
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}