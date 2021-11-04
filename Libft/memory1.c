/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:52:26 by njennes           #+#    #+#             */
/*   Updated: 2021/11/04 13:52:27 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s1cpy;
	const unsigned char	*s2cpy;

	s1cpy = s1;
	s2cpy = s2;
	i = 0;
	while (i < n - 1 && s1cpy[i] == s2cpy[i])
		i++;
	return (s1cpy[i] - s2cpy[i]);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bcpy;

	bcpy = b;
	i = 0;
	while (i < len)
	{
		bcpy[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*scpy;

	scpy = s;
	i = 0;
	while (i < n && scpy[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	return ((void *)&scpy[i]);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dstcpy;
	const unsigned char	*srccpy;

	dstcpy = dst;
	srccpy = src;
	i = 0;
	while (i < n)
	{
		dstcpy[i] = srccpy[i];
		i++;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstcpy;
	unsigned char	*srccpy;

	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len-- > 0)
		dstcpy[len] = srccpy[len];
	return (dst);
}
