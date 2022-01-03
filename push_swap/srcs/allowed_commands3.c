/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_commands3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:41:27 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 14:41:27 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *stack)
{
	reverse_rotate(stack);
	if (!ft_strncmp(stack->name, "A", 1))
		printf("rra\n");
	else
		printf("rrb\n");
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	if (!ft_strncmp(stack->name, "A", 1))
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
