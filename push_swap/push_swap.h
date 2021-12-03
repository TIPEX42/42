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
void	stack_print(const char *str, t_stack *stack);
void	stack_destroy(t_stack *stack);

//stackCommands.c
void	push(t_stack *stack, int item);
int		pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

//stack_commands2.c
void	stack_reverse(t_stack *stack);
int		is_stack_sorted_dsc(t_stack *stack);
int		is_stack_sorted_dsc(t_stack *stack);

//allowed_commands.c
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack, int value);
void	pb(t_stack *stack, int value);

//allowed_commands2.c
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);


//allowed_commands3.c
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif