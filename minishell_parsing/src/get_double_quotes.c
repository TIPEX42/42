#include "libft.h"
#include "parsing.h"

char	*get_double_quotes(t_parser *parser)
{
	char	*str_out;
	size_t	start;

	parser->i++;
	start = parser->i;
	str_out = gc_strdup(get_gc(), "");
	while (parser->str[parser->i] && parser->str[parser->i] != '\'')
	{
		if (parser->str[parser->i] == '$')
			str_out = gc_strjoin(get_gc(), str_out, get_env_var_raw(parser), FREE_BOTH);
		else
			str_out = gc_strappend(get_gc(), str_out, parser->str[parser->i++]);
	}
	if (parser->str[parser->i])
		parser->i++;
	return (str_out);
}
