/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:08:00 by njennes           #+#    #+#             */
/*   Updated: 2021/08/08 15:29:55 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);

void	ft_swap(int *tab, int a, int b)
{
	int	temp;

	temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(tab, i, i + 1);
			i = 0;
		}
		else
		{
			i = i + 1;
		}			
	}
}
