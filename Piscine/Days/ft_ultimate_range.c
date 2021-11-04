/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:19:58 by njennes           #+#    #+#             */
/*   Updated: 2021/08/25 17:16:08 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*res;

	i = 0;
	if (min >= max)
	{
		res = NULL;
		*range = res;
		return (0);
	}
	res = malloc(sizeof(int) * (max - min));
	if (!res)
		return (-1);
	while (min < max)
	{
		res[i] = min;
		i++;
		min++;
	}
	*range = res;
	return (i);
}
