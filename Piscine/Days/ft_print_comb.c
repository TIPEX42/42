/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 10:47:40 by njennes           #+#    #+#             */
/*   Updated: 2021/08/05 14:48:08 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_number(int a, int b, int c)
{
	char	num1;
	char	num2;
	char	num3;

	num1 = '0' + a;
	num2 = '0' + b;
	num3 = '0' + c;
	write(1, &num1, 1);
	write(1, &num2, 1);
	write(1, &num3, 1);
}

void	ft_print_space(void)
{
	write(1, ",", 1);
	write(1, " ", 1);
}

void	ft_next_combination(int *a, int *b, int *c)
{
	*c = *c + 1;
	if (*c > 9)
	{
		*c = 0;
		*b = *b + 1;
		if (*b > 9)
		{
			*b = 0;
			*a = *a + 1;
		}
	}
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	c = 0;
	while (a <= 9)
	{
		if (a < b && b < c)
		{
			if (c >= 3)
				ft_print_space();
			ft_print_number(a, b, c);
			ft_next_combination(&a, &b, &c);
		}
		else
		{
			ft_next_combination(&a, &b, &c);
		}
	}
}
