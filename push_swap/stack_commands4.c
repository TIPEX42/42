/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_commands4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:34:45 by njennes           #+#    #+#             */
/*   Updated: 2021/12/15 14:28:43 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted_asc(t_stack *stack, int part)
{
	int	i;

	i = s_size(stack) - part;
	while (i < s_top(stack))
	{
		if (stack->items[i] > stack->items[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_stack_sorted_dsc(t_stack *stack, int part)
{
	int	i;

	i = s_size(stack) - part;
	while (i < s_top(stack))
	{
		if (stack->items[i] < stack->items[i + 1])
			return (0);
		i++;
	}
	return (1);
}
