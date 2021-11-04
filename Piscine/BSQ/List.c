#include "header.h"

void	ft_put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

long	ft_list_error(char *error)
{
	ft_put_str(error);
	return (0);
}

void	ft_init_list_zeros(int **list, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			list[i + 1][j] = 0;
			j++;
		}
		i++;
	}
}

int	**ft_list_create(int width, int height)
{
	int	i;
	int	**list;

	list = malloc((width + 1) * sizeof(int *));
	if (!list)
		return ((void *)ft_list_error("Error initializing list \n"));
	list[0] = malloc(2 * sizeof(int));
	if (!list[0])
		return ((void *)ft_list_error("Error initializing list \n"));
	list[0][0] = width;
	list[0][1] = height;
	i = 0;
	while (i < width)
	{
		list[i + 1] = malloc(height * sizeof(int));
		if (!list[i + 1])
			return ((void *)ft_list_error("Error initializing list \n"));
		i++;
	}
	ft_init_list_zeros(list, width, height);
	return (list);
}

void	ft_list_free(int **list)
{
	int	i;

	i = 0;
	while (i < list[0][0])
	{
		free(list[i]);
		i++;
	}
	free(list);
}

int	**ft_list_push(int **list, int *buffer)
{
	int	i;
	int	j;
	int	**new_list;

	new_list = ft_list_create(list[0][0] + 1, list[0][1]);
	if (!new_list)
		return (0);
	i = 0;
	if (list[0][0] != 1)
	{
		while (i < list[0][0])
		{
			j = 0;
			while (j < list[0][1])
			{
				new_list[i + 1][j] = list[i + 1][j];
				j++;
			}
			i++;
		}
	}
	j = 0;
	while (j < list[0][1])
	{
		new_list[i + 1][j] = buffer[j];
		j++;
	}
	ft_list_free(list);
	return (new_list);
}

int	ft_list_get(int **list, int x, int y)
{
	if (x >= list[0][0])
		return (ft_list_error("Index x too large\n"));
	if (y >= list[0][1])
		return (ft_list_error("Index y too large\n"));
	if (x < 0)
		return (ft_list_error("Index x below 0\n"));
	if (y < 0)
		return (ft_list_error("Index y below 0\n"));
	return (list[x + 1][y]);
}

void	ft_list_set(int **list, int x, int y, int value)
{
	if (x >= list[0][0])
		ft_list_error("Index x too large\n");
	if (y >= list[0][1])
		ft_list_error("Index y too large\n");
	if (x < 0)
		ft_list_error("Index x below 0\n");
	if (y < 0)
		ft_list_error("Index y below 0\n");
	list[x + 1][y] = value;
}
