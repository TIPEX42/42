#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

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

#endif