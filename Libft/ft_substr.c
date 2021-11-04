/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:27:03 by njennes           #+#    #+#             */
/*   Updated: 2021/11/04 14:27:09 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	new = malloc((ft_min(ft_strlen(s) - start, len) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s[start], ft_min(ft_strlen(s) - start, len) + 1);
	return (new);
}
