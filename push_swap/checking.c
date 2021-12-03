#include "push_swap.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			print_error_and_exit();
		i++;
	}
}