#include "libft.h"

int main(int argc, char **argv)
{
	if (ft_valid_args(argc, argv, "%d"))
		ft_printf("V");
	else
		ft_printf("N");
}