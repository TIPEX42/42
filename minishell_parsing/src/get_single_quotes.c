#include "libft.h"
#include "parsing.h"

char	*get_single_quotes(t_parser *parser)
{
	char	*str_out;
	size_t	start;

	parser->i++;
	start = parser->i;
	while (parser->str[parser->i] && parser->str[parser->i] != '\'')
		parser->i++;
	str_out = gc_substr(get_gc(), parser->str, start, parser->i - start);
	if (parser->str[parser->i])
		parser->i++;
	return (str_out);
}
