/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:08:28 by njennes           #+#    #+#             */
/*   Updated: 2021/08/16 17:10:41 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	i = 0;
	while (base[i] != 0)
	{
		j = i + 1;
		while (base[i] != base[j] && base[j] != 0)
			j++;
		if (base[j] != 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

void	ft_putnbr(char *result)
{
	result += 32;
	while (*result != -1)
	{
		if (*result != -2)
			write(1, result, 1);
		result--;
	}
}

void	ft_prepare_list(char *result)
{
	int	i;

	i = 0;
	while (i < 33)
	{
		result[i] = -2;
		i++;
	}
	result[0] = -1;
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		r;
	long	q;
	char	result[33];
	int		i;

	ft_prepare_list(result);
	i = 0;
	q = nbr;
	if (!ft_check_base(base))
		return ;
	if (q < 0)
	{
		write(1, "-", 1);
		q = -q;
	}
	while (q != 0 || result[i] == -1)
	{
		i++;
		r = q % ft_strlen(base);
		q = q / ft_strlen(base);
		result[i] = base[r];
	}
	ft_putnbr(result);
}
