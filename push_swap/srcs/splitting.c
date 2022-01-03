/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:41:10 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 14:41:10 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_b_opti(t_stack *sta, t_stack *stb, t_stack *partitions, int median)
{
	if (peek(sta) < median)
	{
		pb(sta, stb);
		partitions->items[s_top(partitions)]--;
		return (0);
	}
	if (peek(partitions) == s_size(sta) && bpeek(sta) < median)
	{
		rra(sta);
		pb(sta, stb);
		partitions->items[s_top(partitions)]--;
		return (0);
	}
	ra(sta);
	return (1);
}

void	smart_rotate(t_stack *stack_a, int rotations)
{
	int	i;

	i = 0;
	if (rotations > s_size(stack_a) / 2)
	{
		while (i < s_size(stack_a) - rotations)
		{
			ra(stack_a);
			i++;
		}
		return ;
	}
	while (i < rotations)
	{
		rra(stack_a);
		i++;
	}
}

void	s_push_low(t_stack *sta, t_stack *stb, t_stack *partitions)
{
	int	rotations;
	int	median;

	if (s_size(sta) <= 3)
	{
		optimize_sort_3_a(sta, partitions);
		return ;
	}
	if (peek(partitions) <= 3)
	{
		optimize_sort_3_a_safe(sta, stb, partitions);
		return ;
	}
	median = s_get_median(sta, peek(partitions));
	rotations = 0;
	while (peek(partitions) - rotations > 0 && \
			s_get_min(sta, peek(partitions) - rotations) < median)
		rotations += push_b_opti(sta, stb, partitions, median);
	if (peek(partitions) == s_size(sta))
		return ;
	smart_rotate(sta, rotations);
}

void	push_a_opti(t_stack *sta, t_stack *stb, t_stack *partitions, int median)
{
	if (peek(stb) > median && bpeek(stb) >= median)
	{
		if (bpeek(stb) > peek(stb))
			rrb(stb);
		pa(sta, stb);
		partitions->items[s_top(partitions)]++;
	}
	else if (peek(stb) >= median)
	{
		pa(sta, stb);
		partitions->items[s_top(partitions)]++;
	}
	else if (bpeek(stb) >= median)
	{
		rrb(stb);
		pa(sta, stb);
		partitions->items[s_top(partitions)]++;
	}
	else
		rb(stb);
	return ;
}

void	s_push_high(t_stack *sta, t_stack *stb, t_stack *partitions)
{
	int	median;

	if (s_size(stb) == 1)
	{
		partitions->items[s_top(partitions)]++;
		pa(sta, stb);
		return ;
	}
	if (s_size(sta) <= 3 && s_size(stb) <= 3)
		optimize_sort_3(sta, stb, partitions);
	else if (s_size(sta) <= 3)
		optimize_sort_3_a(sta, partitions);
	else if (s_size(stb) <= 3)
		optimize_sort_3_b(stb);
	push(partitions, 0);
	median = s_get_median(stb, s_size(stb));
	while (s_get_max(stb, s_size(stb)) >= median)
		push_a_opti(sta, stb, partitions, median);
	if (peek(stb) >= median)
	{
		pa(sta, stb);
		partitions->items[s_top(partitions)]++;
	}
}
