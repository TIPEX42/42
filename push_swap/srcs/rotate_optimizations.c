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

int	worth_rotating_a(t_stack *sta, t_stack *stb)
{
	int	i;
	int	index_min;
	int	index_max;

	if (is_stack_sorted_dsc(sta, s_size(sta)) || !is_empty(stb))
		return (0);
	index_min = s_get_index(sta, s_get_min(sta, s_size(sta)));
	index_max = s_get_index(sta, s_get_max(sta, s_size(sta)));
	if (index_min == index_max - 1)
	{
		i = index_max;
		while (i < s_top(sta) && s_get(sta, i) > s_get(sta, i + 1))
			i++;
		if (i != s_top(sta) || peek(sta) <= bpeek(sta))
			return (0);
		i = 0;
		while (i < index_min && s_get(sta, i) > s_get(sta, i + 1))
			i++;
		if (i != index_min)
			return (0);
		if (index_min < s_size(sta) / 2)
			return (2);
		return (1);
	}
	return (0);
}

int	try_rotate(t_stack *sta, t_stack *stb, t_stack *partitions)
{
	if (!s_size(partitions))
		return (1);
	if (s_get(sta, s_top(sta) - 1) == s_get_min(sta, s_sum(partitions)))
	{
		sa(sta);
		rotate_already_sorted(sta, partitions);
		return (try_rotate(sta, stb, partitions));
	}
	if (worth_rotating_a(sta, stb) == 1)
	{
		while (!is_stack_sorted_dsc(sta, s_size(sta)))
			ra(sta);
		return (1);
	}
	if (worth_rotating_a(sta, stb) == 2)
	{
		while (!is_stack_sorted_dsc(sta, s_size(sta)))
			rra(sta);
		return (1);
	}
	return (0);
}

void	rotate_already_sorted(t_stack *sta, t_stack *partitions)
{
	if (s_size(sta) <= 3)
		return ;
	while (s_size(partitions) && peek(sta) == s_get_min(sta, peek(partitions)))
	{
		ra(sta);
		partitions->items[s_top(partitions)]--;
		if (!peek(partitions))
			pop(partitions);
	}
}
