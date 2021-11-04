/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 09:50:50 by njennes           #+#    #+#             */
/*   Updated: 2021/08/26 13:43:05 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str, char *charset, int mode)
{
	int	i;

	i = 0;
	if (mode)
	{
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
		return (i);
	}
	else
	{	
		while (str[i])
			i++;
		return (i);
	}
}

int	ft_get_words(char *str, char *charset)
{
	int	i;
	int	in_word;
	int	blocks;

	i = 0;
	in_word = 0;
	blocks = 0;
	while (str[i])
	{
		if (!ft_is_charset(str[i], charset))
		{
			if (!in_word)
				blocks++;
			in_word = 1;
		}
		else
			in_word = 0;
		i++;
	}
	return (blocks);
}

char	**ft_add_to_tab(char **result, char **str, char *charset, int i)
{
	int	j;

	result[i] = malloc(ft_strlen(str[0], charset, 1) + 1);
	if (!result[i])
		return (0);
	j = 0;
	while (!ft_is_charset(*str[0], charset) && *str[0])
	{
		result[i][j] = *str[0];
		j++;
		str[0]++;
	}
	result[i][j] = 0;
	return (result);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		len;
	char	**result;

	len = ft_get_words(str, charset);
	result = malloc((len + 1) * sizeof(char *));
	if (!result)
		return (0);
	i = 0;
	while (*str)
	{
		if (ft_is_charset(*str, charset))
		{
			str++;
			continue ;
		}
		result = ft_add_to_tab(result, &str, charset, i);
		i++;
		str++;
	}
	result[i] = 0;
	return (result);
}
