#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int is_in(int *tab, int val)
{
	int i = 0;
	while (tab[i] != 0)
	{
		if (tab[i] == val)
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	srand(time(NULL) + atoi(argv[2]));
	int *tab = calloc((atoi(argv[1]) + 1), sizeof(int));

	int i = 0;
	int num = 0;
	while (i < atoi(argv[1]))
	{
		num = rand() % (atoi(argv[1]) * 2) + 1;
		while (is_in(tab, num))
			num = rand() % (atoi(argv[1]) * 2) + 1;
		tab[i] = num;
		i++;
	}

	for (int i = 0; tab[i]; i++)
	{
		printf("%d ", tab[i]);
	}
	
	free(tab);
}