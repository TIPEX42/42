/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:34:45 by njennes           #+#    #+#             */
/*   Updated: 2021/12/10 12:34:35 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted_asc(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < s_top(stack))
	{
		if (stack->items[i] > stack->items[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_stack_sorted_dsc(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < s_top(stack))
	{
		if (stack->items[i] < stack->items[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_vs_sorted_asc(t_stack *stack, int virtual_stack)
{
	int	i;

	i = s_size(stack) - virtual_stack;
	while (i < s_top(stack))
	{
		if (stack->items[i] > stack->items[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_vs_sorted_dsc(t_stack *stack, int virtual_stack)
{
	int	i;

	i = s_size(stack) - virtual_stack;
	while (i < s_top(stack))
	{
		if (stack->items[i] < stack->items[i + 1])
			return (0);
		i++;
	}
	return (1);
}