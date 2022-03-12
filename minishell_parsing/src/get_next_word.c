#include "libft.h"
#include "parsing.h"

t_err_or_charptr	append_chars(char **word, t_parser *parser);

char	*get_next_word(char *str)
{
	t_err_or_charptr	result;
	t_parser			parser;
	char				*word;

	parser.i = 0;
	parser.str = str;
	word = gc_strdup(get_gc(), "");
	while (parser.str[parser.i])
	{
		result = append_chars(&word, &parser);
		if (result.error)
		{
			gc_free(get_gc(), word);
		}
	}
	return (parser.str);
}

t_err_or_charptr	append_chars(char **word, t_parser *parser)
{
	t_err_or_charptr	result;

	result.result = NULL;
	result.error = NULL;
}
