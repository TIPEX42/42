/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:28:26 by njennes           #+#    #+#             */
/*   Updated: 2021/08/16 11:28:30 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_modulo(int a, int b)
{
	while (a > b)
	{
		a = a - b;
	}
	return (a);
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
