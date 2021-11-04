/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 12:09:37 by njennes           #+#    #+#             */
/*   Updated: 2021/08/08 12:09:43 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(int x, int y, int i, int j)
{
	if (i == x)
		ft_putchar('\n');
	else if ((i == 0 || i == x - 1) && (j == 0 || j == y - 1))
		ft_putchar('o');
	else if (i == 0 || i == x - 1)
		ft_putchar('|');
	else if (j == 0 || j == y - 1)
		ft_putchar('-');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	i;
	int	j;	

	if (x <= 0 || y <= 0)
		return ;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i <= x)
		{
			ft_print(x, y, i, j);
			i++;
		}
		j++;
	}
}
