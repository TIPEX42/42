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

void	please_work_sort(t_stack *stack_a, t_stack *stack_b, t_stack *partitions)
{
	if (s_size(stack_a) <= 1)
		return ;
	if (try_rotate(stack_a, stack_b, partitions))
		return ;
	rotate_already_sorted(stack_a, partitions);
	while (!is_stack_sorted_dsc(stack_a, s_size(stack_a)) || !is_empty(stack_b))
	{
#ifdef DEBUG
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	stack_print(partitions, 0);
	getchar();
#endif
		if (try_rotate(stack_a, stack_b, partitions))
			return ;
		if (is_stack_sorted_dsc(stack_a, peek(partitions)))
		{
#ifdef DEBUG
	printf("Push sorted partition\n");
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	stack_print(partitions, 0);
	getchar();
#endif
			while (peek(partitions))
			{
				ra(stack_a);
				partitions->items[s_top(partitions)]--;
			}
			pop(partitions);
		}
		else
		{
#ifdef DEBUG
	printf("Push low\n");
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	stack_print(partitions, 0);
	getchar();
#endif
			rotate_already_sorted(stack_a, partitions);
			s_push_low(stack_a, stack_b, partitions);
			while (!is_empty(stack_b))
			{
#ifdef DEBUG
	printf("Push high\n");
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
	getchar();
#endif
				s_push_high(stack_a, stack_b, partitions);
			}
		}
	}
}

int main(int argc, char **argv)
{
	t_params	params;
	t_stack		*partitions;
	t_stack		*stack_a;
	t_stack		*stack_b;

	params = check_args(argc, argv);
	stack_a = create_stack(params.size, "A");
	if (!stack_a)
		print_error_and_exit();
	stack_b = create_stack(params.size, "B");
	if (!stack_b)
	{
		stack_destroy(stack_a);
		print_error_and_exit();
	}
	partitions = create_stack(params.size, "P");
	if (!partitions)
	{
		stack_destroy(stack_a);
		stack_destroy(stack_b);
		print_error_and_exit();
	}
	populate_stack(stack_a, params);
	push(partitions, params.size);
#ifdef DEBUG
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
#endif
	please_work_sort(stack_a, stack_b, partitions);

#ifdef DEBUG
	stack_print(stack_a, 0);
	stack_print(stack_b, 0);
#endif

	stack_destroy(stack_a);
	stack_destroy(stack_b);
	return (0);
}

void	print_error_and_exit()
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}
