#include "libft.h"

int		atoi(const char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (ft_isdigit(str[i]) && str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}