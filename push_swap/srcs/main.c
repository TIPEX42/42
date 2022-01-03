/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:41:23 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 14:41:23 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	please_work_sort(t_stack *sta, t_stack *stb, t_stack *pts)
{
	if (s_size(sta) <= 1 || try_rotate(sta, stb, pts))
		return ;
	rotate_already_sorted(sta, pts);
	while (!is_stack_sorted_dsc(sta, s_size(sta)) || !is_empty(stb))
	{
		if (try_rotate(sta, stb, pts))
			return ;
		if (is_stack_sorted_dsc(sta, peek(pts)))
		{
			while (peek(pts))
			{
				ra(sta);
				pts->items[s_top(pts)]--;
			}
			pop(pts);
		}
		else
		{
			rotate_already_sorted(sta, pts);
			s_push_low(sta, stb, pts);
			while (!is_empty(stb))
				s_push_high(sta, stb, pts);
		}
	}
}

void	init_stacks(t_stack **sta, t_stack **stb, t_stack **pts, t_params parm)
{
	*sta = create_stack(parm.size, "A");
	if (!*sta)
	{
		free(parm.values);
		print_error_and_exit();
	}
	*stb = create_stack(parm.size, "B");
	if (!*stb)
	{
		free(parm.values);
		stack_destroy(*sta);
		print_error_and_exit();
	}
	*pts = create_stack(parm.size, "P");
	if (!*pts)
	{
		free(parm.values);
		stack_destroy(*sta);
		stack_destroy(*stb);
		print_error_and_exit();
	}
	populate_stack(*sta, parm);
	push(*pts, parm.size);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_stack		*partitions;
	t_stack		*stack_a;
	t_stack		*stack_b;

	params = check_args(argc, argv);
	init_stacks(&stack_a, &stack_b, &partitions, params);
	please_work_sort(stack_a, stack_b, partitions);
	stack_destroy(stack_a);
	stack_destroy(stack_b);
	return (0);
}

void	print_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
