/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:52:23 by njennes           #+#    #+#             */
/*   Updated: 2021/11/04 13:52:23 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int	negative;
	int	result;
	int	i;

	i = 0;
	result = 0;
	negative = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (ft_isdigit(str[i]) && str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * negative);
}

static void	ft_init_itoa(int *negative, long n, long *ncpy)
{
	*negative = 0;
	*ncpy = n;
	if(n < 0)
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

char	*ft_itoa(int n)
{
	int		negative;
	int		i;
	long	ncpy;
	char	*new;

	ft_init_itoa(&negative, n, &ncpy);
	new = ft_calloc(ft_numlen(ncpy, negative) + 1, sizeof(char));
	if (!new)
		return (NULL);
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