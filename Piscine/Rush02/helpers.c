/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 23:03:27 by eleroux           #+#    #+#             */
/*   Updated: 2021/08/22 23:04:17 by eleroux          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_my_ln(unsigned long long number)
{
	int					result;
	unsigned long long	guess;

	result = 0;
	guess = 1000;
	while (guess != number)
	{
		result++;
		guess = guess * 1000;
	}
	return (result);
}

int	ft_strlen(char *str, char second)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str[i] != second)
		i++;
	return (i);
}
