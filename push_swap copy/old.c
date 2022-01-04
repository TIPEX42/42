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