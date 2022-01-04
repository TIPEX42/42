/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:09:09 by njennes           #+#    #+#             */
/*   Updated: 2021/11/05 11:13:49 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(long nb, long modulo, int fd)
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
	write(fd, &letter, 1);
	if (modulo > 1)
		ft_print(nb, modulo / 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	modulo;
	long	nbcpy;

	nbcpy = n;
	if (nbcpy < 0)
	{
		write(fd, "-", 1);
		nbcpy = nbcpy * -1;
	}
	if (nbcpy < 10)
	{
		c = '0';
		c = c + nbcpy;
		write(fd, &c, 1);
	}
	else
	{
		modulo = 10;
		while (modulo <= nbcpy)
			modulo = modulo * 10;
		modulo = modulo / 10;
		ft_print(nbcpy, modulo, fd);
	}
}
