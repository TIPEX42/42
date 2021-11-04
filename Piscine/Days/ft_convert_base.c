/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:19:55 by njennes           #+#    #+#             */
/*   Updated: 2021/08/25 10:13:13 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

long	ft_atoi_base(char *str, char *base)
{
	long	nb;
	long	moins;
	int		index;

	nb = 0;
	moins = 1;
	while (*str < 33)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			moins *= -1;
		str++;
	}
	while (*str)
	{
		index = 0;
		while (*str != base[index])
			index++;
		nb = (nb * ft_strlen(base)) + index;
		str++;
	}
	return (nb * moins);
}

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

char	*ft_putnbr_base(long nbr, char *base)
{
	int		r;
	char	*result;
	int		i;

	i = 0;
	result = malloc(35 * sizeof(char));
	if (!result)
		return (0);
	if (nbr < 0)
		nbr = -nbr;
	while (nbr != 0)
	{
		r = nbr % ft_strlen(base);
		nbr = nbr / ft_strlen(base);
		result[i] = base[r];
		i++;
	}
	if (i == 0 && nbr == 0)
	{
		result[i] = base[0];
		i++;
	}
	result[i] = 0;
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nbr_int;
	char	*result;
	char	tmp;
	int		i;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (0);
	nbr_int = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(nbr_int, base_to);
	if (result == 0)
		return (0);
	i = 0;
	if (ft_atoi_base(nbr, base_from) < 0)
	{
		result[ft_strlen(result) + 1] = '\0';
		result[ft_strlen(result)] = '-';
	}
	while (i < ft_strlen(result) / 2)
	{
		tmp = result[i];
		result[i] = result[ft_strlen(result) - i - 1];
		result[ft_strlen(result) - i - 1] = tmp;
		i++;
	}
	return (result);
}
