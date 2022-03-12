#include "libft.h"
#include "parsing.h"

char	*get_next_word(char *str)
{
	size_t		i;
	t_parser	parser;

	i = 0;
	parser.str = gc_strdup(get_gc(), "");
	while (str[i])
	{
		if (str[i] == '"')
			parser.str = gc_strjoin(get_gc(), parser.str, get_double_quotes(&parser), FREE_BOTH);
		else if (str[i] == '\'')
			parser.str = gc_strjoin(get_gc(), parser.str, get_single_quotes(&parser), FREE_BOTH);
		else if (str[i] == '$')
			parser.str = gc_strjoin(get_gc(), parser.str, get_env_var_first_word(&parser), FREE_BOTH);
		else
			parser.str = gc_strappend(get_gc(), parser.str, parser.str[parser.i++]);
	}
	return (parser.str);
}
