/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:43:10 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 14:43:10 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*create_stack(int capacity, char *name)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = 0;
	new_stack->size = capacity;
	new_stack->items = malloc(capacity * sizeof(int));
	new_stack->name = name;
	if (!new_stack->items)
	{
		free(new_stack);
		return (NULL);
	}
	return (new_stack);
}

void	populate_stack(t_stack *stack, t_params params)
{
	int	i;

	i = params.size - 1;
	while (i >= 0)
	{
		push(stack, params.values[i]);
		i--;
	}
	free(params.values);
}

void	stack_destroy(t_stack *stack)
{
	free(stack->items);
	free(stack);
}
