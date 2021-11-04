/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_letters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:09:59 by eleroux           #+#    #+#             */
/*   Updated: 2021/08/22 22:41:38 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str, char second);
char	*ft_cent(char *comb, int offset, char *result, char ***dict);
char	*ft_diz(char *comb, int offset, char *result, char ***dict);
char	*ft_unit(char *comb, int offset, char *result, char ***dict);
char	*ft_str_filler(char *str_old, char *str_new);

char	*ft_num_to_letters(char	*comb, int offset, int max, char ***dict)
{
	int		len;
	char	*result;

	len = max - offset;
	result = "";
	if (len >= 3)
		result = ft_cent(comb, offset, result, dict);
	if (len == 2)
		result = ft_diz(comb, offset - 1, result, dict);
	if (len == 1)
		result = ft_unit(comb, offset - 2, result, dict);
	return (result);
}

char	*ft_cent(char *comb, int offset, char *result, char ***dict)
{
	int	num;

	num = 1;
	if (comb[0 + offset] != '0')
	{
		while (num <= 9)
		{
			if (comb[0 + offset] - 48 == num)
			{
				result = ft_str_filler(result, dict[0][num]);
				result = ft_str_filler(result, dict[1][8]);
			}
			num++;
		}	
	}
	if (comb[1 + offset] != '0')
		return (ft_diz(comb, offset, result, dict));
	else if (comb[2 + offset] != '0')
		return (ft_unit(comb, offset, result, dict));
	else
		return (result);
}

char	*ft_diz(char	*comb, int offset, char	*result, char ***dict)
{
	int	num;

	num = 1;
	if (comb[1 + offset] == '1')
	{
		num = 0;
		while (num <= 9)
		{
			if (comb[2 + offset] - 48 == num)
			{
				result = ft_str_filler(result, dict[0][num + 10]);
				return (result);
			}
			num++;
		}
	}
	else
	{
		while (num <= 9)
		{
			if (comb[1 + offset] - 48 == num)
				result = ft_str_filler(result, dict[1][num - 2]);
			num++;
		}
	}
	if (comb[2 + offset] == '0')
		return (result);
	return (ft_unit(comb, offset, result, dict));
}

char	*ft_unit(char *comb, int offset, char *result, char ***dict)
{
	int	num;

	num = 1;
	while (num <= 9)
	{
		if (comb[2 + offset] - 48 == num)
		{
			result = ft_str_filler(result, dict[0][num]);
				return (result);
		}
		num++;
	}
	result = ft_str_filler(result, dict[0][0]);
	return (result);
}

char	*ft_str_filler(char *str_old, char *str_new)
{
	char	*result;
	int		i;
	int	j;

	result = malloc(ft_strlen(str_old, 0) + ft_strlen(str_new, 0) + 2);
	i = 0;
	if (!result)
		return (NULL);
	while (str_old[i])
	{
		result[i] = str_old[i];
		i++;
	}
	j = 0;
	if (result[0])
	{
		result[i] = ' ';
		i++;
	}
	while (str_new[j])
	{
		result[i] = str_new[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
