#include "push_swap.h"

void	print_error_and_exit();

int main(int argc, char **argv)
{
	check_args(argc, argv);
	t_stack *stackA = create_stack(10);
	stack_print(stackA);
	pop(stackA);
	stack_print(stackA);
	push(stackA, 10);
	push(stackA, 9);
	push(stackA, 8);
	push(stackA, 7);
	push(stackA, 6);
	push(stackA, 5);
	push(stackA, 4);
	push(stackA, 3);
	push(stackA, 2);
	push(stackA, 1);
	stack_print(stackA);

	push(stackA, 22);
	stack_print(stackA);

	rotate(stackA);
	stack_print(stackA);
	rotate(stackA);
	stack_print(stackA);
	rotate(stackA);
	stack_print(stackA);
	rotate(stackA);
	stack_print(stackA);
	rotate(stackA);
	stack_print(stackA);
	rotate(stackA);
	stack_print(stackA);
	rotate(stackA);
	stack_print(stackA);
	rotate(stackA);
	stack_print(stackA);
	rotate(stackA);
	stack_print(stackA);
	rotate(stackA);
	stack_print(stackA);

	reverse_rotate(stackA);
	stack_print(stackA);
	reverse_rotate(stackA);
	stack_print(stackA);
	reverse_rotate(stackA);
	stack_print(stackA);
	reverse_rotate(stackA);
	stack_print(stackA);
	reverse_rotate(stackA);
	stack_print(stackA);
	reverse_rotate(stackA);
	stack_print(stackA);
	reverse_rotate(stackA);
	stack_print(stackA);
	reverse_rotate(stackA);
	stack_print(stackA);
	reverse_rotate(stackA);
	stack_print(stackA);
	reverse_rotate(stackA);
	stack_print(stackA);

	swap(stackA);
	stack_print(stackA);
	swap(stackA);
	stack_print(stackA);
	return (0);
}

void	print_error_and_exit()
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}