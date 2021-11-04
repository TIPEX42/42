/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:54:40 by njennes           #+#    #+#             */
/*   Updated: 2021/08/17 14:55:37 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_init_params(int **params, char **argv, int size);
void	ft_create_tab(int **tab, int size);
int		ft_check_column(int **tab, int col, int p[2], int size);
int		ft_check_view_left(int *tab, int nb);
int		ft_check_view_right(int *tab, int nb);
int		ft_check_params(int argc, char **argv, int *size);

//Prints the grid to the screen
void	ft_show_tab(int **tab, int size)
{
	char	c[2];
	int		i;
	int		j;

	i = 0;
	j = 0;
	c[1] = ' ';
	while (i < size)
	{
		while (j < size)
		{
			c[0] = tab[i][j] + 48;
			write(1, c, 2);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

//Checks all grid for match
int	ft_check_grid(int **tab, int **params, int size)
{
	int	i;
	int	p[2];

	i = 0;
	while (i < size)
	{
		p[0] = params[0][i];
		p[1] = params[2][i];
		if (!ft_check_column(tab, i, p, size))
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (!ft_check_view_left(tab[i], params[1][i]))
			return (0);
		if (!ft_check_view_right(tab[i], params[3][i]))
			return (0);
		i++;
	}
	return (1);
}

int	**ft_allocate_tab(int x, int y)
{
	int **tab;
	int	i;

	tab = malloc(y * 4);
	i = 0;
	while (i < y)
	{
		tab[i] = malloc(x * 4);
		i++;
	}
	return (tab);
}

void	ft_increment(int **tab, int x, int y, int size)
{
	tab[x][y]++;
	if (tab[x][y] > size)
	{
		tab[x][y] = 1;
		if (y < size - 1)
		{
			ft_increment(tab, x, y + 1, size);
		}
		else
		{
			ft_increment(tab, x + 1, 0, size);
		}
	}
}

//Main loop that check all possibilities for match
int	ft_solve(int **tab, int **params, int size)
{
	while (!ft_check_grid(tab, params, size))
	{
		if (tab[size - 1][size - 1] < size)
		{
			ft_increment(tab, 0, 0, size);
		}
	}
	return (1);
}

void	ft_free(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

//Main function
//takes in parameters
//creates the grid of numbers
//solve the grid for given parameters
int	main(int argc, char **argv)
{
	int	**params;
	int	**tab;
	int	size;

	if (!ft_check_params(argc, argv, &size))
	{
		write(1, "Error\n", 7);
		return (0);
	}
	params = ft_allocate_tab(size, size);
	ft_init_params(params, argv, size);
	tab = ft_allocate_tab(size, size);
	ft_create_tab(tab, size);
	if (ft_solve(tab, params, size))
		ft_show_tab(tab, size);
	ft_free(params, size);
	ft_free(tab, size);
}
