/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting_optimizations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:41:12 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 14:51:43 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	optimize_3_a(t_stack *sta, t_stack *partitions)
{
	if (peek(partitions) <= 2)
		return ;
	if (peek(partitions) != s_size(sta))
		return ;
	if (peek(sta) == s_get_max(sta, s_size(sta)))
		ra(sta);
	if (s_get(sta, s_top(sta) - 1) == s_get_max(sta, s_size(sta)))
		rra(sta);
}

void	optimize_3_b(t_stack *stb)
{
	if (s_size(stb) <= 2)
		return ;
	if (peek(stb) == s_get_min(stb, s_size(stb)))
		rb(stb);
	if (s_get(stb, s_top(stb) - 1) == s_get_min(stb, s_size(stb)))
		rrb(stb);
}

void	optimize_sort_3(t_stack *sta, t_stack *stb, t_stack *partitions)
{
	optimize_3_a(sta, partitions);
	optimize_3_b(stb);
	if (s_size(stb) >= 2 && \
		peek(stb) < s_get(stb, s_top(stb) - 1) && \
		peek(sta) > s_get(sta, s_top(sta) - 1))
		ss(sta, stb);
	else if (peek(stb) < s_get(stb, s_top(stb) - 1))
		sb(stb);
	else if (peek(sta) > s_get(sta, s_top(sta) - 1))
		sa(sta);
	pop(partitions);
}

void	optimize_sort_3_a(t_stack *sta, t_stack *partitions)
{
	if (peek(partitions) <= 2)
		return ;
	if (peek(partitions) != s_size(sta))
		return ;
	if (peek(sta) == s_get_max(sta, s_size(sta)))
		ra(sta);
	if (s_get(sta, s_top(sta) - 1) == s_get_max(sta, s_size(sta)))
		rra(sta);
	if (peek(sta) > s_get(sta, s_top(sta) - 1))
		sa(sta);
	pop(partitions);
}

void	optimize_sort_3_b(t_stack *stb)
{
	if (s_size(stb) <= 2)
		return ;
	if (peek(stb) == s_get_min(stb, s_size(stb)))
		rb(stb);
	if (s_get(stb, s_top(stb) - 1) == s_get_min(stb, s_size(stb)))
		rrb(stb);
	if (peek(stb) < s_get(stb, s_top(stb) - 1))
		sb(stb);
}
