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

int	ft_tab_unique(int **tab, int col, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i][col] == tab[j][col])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
