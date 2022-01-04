#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#include "get_next_line_bonus.h"

int main()
{
	//int fd = open("filetxt", O_RDONLY);
	//char *line = get_next_line(fd);
	//getchar();
	//free(line);

	static char *test[1000000];
	getchar();
	char *lol;
	for (long i = 0; i < 1000000; i++)
		test[i] = malloc(5000000);
	getchar();
}