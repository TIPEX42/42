#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("file.txt", O_RDWR);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("Line : %s", line);
		free(line);
		line = get_next_line(fd);
	}
}