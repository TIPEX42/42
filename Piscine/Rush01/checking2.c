/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:54:01 by njennes           #+#    #+#             */
/*   Updated: 2021/08/15 17:54:03 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_tab_unique(int **tab, int col, int size);

int	ft_check_view_left(int *tab, int nb, int size)
{
	int	i;
	int	result;
	int	max;

	i = 0;
	result = 0;
	max = 0;
	while (i < size)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			result++;
		}
		i++;
	}
	if (result == nb)
		return (1);
	return (0);
}

int	ft_check_view_right(int *tab, int nb, int size)
{
	int	i;
	int	result;
	int	max;

	i = size - 1;
	result = 0;
	max = 0;
	while (i >= 0)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			result++;
		}
		i--;
	}
	if (result == nb)
		return (1);
	return (0);
}

int	ft_check_view_up(int **tab, int col, int nb, int size)
{
	int	result;
	int	max;
	int	i;

	result = 0;
	max = 0;
	i = 0;
	while (i < size)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			result++;
		}
		i++;
	}
	if (result == nb)
		return (1);
	return (0);
}

int	ft_check_view_down(int **tab, int col, int nb, int size)
{
	int	result;
	int	max;
	int	i;

	result = 0;
	max = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			result++;
		}
		i--;
	}
	if (result == nb)
		return (1);
	return (0);
}

int	ft_check_column(int **tab, int col, int nb[2], int size)
{
	int	i;
	int	passed_up;
	int	passed_down;

	if (!ft_tab_unique(tab, col, size))
		return (0);
	i = 0;
	while (i < size)
	{
		if (tab[i][col] > size || tab[i][col] < 1)
			return (0);
		i++;
	}
	passed_up = ft_check_view_up(tab, col, nb[0], size);
	passed_down = ft_check_view_down(tab, col, nb[1], size);
	return (passed_up && passed_down);
}
