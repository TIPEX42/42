/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:20:03 by njennes           #+#    #+#             */
/*   Updated: 2021/08/24 23:46:30 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
