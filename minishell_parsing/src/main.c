#include "libft.h"
#include "parsing.h"
#include "minishell.h"

t_gc gc;
t_app g_minishell;

t_gc *get_gc()
{
	return (&gc);
}

int main(int argc, char **argv)
{
	gc_init(get_gc(), NULL, NULL);
	t_command_batch	batch = {0};
	batch = parse_input(argv[1]);
	printf("is redirecting: %d\n", batch.commands[0].is_redirecting);
	for (int i = 0; i < batch.count; i++)
	{
		for (int j = 0; batch.commands[i].redirections[j].type; j++)
		{
			printf("Command [%d]: Redir [%d]: type: %d file: %s\n", i, batch.commands[i].redirections[j].type, batch.commands[i].redirections[j].file);
		}
	}
}
