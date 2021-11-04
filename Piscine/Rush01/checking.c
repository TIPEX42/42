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

int	ft_tab_unique(int a, int b, int c, int d);

int	ft_check_view_left(int tab[4], int nb)
{
	int	i;
	int	result;
	int	max;

	i = 0;
	result = 0;
	max = 0;
	while (i < 4)
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

int	ft_check_view_right(int tab[4], int nb)
{
	int	i;
	int	result;
	int	max;

	i = 3;
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

int	ft_check_view_up(int tab[4][4], int col, int nb)
{
	int	result;
	int	max;
	int	i;

	result = 0;
	max = 0;
	i = 0;
	while (i < 4)
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

int	ft_check_view_down(int tab[4][4], int col, int nb)
{
	int	result;
	int	max;
	int	i;

	result = 0;
	max = 0;
	i = 3;
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

int	ft_check_column(int tab[4][4], int col, int nbup, int nbdown)
{
	int	i;
	int	passed_up;
	int	passed_down;

	if (!ft_tab_unique(tab[0][col], tab[1][col], tab[2][col], tab[3][col]))
		return (0);
	i = 0;
	while (i < 4)
	{
		if (tab[i][col] > 4 || tab[i][col] < 1)
			return (0);
		i++;
	}
	passed_up = ft_check_view_up(tab, col, nbup);
	passed_down = ft_check_view_down(tab, col, nbdown);
	return (passed_up && passed_down);
}
