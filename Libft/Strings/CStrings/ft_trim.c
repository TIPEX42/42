/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 17:49:56 by                   #+#    #+#             */
/*   Updated: 2022/01/25 17:54:18 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_trimr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = ft_strlen(str) - 1;
	while (i >= 0 && ft_isspace(str[i]))
	{
		str[i] = 0;
		i--;
	}
}

void	ft_triml(char *str)
{
	size_t	i;
	size_t	len;

	if (!str)
		return ;
	i = 0;
	len = ft_strlen(str);
	while (i < len && ft_isspace(str[i]))
	{
		str[i] = 0;
		i++;
	}
}

void	ft_trim(char *str)
{
	ft_triml(str);
	ft_trimr(str);
}
