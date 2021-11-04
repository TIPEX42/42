/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:11:50 by njennes           #+#    #+#             */
/*   Updated: 2021/11/04 14:12:01 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
