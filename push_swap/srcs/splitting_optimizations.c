/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting_optimizations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:41:12 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 14:41:12 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	optimize_sort_3_a_safe(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{
#ifdef DEBUG
	printf("Optimizing sort\n");
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	stack_print(partitions, 0);
	getchar();
#endif
	if (peek(partitions) == 3)
	{
		if (s_get_max(stack_a, peek(partitions)) == peek(stack_a))
		{
			pb(stack_a, stack_b);
			if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
				sa(stack_a);
			ra(stack_a);
			ra(stack_a);
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (s_get_max(stack_a, peek(partitions)) == s_get(stack_a, s_top(stack_a) - 1))
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
		else if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
		{
			sa(stack_a);
			ra(stack_a);
			ra(stack_a);
			ra(stack_a);
		}
		pop(partitions);
		return ;
	}
	if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
		sa(stack_a);
	ra(stack_a);
	ra(stack_a);
	pop(partitions);
}

void	optimize_3_a(t_stack *stack_a, t_stack *partitions)
{
	if (peek(partitions) <= 2)
		return ;
	if (peek(partitions) != s_size(stack_a))
		return ;
	if (peek(stack_a) == s_get_max(stack_a, s_size(stack_a)))
		ra(stack_a);
	if (s_get(stack_a, s_top(stack_a) - 1) == s_get_max(stack_a, s_size(stack_a)))
		rra(stack_a);
}

void	optimize_3_b(t_stack *stack_b)
{
	if (s_size(stack_b) <= 2)
		return ;
	if (peek(stack_b) == s_get_min(stack_b, s_size(stack_b)))
		rb(stack_b);
	if (s_get(stack_b, s_top(stack_b) - 1) == s_get_min(stack_b, s_size(stack_b)))
		rrb(stack_b);
}

void	optimize_sort_3(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{
	optimize_3_a(stack_a, partitions);
	optimize_3_b(stack_b);
	if (s_size(stack_b) >= 2 && \
		peek(stack_b) < s_get(stack_b, s_top(stack_b) - 1) && \
		peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
		ss(stack_a, stack_b);
	else if (peek(stack_b) < s_get(stack_b, s_top(stack_b) - 1))
		sb(stack_b);
	else if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
		sa(stack_a);
	pop(partitions);
}

void	optimize_sort_3_a(t_stack *stack_a, t_stack *partitions)
{
#ifdef DEBUG
	printf("Optimizing sort 3 a\n");
	stack_print(stack_a, 0);
	stack_print(partitions, 0);
	getchar();
#endif
	if (peek(partitions) <= 2)
		return ;
	if (peek(partitions) != s_size(stack_a))
		return ;
	if (peek(stack_a) == s_get_max(stack_a, s_size(stack_a)))
		ra(stack_a);
	if (s_get(stack_a, s_top(stack_a) - 1) == s_get_max(stack_a, s_size(stack_a)))
		rra(stack_a);
	if (peek(stack_a) > s_get(stack_a, s_top(stack_a) - 1))
		sa(stack_a);
	pop(partitions);
}

void	optimize_sort_3_b(t_stack *stack_b)
{
#ifdef DEBUG
	printf("Optimizing sort 3 b\n");
	stack_print(stack_b, 0);
	getchar();
#endif
	if (s_size(stack_b) <= 2)
		return ;
	if (peek(stack_b) == s_get_min(stack_b, s_size(stack_b)))
		rb(stack_b);
	if (s_get(stack_b, s_top(stack_b) - 1) == s_get_min(stack_b, s_size(stack_b)))
		rrb(stack_b);
	if (peek(stack_b) < s_get(stack_b, s_top(stack_b) - 1))
		sb(stack_b);
}