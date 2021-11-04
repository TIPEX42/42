/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 14:48:39 by njennes           #+#    #+#             */
/*   Updated: 2021/08/05 16:18:19 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_space(void)
{
	write(1, ",", 1);
	write(1, " ", 1);
}

int	ft_tens(int number)
{
	int	result;

	result = 0;
	while (number >= 10)
	{
		number = number - 10;
		result = result + 1;
	}
	return (result);
}

void	ft_print_numbers(int a, int b)
{
	char	a1;
	char	a2;
	char	b1;
	char	b2;

	a1 = '0' + ft_tens(a);
	a2 = '0' + (a % 10);
	b1 = '0' + ft_tens(b);
	b2 = '0' + (b % 10);
	write(1, &a1, 1);
	write(1, &a2, 1);
	write(1, " ", 1);
	write(1, &b1, 1);
	write(1, &b2, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = a + 1;
	while (a <= 99)
	{
		while (b <= 99)
		{
			if (b > 1)
				ft_print_space();
			ft_print_numbers(a, b);
			b = b + 1;
		}
		a = a + 1;
		b = a + 1;
	}
}
