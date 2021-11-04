/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:05:38 by njennes           #+#    #+#             */
/*   Updated: 2021/08/23 14:08:28 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	totlen;

	totlen = ft_strlen(src) + ft_strlen(dest);
	if (size <= strlen(dest))
		return (ft_strlen(src) + size);
	while (*dest != 0 && size - 1 > 0)
	{
		dest++;
		size--;
	}
	while (*src != 0 && size - 1 > 0)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = 0;
	return (totlen);
}
