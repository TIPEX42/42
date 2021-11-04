/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:11:36 by njennes           #+#    #+#             */
/*   Updated: 2021/11/04 14:11:42 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
