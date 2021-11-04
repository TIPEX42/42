/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_comb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:54:17 by njennes           #+#    #+#             */
/*   Updated: 2021/08/15 17:54:18 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_tab_unique(int a, int b, int c, int d)
{
	if (a == b)
		return (0);
	if (b == c)
		return (0);
	if (c == d)
		return (0);
	if (a == c)
		return (0);
	if (a == d)
		return (0);
	if (b == d)
		return (0);
	return (1);
}

int	ft_check_comb(int tab[4])
{
	int	i;

	if (!ft_tab_unique(tab[0], tab[1], tab[2], tab[3]))
		return (0);
	i = -1;
	while (++i < 4)
	{
		if (tab[i] > 4 || tab[i] < 1)
			return (0);
	}
	return (1);
}

int	ft_next_comb(int tab[4], int depth)
{
	int	i;

	while (tab[depth] <= 4)
	{
		if (depth < 3)
		{
			if (ft_next_comb(tab, depth + 1))
				return (1);
			tab[depth]++;
		}
		else
		{
			tab[depth]++;
			if (ft_check_comb(tab))
				return (1);
		}
	}
	i = 3;
	while (i >= depth)
	{
		tab[i] = 0;
		i--;
	}
	return (0);
}
