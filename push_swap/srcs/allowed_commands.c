/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:41:31 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 14:41:31 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack)
{
	swap(stack);
	if (!ft_strncmp(stack->name, "A", 1))
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	sb(t_stack *stack)
{
	swap(stack);
	if (!ft_strncmp(stack->name, "A", 1))
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, pop(stack_b));
	if (!ft_strncmp(stack_a->name, "A", 1))
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, pop(stack_a));
	if (!ft_strncmp(stack_b->name, "A", 1))
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}
