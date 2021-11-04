/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:54:11 by njennes           #+#    #+#             */
/*   Updated: 2021/08/15 17:54:13 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_init_params(int params[4][4], char **argv);
void	ft_init_permutations(int permutations[4]);
void	ft_create_tab(int tab[4][4]);
int		ft_next_comb(int tab[4], int depth);
int		ft_check_column(int tab[4][4], int col, int nbup, int nbdown);
int		ft_check_view_left(int tab[4], int nb);
int		ft_check_view_right(int tab[4], int nb);
int		ft_check_params(int argc, char **argv);

//Prints the grid to the screen
void	ft_show_tab(int tab[4][4])
{
	char	c[2];
	int		i;
	int		j;

	i = 0;
	j = 0;
	c[1] = ' ';
	while (i < 4)
	{
		while (j < 4)
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
int	ft_check_grid(int tab[4][4], int params[4][4])
{
	if (!ft_check_column(tab, 0, params[0][0], params[2][0]))
		return (0);
	if (!ft_check_column(tab, 1, params[0][1], params[2][1]))
		return (0);
	if (!ft_check_column(tab, 2, params[0][2], params[2][2]))
		return (0);
	if (!ft_check_column(tab, 3, params[0][3], params[2][3]))
		return (0);
	if (!ft_check_view_left(tab[0], params[1][0]))
		return (0);
	if (!ft_check_view_right(tab[0], params[3][0]))
		return (0);
	if (!ft_check_view_left(tab[1], params[1][1]))
		return (0);
	if (!ft_check_view_right(tab[1], params[3][1]))
		return (0);
	if (!ft_check_view_left(tab[2], params[1][2]))
		return (0);
	if (!ft_check_view_right(tab[2], params[3][2]))
		return (0);
	if (!ft_check_view_left(tab[3], params[1][3]))
		return (0);
	if (!ft_check_view_right(tab[3], params[3][3]))
		return (0);
	return (1);
}

//Permutes one line and reset permutations of earlier lines
void	ft_permute(int tab[4][4], int permutations[4], int line)
{
	int	i;

	i = 0;
	ft_next_comb(tab[line], 0);
	while (i < line)
	{
		permutations[i] = 0;
		i++;
	}
	permutations[line]++;
}

//Main loop that check all possibilities for match
int	ft_solve(int tab[4][4], int params[4][4], int permutations[4])
{
	while (!ft_check_grid(tab, params))
	{
		if (permutations[0] <= 24)
			ft_permute(tab, permutations, 0);
		else if (permutations[1] <= 24)
			ft_permute(tab, permutations, 1);
		else if (permutations[2] <= 24)
			ft_permute(tab, permutations, 2);
		else if (permutations[3] <= 24)
			ft_permute(tab, permutations, 3);
		else
		{
			write(1, "Error\n", 7);
			return (0);
		}
	}
	return (1);
}

//Main function
//takes in parameters
//creates the grid of numbers
//solve the grid for given parameters
int	main(int argc, char **argv)
{
	int	params[4][4];
	int	tab[4][4];
	int	permutations[4];

	if (!ft_check_params(argc, argv))
	{
		write(1, "Error\n", 7);
		return (0);
	}
	ft_init_params(params, argv);
	ft_init_permutations(permutations);
	ft_create_tab(tab);
	if (ft_solve(tab, params, permutations))
		ft_show_tab(tab);
}
