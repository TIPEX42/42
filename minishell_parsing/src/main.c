#include "libft.h"
#include "parsing.h"

t_gc gc;

t_gc *get_gc()
{
	return (&gc);
}

int main(int argc, char **argv)
{
	gc_init(get_gc(), NULL, NULL);
	t_command_batch batch = parse_input(argv[1]);
	printf("Command count : %zu\n", batch.count);
	for (int i = 0; i < batch.count; i++)
		printf("[%d]: batch.is_piping: %d\n", i, batch.commands[i].is_piping);
}
