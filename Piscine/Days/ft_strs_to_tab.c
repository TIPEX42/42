/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 01:14:16 by njennes           #+#    #+#             */
/*   Updated: 2021/08/25 17:52:23 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*strcpy;

	i = 0;
	strcpy = malloc(ft_strlen(src) + 1);
	if (strcpy == 0)
		return (0);
	while (src[i])
	{
		strcpy[i] = src[i];
		i++;
	}
	strcpy[i] = 0;
	return (strcpy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ptr;
	int			i;

	ptr = malloc((ac + 1) * sizeof(t_stock_str));
	if (!ptr)
		return (0);
	i = 0;
	while (i < ac)
	{
		ptr[i].size = ft_strlen(av[i]);
		ptr[i].str = av[i];
		ptr[i].copy = ft_strdup(av[i]);
		if (!ptr[i].copy)
		{
			while (i > 0)
			{
				i--;
				free(ptr[i].copy);
			}
			return (0);
		}
		i++;
	}
	ptr[i].str = 0;
	return (ptr);
}
