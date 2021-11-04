/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:39:06 by njennes           #+#    #+#             */
/*   Updated: 2021/08/25 21:56:45 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_print(long nb, long modulo)
{
	char	letter;
	long	result;

	letter = '0';
	result = 0;
	while (nb >= modulo)
	{
		nb = nb - modulo;
		result = result + 1;
	}
	letter = letter + result;
	write(1, &letter, 1);
	if (modulo > 1)
		ft_print(nb, modulo / 10);
}

void	ft_putnbr(int nb)
{
	char	c;
	long	modulo;
	long	nbcpy;

	nbcpy = nb;
	if (nbcpy < 0)
	{
		write(1, "-", 1);
		nbcpy = nbcpy * -1;
	}
	if (nbcpy < 10)
	{
		c = '0';
		c = c + nbcpy;
		write(1, &c, 1);
	}
	else
	{
		modulo = 10;
		while (modulo <= nbcpy)
			modulo = modulo * 10;
		modulo = modulo / 10;
		ft_print(nbcpy, modulo);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	if (!par)
		return ;
	while (par->str)
	{
		ft_putstr(par->str);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr(par->copy);
		par++;
	}
}
