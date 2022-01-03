/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allowed_commands2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:41:29 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 14:41:29 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack)
{
	rotate(stack);
	if (!ft_strncmp(stack->name, "A", 1))
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	rb(t_stack *stack)
{
	rotate(stack);
	if (!ft_strncmp(stack->name, "A", 1))
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
