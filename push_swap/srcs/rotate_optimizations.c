/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_optimizations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:41:13 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 14:41:19 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	worth_rotating_a(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int index_min;
	int index_max;

	if (is_stack_sorted_dsc(stack_a, s_size(stack_a)) || !is_empty(stack_b))
		return (0);
	index_min = s_get_index(stack_a, s_get_min(stack_a, s_size(stack_a)));
	index_max = s_get_index(stack_a, s_get_max(stack_a, s_size(stack_a)));
	if (index_min == index_max - 1)
	{
		i = index_max;
		while (i < s_top(stack_a) && s_get(stack_a, i) > s_get(stack_a, i + 1))
			i++;
		if (i != s_top(stack_a))
			return (0);
		if (peek(stack_a) <= bpeek(stack_a))
			return (0);
		i = 0;
		while (i < index_min && s_get(stack_a, i) > s_get(stack_a, i + 1))
			i++;
		if (i != index_min)
			return (0);
		if (index_min < s_size(stack_a) / 2)
			return (2);
		return (1);
	}
	return (0);
}

int	try_rotate(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{
	if (!s_size(partitions))
		return(1);
	if (s_get(stack_a, s_top(stack_a) - 1) == s_get_min(stack_a, s_sum(partitions)))
	{
		sa(stack_a);
		rotate_already_sorted(stack_a, partitions);
		return (try_rotate(stack_a, stack_b, partitions));
	}
	if (worth_rotating_a(stack_a, stack_b) == 1)
	{
		while (!is_stack_sorted_dsc(stack_a, s_size(stack_a)))
			ra(stack_a);
		return (1);
	}
	if (worth_rotating_a(stack_a, stack_b) == 2)
	{
		while (!is_stack_sorted_dsc(stack_a, s_size(stack_a)))
			rra(stack_a);
		return (1);
	}
	return (0);
}

void	rotate_already_sorted(t_stack *stack_a, t_stack *partitions)
{
#ifdef DEBUG
	if (peek(stack_a) == s_get_min(stack_a, peek(partitions)))
		printf("Rotating already sorted\n");
#endif
	if (s_size(stack_a) <= 3)
		return ;
	while (s_size(partitions) && peek(stack_a) == s_get_min(stack_a, peek(partitions)))
	{
		ra(stack_a);
		partitions->items[s_top(partitions)]--;
		if (!peek(partitions))
			pop(partitions);
	}
}
