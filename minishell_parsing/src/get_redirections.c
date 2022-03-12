#include "libft.h"
#include "parsing.h"

static int		setup_redirections(char *str, t_command *command);
static size_t	get_redir_count(char *str);
static char		*get_redir_file(char *str);

int				get_redir_type(char *str);
int				is_redirection(char *str);

int	get_redirections(char *input, t_command_batch *batch)
{
	size_t	command_index;

	command_index = 0;
	while (command_index < batch->count)
	{
		if (!setup_redirections(input, &batch->commands[command_index]))
			return (0);
		input = ft_strchr(input, '|');
	}
}

static int	setup_redirections(char *str, t_command *command)
{
	size_t	i;
	size_t	redir_count;

	redir_count = get_redir_count(str);
	if (redir_count)
		command->is_redirecting = 1;
	command->redirections = gc_calloc(get_gc(), redir_count + 1, sizeof (t_redir));
	i = 0;
	while (i < redir_count)
	{
		if (is_redirection(&str[i]))
		{
			command->redirections[i].type = get_redir_type(&str[i]);
			while (str[i] == '>' || str[i] == '<')
				i++;
			command->redirections[i].file = get_redir_file(&str[i]);
		}
		else
		{
			while (str[i] == '>' || str[i] == '<')
				i++;
		}
		i++;
	}
	return (0);
}

static char	*get_redir_file(char *str)
{
	size_t	i;
	char	*file;

	str = skip_spaces(str);
	file = get_next_word(str);
}

static size_t	get_redir_count(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_redirection(&str[i]))
			count++;
		while (str[i] == '>' || str[i] == '<')
			i++;
		i++;
	}
	return (count);
}
