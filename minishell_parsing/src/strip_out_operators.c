#include "parsing.h"

int				is_redirection(char *str);

static t_parser	populate_parser(char *str, t_redir *redirs);
static char		*skip_redir_file(char *str, t_redir *redirs);
static char		*append_quotes(char *str, char **parser_str);

t_parser	*strip_out_operators(char *input, t_command_batch *batch)
{
	size_t		i;
	t_parser	*parsers;

	parsers = gc_calloc(get_gc(), batch->count, sizeof (t_parser));
	i = 0;
	while (input)
	{
		parsers[i] = populate_parser(input, batch->commands[i].redirections);
		input = ft_strchr(input, '|');
		if (input)
			input ++;
		i++;
	}
	return (parsers);
}

static t_parser	populate_parser(char *str, t_redir *redirs)
{
	t_parser	parser;

	parser.str = gc_strdup(get_gc(), "");
	parser.i = 0;
	while (*str && *str != '|')
	{
		if (is_redirection_char(*str))
		{
			if (!is_redirection(str))
			{
				while (is_redirection_char(*str))
					parser.str = gc_strappend(get_gc(), parser.str, *str++);
			}
			else
			{
				while (is_redirection_char(*str))
					str++;
				while (ft_isspace(*str))
					str++;
				str = skip_redir_file(str, redirs);
			}
		}
		else
		{
			if (*str == '\'' || *str == '"')
				str = append_quotes(str, &parser.str);
			else
				parser.str = gc_strappend(get_gc(), parser.str, *str++);
		}
	}
	return (parser);
}

static char	*skip_redir_file(char *str, t_redir *redirs)
{
	size_t	i;
	size_t	file_len;

	i = 0;
	while (redirs[i].type)
	{
		file_len = ft_strlen(ft_strrchr(redirs[i].file, '/') + 1);
		if (ft_strncmp(str, ft_strrchr(redirs[i].file, '/') + 1, file_len) == 0)
		{
			str += file_len;
			break;
		}
		i++;
	}
	return (str);
}

static char	*append_quotes(char *str, char **parser_str)
{
	size_t	i;
	char	*sub_str;

	i = skip_quotes(str);
	sub_str = gc_substr(get_gc(), str, 0, i);
	*parser_str = gc_strjoin(get_gc(), *parser_str, sub_str, FREE_BOTH);
	return (str + i);
}
