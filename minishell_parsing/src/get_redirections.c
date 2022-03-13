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
	printf("batch count :%d\n", (int)batch->count);
	printf("Input: %s\n", input);
	while (command_index < batch->count)
	{
		if (!setup_redirections(input, &batch->commands[command_index]))
			return (0);
		input = ft_strchr(input, '|');
		command_index++;
	}
	return (1);
}

static int	setup_redirections(char *str, t_command *command)
{
	size_t	i;
	size_t	redir_count;

	redir_count = get_redir_count(str);
	printf("redir count:%zu\n", redir_count);
	if (redir_count)
		command->is_redirecting = 1;
	command->redirections = gc_calloc(get_gc(), redir_count + 1, sizeof (t_redir));
	i = 0;
	while (str[i])
	{
		printf("REDIR\n");
		printf("%zu\n", i);
		if (is_redirection(&str[i]))
		{
			printf("found a redir\n");
			command->redirections[i].type = get_redir_type(&str[i]);
			while (str[i] == '>' || str[i] == '<')
				i++;
			command->redirections[i].file = get_redir_file(&str[i]);
			if (!command->redirections[i].file)
				return (0);
		}
		while (str[i] == '>' || str[i] == '<')
			i++;
		if (str[i])
			i++;
	}
	return (1);
}

static char	*get_redir_file(char *str)
{
	size_t				i;
	t_err_or_charptr	file;
	char				*filename;

	str = skip_spaces(str);
	file = get_next_word(str, 1);
	if (file.error)
		return (parsing_error(file.error));
	if (contains_open_spaces(file.result))
		return (error_ambiguous_redirection(str));
	if (ft_strlen(file.result) == 0)
		return (parsing_error("minishell: :No such file or directory"));
	if (!is_absolute_path(file.result))
		make_absolute_path(&file.result);
	filename = ft_strrchr(file.result, '/') + 1;
	filename[-2] = 0;
	if (!is_valid_path(file.result))
		return (parsing_error("minishell: :No such file or directory"));
	if (is_valid_path(file.result) == PATH_DIRECTORY)
		return (parsing_error("minishell: :Is a directory"));
	filename[-2] = '/';
	return (file.result);
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
		if (str[i])
			i++;
	}
	return (count);
}
