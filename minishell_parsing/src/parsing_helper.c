#include "parsing.h"

int	is_operator_char(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}

char	*skip_spaces(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}
