#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>

//#define DEBUG

typedef struct	s_stack
{
	int		size;
	int		top;
	int		*items;
	char	*name;
} t_stack;

//main.c
void	print_error_and_exit();
void	rotate_already_sorted(t_stack *stack_a, t_stack *partitions);

//checking.c
void	check_args(int argc, char **argv);

//stack.c
t_stack	*create_stack(int capacity, char *name);
void	populate_stack(t_stack *stack, int argc, char **argv);
void	stack_print(t_stack *stack, int virtual_size);
void	stack_destroy(t_stack *stack);

//stack_basics.c
void	push(t_stack *stack, int item);
int		pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

//stack_get.c
int		peek(t_stack *stack);
int		bpeek(t_stack *stack);
int		s_get(t_stack *stack, int index);
int		s_get_max(t_stack *stack, int part);
int		s_get_min(t_stack *stack, int part);

//stack_size.c
int		s_top(t_stack *stack);
int		is_empty(t_stack *stack);
int		s_size(t_stack *stack);

//stack_sorted.c
int		is_stack_sorted_asc(t_stack *stack, int part);
int		is_stack_sorted_dsc(t_stack *stack, int part);

//stack_sorting.c
int		s_get_median(t_stack *stack, int part);
int		s_get_last(t_stack *stack, int value, int part);
int		s_get_index(t_stack *stack, int item);

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

//splitting.c
void	s_push_high(t_stack *stack_a, t_stack *stack_b, t_stack *partitions);
void	s_push_low(t_stack *stack_a, t_stack *stack_b, t_stack *partitions);
void	push_a_opti(t_stack *stack_a, t_stack *stack_b, t_stack *partitions, int median);

//splitting_optimizations.c
void	optimize_sort_3_a_safe(t_stack *stack_a, t_stack *stack_b, t_stack *partitions);
void	optimize_sort_3_a(t_stack *stack, t_stack *partitions);
void	optimize_sort_3_b(t_stack *stack_b);

//rotate_optimizations.c
void	rotate_already_sorted(t_stack *stack_a, t_stack *partitions);
int		try_rotate(t_stack *stack_a, t_stack *stack_b);
int		worth_rotating_a(t_stack *stack_a, t_stack *stack_b);

#endif