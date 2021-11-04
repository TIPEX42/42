/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:07:16 by njennes           #+#    #+#             */
/*   Updated: 2021/08/23 14:07:16 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *src, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == 0)
		return (src);
	while (src[i] != 0)
	{
		j = 0;
		while (src[i + j] == to_find[j] && to_find[j] != 0)
		{
			j++;
		}
		if (to_find[j] == 0)
			return (&src[i]);
		i++;
	}
	return (0);
}
