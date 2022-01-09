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

void populate_tab_five(int *tab)
{
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	tab[3] = 4;
	tab[4] = 5;
}

int doubles(int *tab)
{
	int current;
	int i = 0;
	int j;

	while (i < 5)
	{
		j = i + 1;
		while (j < 5)
		{
			if (tab[i] == tab[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void next_comb(int *tab)
{
	tab[4]++;
	if (tab[4] > 5)
	{
		tab[3]++;
		if (tab[3] > 5)
		{
			tab[2]++;
			if (tab[2] > 5)
			{
				tab[1]++;
				if (tab[1] > 5)
				{
					tab[0]++;
					if (tab[0] > 5)
					{
						tab[0] = 1;
					}
					tab[1] = 1;
				}
				tab[2] = 1;
			}
			tab[3] = 1;
		}
		tab[4] = 1;
	}
	if (doubles(tab))
		next_comb(tab);
}

int five(char **argv)
{
	int *tab = calloc((atoi(argv[1]) + 1), sizeof(int));
	populate_tab_five(tab);
	int i = atoi(argv[2]);
	while (i)
	{
		next_comb(tab);
		i--;
	}

	for (int i = 0; tab[i]; i++)
	{
		printf("%d", tab[i]);
		if (tab[i + 1])
			printf(" ");
	}

	free(tab);
	return (0);
}

int main(int argc, char **argv)
{
	srand(time(NULL) + atoi(argv[2]));
	if (atoi(argv[1]) == 5)
		return (five(argv));
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
		printf("%d", tab[i]);
		if (tab[i + 1])
			printf(" ");
	}
	
	free(tab);
}