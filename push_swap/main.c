#include "push_swap.h"

void	print_error_and_exit();

int main(int argc, char **argv)
{
	check_args(argc, argv);
	return (0);
}

void	print_error_and_exit()
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}