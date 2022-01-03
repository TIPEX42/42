/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:41:05 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 14:41:05 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	peek(t_stack *stack)
{
	return (stack->items[stack->top - 1]);
}

int	bpeek(t_stack *stack)
{
	return (stack->items[0]);
}

int	s_get(t_stack *stack, int index)
{
	if (index > s_size(stack))
		return (stack->items[index - s_size(stack)]);
	return (stack->items[index]);
}

int	s_get_max(t_stack *stack, int part)
{
	int	max;
	int	i;

	i = s_size(stack) - part;
	max = s_get(stack, i);
	while (i < s_size(stack))
	{
		if (s_get(stack, i) > max)
			max = s_get(stack, i);
		i++;
	}
	return (max);
}

int	s_get_min(t_stack *stack, int part)
{
	int	min;
	int	i;

	i = s_size(stack) - part;
	min = s_get(stack, i);
	while (i < s_size(stack))
	{
		if (s_get(stack, i) < min)
			min = s_get(stack, i);
		i++;
	}
	return (min);
}
