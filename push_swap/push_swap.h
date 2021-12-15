#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>

#define DEBUG

typedef struct	s_stack
{
	int		size;
	int		top;
	int		*items;
	char	*name;
} t_stack;

//main.c
void	print_error_and_exit();
int		s_get_max_value(t_stack *stack);
int		s_get_min_value(t_stack *stack);
int		get_item_index(t_stack *stack, int item);
int		s_next_value(t_stack *stack, int value);
int		s_last_value(t_stack *stack, int value);

//checking.c
void	check_args(int argc, char **argv);

//stack.c
t_stack	*create_stack(int capacity, char *name);
void	stack_print(t_stack *stack, int virtual_size);
void	stack_destroy(t_stack *stack);

//stackCommands.c
void	push(t_stack *stack, int item);
int		pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

//stack_commands2.c
int		peek(t_stack *stack);
int		bpeek(t_stack *stack);
int		is_empty(t_stack *stack);

//stack_commands3.c
int		s_top(t_stack *stack);
int		s_get(t_stack *stack, int index);
int		s_size(t_stack *stack);

//stack_commands4.c
int		is_stack_sorted_asc(t_stack *stack, int part);
int		is_stack_sorted_dsc(t_stack *stack, int part);

//allowed_commands.c
void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

//allowed_commands2.c
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);


//allowed_commands3.c
void	rra(t_stack *stack);
void	rrb(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

//insert.c
void	insert_top_top(t_stack *stack_a, t_stack *stack_b);
void	insert_top_bot(t_stack *stack_a, t_stack *stack_b);
void	insert_bot_top(t_stack *stack_a, t_stack *stack_b);
void	insert_bot_bot(t_stack *stack_a, t_stack *stack_b);

//costs.c
int		get_cost_top_top(t_stack *stack_a, t_stack *stack_b);
int		get_cost_top_bot(t_stack *stack_a, t_stack *stack_b);
int		get_cost_bot_top(t_stack *stack_a, t_stack *stack_b);
int		get_cost_bot_bot(t_stack *stack_a, t_stack *stack_b);
int		get_best_cost(t_stack *stack_a, t_stack *stack_b);

#endif