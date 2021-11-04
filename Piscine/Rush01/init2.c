/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:54:06 by njennes           #+#    #+#             */
/*   Updated: 2021/08/15 17:54:08 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char c)
{
	return ((int)c - '0');
}

//initialize parameters array with given arguments
void	ft_init_params(int **params, char **argv, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		params[0][i] = ft_atoi(argv[1][j]);
		i++;
		j += 2;
	}
	i = 0;
	while (i < size)
	{
		params[2][i] = ft_atoi(argv[1][j]);
		i++;
		j += 2;
	}
	i = 0;
	while (i < size)
	{
		params[1][i] = ft_atoi(argv[1][j]);
		i++;
		j += 2;
	}
	i = 0;
	while (i < size)
	{
		params[3][i] = ft_atoi(argv[1][j]);
		i++;
		j += 2;
	}
}

//Initialize tab with valid numbers
void	ft_create_tab(int **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (j + i + 1 > size)
				tab[i][j] = j + i + 1 - size;
			else
				tab[i][j] = j + i + 1;
			j++;
		}
		j = 0;
		i++;
	}
}

//Checks for valid parameters
//length and syntax
int	ft_check_params(int argc, char **argv, int *size)
{
	int	i;

	if (argc != 3)
		return (0);
	*size = ft_atoi(argv[2][0]);
	i = 0;
	while (argv[1][i] != 0)
	{
		if (i % 2 == 0 && (argv[1][i] < '0' || argv[1][i] > '9'))
			return (0);
		if (i % 2 == 1 && argv[1][i] != ' ')
			return (0);
		i++;
	}
	if (i % 2 == 1)
		return (1);
	return (0);
}
