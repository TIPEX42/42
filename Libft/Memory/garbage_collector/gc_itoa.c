/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:22:09 by njennes           #+#    #+#             */
/*   Updated: 2022/04/08 19:18:28 by njennes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_init_itoa(int *negative, long n, long *ncpy)
{
	*negative = 0;
	*ncpy = n;
	if (n < 0)
	{
		*negative = 1;
		*ncpy = -n;
	}
}

static int	ft_numlen(long n, int negative)
{
	int	result;

	result = 1;
	while (n > 9)
	{
		n /= 10;
		result++;
	}
	return (result + negative);
}

char	*gc_itoa(int n)
{
	int		negative;
	int		i;
	long	ncpy;
	char	*new;

	ft_init_itoa(&negative, n, &ncpy);
	new = gc_calloc(ft_numlen(ncpy, negative) + 1, sizeof(char));
	i = ft_numlen(ncpy, negative);
	new[i--] = 0;
	if (ncpy == 0)
		new[0] = '0';
	while (ncpy > 0)
	{
		new[i--] = ncpy % 10 + '0';
		ncpy /= 10;
	}
	if (negative)
		new[0] = '-';
	return (new);
}
