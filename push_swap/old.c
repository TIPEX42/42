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

void	new_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	best_cost;

	if (is_stack_sorted_dsc(stack_a))
		return ;
	pb(stack_a, stack_b);
	while (!is_empty(stack_a))
	{
#ifdef DEBUG
		printf("------------\n");
		stack_print(stack_a);
		stack_print(stack_b);
#endif
		best_cost = get_best_cost(stack_a, stack_b);
#ifdef DEBUG
		printf("Best cost : %d\n", best_cost);
		printf("------------\n");
		getchar();
#endif
		if (best_cost == 0)
			insert_top_top(stack_a, stack_b);
		else if (best_cost == 1)
			insert_top_bot(stack_a, stack_b);
		else if (best_cost == 2)
			insert_bot_top(stack_a, stack_b);
		else
			insert_bot_bot(stack_a, stack_b);
	}
	send_back(stack_a, stack_b);
}

int	s_next_value(t_stack *stack, int value)
{
	int	i;
	int	next;

	next = s_get_max_value(stack);
	if (next < value)
		return (s_get_min_value(stack));
	i = 0;
	while (i < s_size(stack))
	{
		if (s_get(stack, i) >= value && s_get(stack, i) < next)
			next = s_get(stack, i);
		i++;
	}
	return (next);
}

int	s_last_value(t_stack *stack, int value)
{
	int	i;
	int	last;

	last = s_get_min_value(stack);
	if (last > value)
		return (s_get_max_value(stack));
	i = 0;
	while (i < s_size(stack))
	{
		if (s_get(stack, i) <= value && s_get(stack, i) > last)
			last = s_get(stack, i);
		i++;
	}
	return (last);
}

void	send_back(t_stack *stack_a, t_stack *stack_b)
{
	if (get_item_index(stack_b, s_get_max_value(stack_b)) > s_size(stack_b) / 2)
	{
		while (peek(stack_b) != s_get_max_value(stack_b))
			rb(stack_b);
	}
	else
	{
		while (peek(stack_b) != s_get_max_value(stack_b))
			rrb(stack_b);
	}
	while (!is_empty(stack_b))
		pa(stack_a, stack_b);
}



void	shit_sort(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	while (!is_stack_sorted_dsc(stack_a))
	{
		if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
		{
			if (s_get_max_value(stack_a) == peek(stack_a))
			{
				if (s_get(stack_a, s_top(stack_a) - 1) != s_get_min_value(stack_a))
					sa(stack_a);
			}
			else
				sa(stack_a);
		}
		ra(stack_a);
	}
}

void	send_low_to_stack(t_stack *stack_a, t_stack *stack_b, int median, int virtual_size)
{
	int	rotations;
	int	min_val;

	rotations = 0;
	if (s_size(stack_a) - virtual_size < 0)
		min_val = s_get(stack_a, 0);
	else
		min_val = s_get(stack_a, s_size(stack_a) - virtual_size);
	while (min_val > median)
		min_val = s_get(stack_a, get_item_index(stack_a, min_val) + 1);
	//while (s_get_min_value(stack_a) <= median && get_item_index(stack_a, s_get_min_value(stack_a)) >= s_size(stack_a) - virtual_size)
	while (is_empty(stack_b) || peek(stack_b) != min_val)
	{
		if (peek(stack_a) <= median)
			pb(stack_a, stack_b);
		else
		{
			ra(stack_a);
			rotations++;
		}
	}
	if (s_size(stack_a) == virtual_size / 2)
		return ;
	while (rotations--)
		rra(stack_a);
}

int	find_median(t_stack *stack, int virtual_size)
{
	int	i;
	int	median;

	median = s_get_max_value(stack);
	while (get_item_index(stack, median) < s_size(stack) - virtual_size)
		median = s_last_value(stack, median - 1);
	i = 0;
	while (i < virtual_size / 2)
	{
		median = s_last_value(stack, median - 1);
		i++;
	}
	return (median);
}

void	swap_tops(t_stack *stack_a, t_stack *stack_b, int vs1, int vs2)
{
	if (!ft_strncmp(stack_a->name, "A", 1))
		{
			if (vs1 > 1 && vs2 > 1 && peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1) && peek(stack_b) < s_get(stack_b, s_top(stack_b) - 1))
				ss(stack_a, stack_b);
			else if (vs1 > 1 && peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
				sa(stack_a);
			else if (vs2 > 1 && peek(stack_b) < s_get(stack_b, s_top(stack_b) - 1))
				sb(stack_b);
		}
		else
		{
			if (vs1 > 1 && vs2 > 1 && peek(stack_a) < s_get(stack_a, s_top(stack_a) - 1) && peek(stack_b) > s_get(stack_b, s_top(stack_b) - 1))
				ss(stack_a, stack_b);
			else if (vs1 > 1 && peek(stack_a) < s_get(stack_a, s_top(stack_a) - 1))
				sa(stack_a);
			else if (vs2 > 1 && peek(stack_b) > s_get(stack_b, s_top(stack_b) - 1))
				sb(stack_b);
		}
}

void	rev_dsc_vs_safe(t_stack *stack_a, t_stack *stack_b, int virtual_size, int lowest)
{
	int	i;
	int	j;

	i = 0;
	while (peek(stack_a) != lowest)
	{
		pb(stack_a, stack_b);
		i++;
	}
	j = 0;
	while (i + j < virtual_size)
	{
		ra(stack_a);
		j++;
	}
	while (i--)
		pa(stack_a, stack_b);
	while (j--)
		rra(stack_a);
}

void	rev_asc_vs_safe(t_stack *stack_a, t_stack *stack_b, int virtual_size, int lowest)
{
	int	i;
	int	j;

	i = 0;
	while (peek(stack_a) != lowest)
	{
		pa(stack_a, stack_b);
		i++;
	}
	j = 0;
	while (i + j < virtual_size)
	{
		rb(stack_b);
		j++;
	}
	while (i--)
		pb(stack_a, stack_b);
	while (j--)
		rrb(stack_b);
}

void	rev_dsc_vs(t_stack *stack_a, t_stack *stack_b, int virtual_size, int lowest)
{
	if (virtual_size == s_size(stack_a))
	{
		if (get_item_index(stack_a, s_get_min_value(stack_a)) < s_size(stack_a) / 2)
			while (peek(stack_a) != s_get_min_value(stack_a))
				rra(stack_a);
		else
			while (peek(stack_a) != s_get_min_value(stack_a))
				ra(stack_a);
	}
	else
		rev_dsc_vs_safe(stack_a, stack_b, virtual_size, lowest);
}

void	rev_asc_vs(t_stack *stack_a, t_stack *stack_b, int virtual_size, int lowest)
{
	if (virtual_size == s_size(stack_b))
	{
		if (get_item_index(stack_b, s_get_max_value(stack_b)) < s_size(stack_b) / 2)
			while (peek(stack_b) != s_get_max_value(stack_b))
				rra(stack_b);
		else
			while (peek(stack_b) != s_get_max_value(stack_b))
				ra(stack_b);
	}
	else
		rev_asc_vs_safe(stack_a, stack_b, virtual_size, lowest);
}

int	try_reverse_a(t_stack *stack_a, t_stack *stack_b, int virtual_size)
{
	int	lowest_index;
	int	lowest;
	int	i;

	if (is_empty(stack_a))
		return (0);
	lowest = s_get_min_value(stack_a);
	while (get_item_index(stack_a, lowest) < s_size(stack_a) - virtual_size)
		lowest = s_next_value(stack_a, lowest + 1);
	//printf("Lowest\n");
	lowest_index = get_item_index(stack_a, lowest);
	i = lowest_index + 1;
	while (i < s_top(stack_a) && s_get(stack_a, i) > s_get(stack_a, i + 1))
		i++;
	//printf("first\n");
	if (i < s_top(stack_a))
		return (0);
	i = s_size(stack_a) - virtual_size;
	while (i < lowest_index && s_get(stack_a, i) > s_get(stack_a, i + 1))
		i++;
	//printf("second\n");
	if (i < lowest_index)
		return (0);
	if (peek(stack_a) < s_get(stack_a, s_size(stack_a) - virtual_size))
		return (0);
	rev_dsc_vs(stack_a, stack_b, virtual_size, lowest);
	return (1);
}

int	try_reverse_b(t_stack *stack_a, t_stack *stack_b, int virtual_size)
{
	int	lowest_index;
	int	lowest;
	int	i;

	if (is_empty(stack_b))
		return (0);
	lowest = s_get_min_value(stack_b);
	while (get_item_index(stack_b, lowest) < s_size(stack_b) - virtual_size)
		lowest = s_next_value(stack_b, lowest + 1);
	//printf("Lowest\n");
	lowest_index = get_item_index(stack_b, lowest);
	i = lowest_index;
	while (i < s_top(stack_b) && s_get(stack_b, i) < s_get(stack_b, i + 1))
		i++;
	//printf("first\n");
	if (i < s_top(stack_b))
		return (0);
	i = s_size(stack_b) - virtual_size;
	while (i < lowest_index && s_get(stack_b, i) < s_get(stack_b, i + 1))
		i++;
	//printf("second\n");
	if (i < lowest_index)
		return (0);
	if (peek(stack_b) > s_get(stack_b, s_size(stack_b) - virtual_size))
		return (0);
	rev_asc_vs(stack_a, stack_b, virtual_size, lowest);
	return (1);
}

void	half_sort(t_stack *stack_a, t_stack *stack_b, int virtual_size, int tabs)
{
	(void)stack_b;
	int	median;
	int	i;

#ifdef DEBUG
	for (int i = 0; i < tabs; i++)
			printf("	");
	printf("HalfSort() -%d-\n", virtual_size);
	for (int i = 0; i < tabs; i++)
		printf("	");
	stack_print(stack_a, virtual_size);
	for (int i = 0; i < tabs; i++)
		printf("	");
	stack_print(stack_b, virtual_size);
#endif

	if (!ft_strncmp(stack_a->name, "A", 1) && is_vs_sorted_dsc(stack_a, virtual_size))
		return ;
	if (!ft_strncmp(stack_a->name, "B", 1) && is_vs_sorted_asc(stack_a, virtual_size))
		return ;

#if 0
	if (!ft_strncmp(stack_a->name, "A", 1) && try_reverse_a(stack_a, stack_b, virtual_size))
		return ;
	if (!ft_strncmp(stack_a->name, "V", 1) && try_reverse_b(stack_a, stack_b, virtual_size))
		return ;
#endif

	if (virtual_size >= 2)
	{
#ifdef DEBUG
		for (int i = 0; i < tabs; i++)
			printf("	");
		printf("Splitting\n");
		for (int i = 0; i < tabs; i++)
			printf("	");
		stack_print(stack_a, virtual_size);
		for (int i = 0; i < tabs; i++)
			printf("	");
		stack_print(stack_b, virtual_size);
		getchar();
#endif
		median = find_median(stack_a, virtual_size);
#ifdef DEBUG
		for (int i = 0; i < tabs; i++)
			printf("	");
		printf("Median : %d\n", median);
		getchar();
#endif
		if (virtual_size > 2)
			send_low_to_stack(stack_a, stack_b, median, virtual_size);
		else
			swap_tops(stack_a, stack_b, virtual_size, 0);
		if (virtual_size / 2 + virtual_size % 2 <= 2)
			swap_tops(stack_a, stack_b, virtual_size / 2, virtual_size / 2 + virtual_size % 2);
		else
		{
			half_sort(stack_b, stack_a, virtual_size / 2 + virtual_size % 2, tabs + 1);
			if (virtual_size / 2 + virtual_size % 2 > 2)
				half_sort(stack_a, stack_b, virtual_size / 2, tabs + 1);
		}
	}
#ifdef DEBUG
	for (int i = 0; i < tabs; i++)
		printf("	");
	stack_print(stack_a, virtual_size);
	for (int i = 0; i < tabs; i++)
		printf("	");
	stack_print(stack_b, virtual_size);
#endif
	if (virtual_size <= 2 || is_empty(stack_b))
		return ;
	if (!ft_strncmp(stack_a->name, "B", 1))
	{
		if (s_size(stack_a) > virtual_size)
		{
			i = 0;
			while (i++ < virtual_size / 2)
				ra(stack_a);
		}
		i = 0;
		while (i++ < virtual_size / 2 + virtual_size % 2)
			pa(stack_a, stack_b);
		i = 0;
		while (i++ < virtual_size / 2)
			rra(stack_a);
	}
	else
	{
		i = 0;
		while (i++ < virtual_size / 2 + virtual_size % 2)
			pa(stack_a, stack_b);
	}
#ifdef DEBUG
	for (int i = 0; i < tabs; i++)
		printf("	");
	stack_print(stack_a, virtual_size);
	for (int i = 0; i < tabs; i++)
		printf("	");
	stack_print(stack_b, virtual_size);
	for (int i = 0; i < tabs; i++)
		printf("	");
	printf("Finish() -%d-\n", virtual_size);
#endif
}

void	new_and_improved_sort(t_stack *stack_a, t_stack *stack_b)
{
	half_sort(stack_a, stack_b, s_size(stack_a), 0);
}

int	need_to_sort(t_stack *stack_a)
{
	if (s_size(stack_a) < 2)
		return (0);
	if (is_stack_sorted_dsc(stack_a))
		return (0);
	if (s_size(stack_a) == 2)
	{
		sa(stack_a);
		return (0);
	}
	return (1);
}