/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:52:16 by njennes           #+#    #+#             */
/*   Updated: 2021/11/04 13:52:16 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	if (ft_isalpha(c) && c >= 'a' && c <= 'z')
		return (c - 26);
	return (c);
}

int		ft_tolower(int c)
{
	if (ft_isalpha(c) && c >= 'A' && c <= 'Z')
		return (c + 26);
	return (c);
}

char	*ft_strdup(const char *s1)
{
	char	*newstr;

	newstr = malloc((ft_strlen(s1) + 1) * sizeof(s1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
	return (newstr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = 0;
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	totlen;

	totlen = ft_strlen(src) + ft_strlen(dst);
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	while (*dst != 0 && dstsize - 1 > 0)
	{
		dst++;
		dstsize--;
	}
	i = 0;
	while (src[i] != 0 && dstsize - 1 > 0)
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	dst[i] = 0;
	return (totlen);
}
