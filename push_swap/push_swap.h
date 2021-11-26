#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_stack
{
	int	size;
	int	top;
	int	*items;
} t_stack;

//main.c
void	print_error_and_exit();

//checking.c
void	check_args(int argc, char **argv);

//stack.c
t_stack	*create_stack(int capacity);
void	stack_print(t_stack *stack);
void	stack_destroy(t_stack *stack);

//stackCommands.c
void	push(t_stack *stack, int item);
int		pop(t_stack *stack, int item);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif