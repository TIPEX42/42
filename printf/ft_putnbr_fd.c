/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:02:28 by njennes           #+#    #+#             */
/*   Updated: 2021/11/24 15:44:21 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(long nb, long modulo, int fd, int *chars_printed)
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
	(*chars_printed)++;
	if (modulo > 1)
		ft_print(nb, modulo / 10, fd, chars_printed);
}

void	ft_putnbr_fd(long n, int fd, int *chars_printed)
{
	char	c;
	long	modulo;
	long	nbcpy;

	nbcpy = n;
	if (nbcpy < 0)
	{
		write(fd, "-", 1);
		(*chars_printed)++;
		nbcpy = nbcpy * -1;
	}
	if (nbcpy < 10)
	{
		c = '0';
		c = c + nbcpy;
		write(fd, &c, 1);
		(*chars_printed)++;
	}
	else
	{
		modulo = 10;
		while (modulo <= nbcpy)
			modulo = modulo * 10;
		modulo = modulo / 10;
		ft_print(nbcpy, modulo, fd, chars_printed);
	}
}
