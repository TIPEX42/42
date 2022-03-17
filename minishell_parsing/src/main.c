#include "libft.h"
#include "parsing.h"
#include "minishell.h"

t_gc gc;
t_app g_minishell;

t_gc *get_gc()
{
	return (&gc);
}

char	*token_to_str(int token)
{
	switch (token)
	{
		case TOKEN_REDIR_OUT:
			return ("TOKEN_REDIR_OUT");
		case TOKEN_REDIR_IN:
			return ("TOKEN_REDIR_IN");
		case TOKEN_REDIR_OUT_APPEND:
			return ("TOKEN_REDIR_OUT_APPEND");
		case TOKEN_REDIR_HEREDOC:
			return ("TOKEN_REDIR_HEREDOC");
		case TOKEN_ARG:
			return ("TOKEN_ARG");
		case TOKEN_COMMAND:
			return ("TOKEN_COMMAND");
		case TOKEN_EMPTY:
			return ("TOKEN_EMPTY");
		case TOKEN_PIPE:
			return ("TOKEN_PIPE");
		case TOKEN_FILE:
			return ("TOKEN_FILE");
		default:
			return ("UNKNOWN_TOKEN_TYPE");
	}
}

int main(int argc, char **argv)
{
	gc_init(get_gc(), NULL, NULL);
	t_command_batch	batch = {0};
	batch = parse_input(argv[1]);
	for (int i = 0; i < batch.count; i++)
	{
		printf("is redirecting: %d\n", batch.commands[i].is_redirecting);
		for (int j = 0; batch.commands[i].redirections[j].type; j++)
		{
			printf("Command [%d]: Redir [%d]: type: %s file: %s\n", i, j, token_to_str(batch.commands[i].redirections[j].type), batch.commands[i].redirections[j].file);
		}
	}
}
