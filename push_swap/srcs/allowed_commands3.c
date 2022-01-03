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
	#ifndef NO_OUT
	if (!ft_strncmp(stack->name, "A", 1))
		printf("rra\n");
	else
		printf("rrb\n");
	#endif
}

void	rrb(t_stack *stack)
{
	reverse_rotate(stack);
	#ifndef NO_OUT
	if (!ft_strncmp(stack->name, "A", 1))
		printf("rra\n");
	else
		printf("rrb\n");
	#endif
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	#ifndef NO_OUT
	printf("rrr\n");
	#endif
}