/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:05:45 by njennes           #+#    #+#             */
/*   Updated: 2021/08/23 14:08:21 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*destcpy;

	destcpy = dest;
	while (*dest != 0)
	{
		dest++;
	}
	while (*src != 0 && nb != 0)
	{
		*dest = *src;
		dest++;
		src++;
		nb--;
	}
	*dest = 0;
	return (destcpy);
}
