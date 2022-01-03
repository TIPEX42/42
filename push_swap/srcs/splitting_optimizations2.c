/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting_optimizations2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:52:02 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 14:52:10 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_top(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
		sa(stack_a);
	ra(stack_a);
	ra(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
}

void	case_mid(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	pb(stack_a, stack_b);
	if (peek(stack_a) < bpeek(stack_a))
	{
		rra(stack_a);
		sa(stack_a);
		ra(stack_a);
	}
	ra(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
}

void	case_bot(t_stack *stack_a)
{
	sa(stack_a);
	ra(stack_a);
	ra(stack_a);
	ra(stack_a);
}

void	optimize_sort_3_a_safe(t_stack *sta, t_stack *stb, t_stack *ps)
{
	if (peek(ps) == 3)
	{
		if (s_get_max(sta, peek(ps)) == peek(sta))
			case_top(sta, stb);
		else if (s_get_max(sta, peek(ps)) == s_get(sta, s_top(sta) - 1))
			case_mid(sta, stb);
		else if (peek(sta) > s_get(sta, s_top(sta) - 1))
			case_bot(sta);
		pop(ps);
		return ;
	}
	if (peek(sta) > s_get(sta, s_top(sta) - 1))
		sa(sta);
	ra(sta);
	ra(sta);
	pop(ps);
}
