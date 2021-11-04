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

//Initialize permutations to zero
void	ft_init_permutations(int permutations[4])
{
	permutations[0] = 0;
	permutations[1] = 0;
	permutations[2] = 0;
	permutations[3] = 0;
}

//initialize parameters array with given arguments
void	ft_init_params(int params[4][4], char **argv)
{
	params[0][0] = ft_atoi(argv[1][0]);
	params[0][1] = ft_atoi(argv[1][2]);
	params[0][2] = ft_atoi(argv[1][4]);
	params[0][3] = ft_atoi(argv[1][6]);
	params[1][0] = ft_atoi(argv[1][16]);
	params[1][1] = ft_atoi(argv[1][18]);
	params[1][2] = ft_atoi(argv[1][20]);
	params[1][3] = ft_atoi(argv[1][22]);
	params[2][0] = ft_atoi(argv[1][8]);
	params[2][1] = ft_atoi(argv[1][10]);
	params[2][2] = ft_atoi(argv[1][12]);
	params[2][3] = ft_atoi(argv[1][14]);
	params[3][0] = ft_atoi(argv[1][24]);
	params[3][1] = ft_atoi(argv[1][26]);
	params[3][2] = ft_atoi(argv[1][28]);
	params[3][3] = ft_atoi(argv[1][30]);
}

//Initialize tab with valid numbers
void	ft_create_tab(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (j + i + 1 > 4)
				tab[i][j] = j + i + 1 - 4;
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
int	ft_check_params(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return (0);
	i = 0;
	while (argv[1][i] != 0)
	{
		if (i % 2 == 0 && (argv[1][i] < '0' || argv[1][i] > '9'))
			return (0);
		if (i % 2 == 1 && argv[1][i] != ' ')
			return (0);
		i++;
	}
	if (i == 31)
		return (1);
	return (0);
}
