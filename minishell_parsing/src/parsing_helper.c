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

int	contains_open_spaces(char *str)
{
	char	quote;
	size_t	i;

	quote = 0;
	i = 0;
	while (str[i])
	{
		if (!quote && str[i] == '"')
			quote = '"';
		else if (quote == '"' && str[i] == '"')
			quote = 0;
		else if (!quote && str[i] == '\'')
			quote = '\'';
		else if (quote == '\'' && str[i] == '\'')
			quote = 0;
		if (!quote && ft_isspace(str[i]))
			return ((int)i);
		i++;
	}
	return (0);
}
