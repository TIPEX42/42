/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:48:27 by njennes           #+#    #+#             */
/*   Updated: 2021/11/25 16:36:49 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libtalk.h"

void	ft_putnbr(char *result, int *chars_printed)
{
	result += 32;
	while (*result != -1)
	{
		if (*result != -2)
		{
			write(1, result, 1);
			(*chars_printed)++;
		}
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

void	ft_putnbr_base(size_t nbr, char *base, int *chars_printed)
{
	int		r;
	char	result[33];
	int		i;

	ft_prepare_list(result);
	i = 0;
	while (nbr != 0 || result[i] == -1)
	{
		i++;
		r = nbr % ft_strlen(base);
		nbr = nbr / ft_strlen(base);
		result[i] = base[r];
	}
	ft_putnbr(result, chars_printed);
}
