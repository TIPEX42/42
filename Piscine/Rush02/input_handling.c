/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 23:04:56 by eleroux           #+#    #+#             */
/*   Updated: 2021/08/22 23:06:52 by eleroux          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str, char second);

int	ft_strlen2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen2(str);
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
	return (str);
}

char	**ft_parse_input(char *str)
{
	int		i;
	int		j;
	char	**result;

	ft_strrev(str);
	if (ft_strlen2(str) % 3 > 0)
	{
		result = malloc(ft_strlen2(str) / 3 + 1);
	}
	else
	{
		result = malloc(ft_strlen2(str) / 3);
	}
	if (!result)
		return (0);
	i = 0;
	while (i < ft_strlen2(str) / 3)
	{
		result[i] = malloc(4);
		if (!result[i])
			return (0);
		result[i][0] = str[i * 3];
		result[i][1] = str[i * 3 + 1];
		result[i][2] = str[i * 3 + 2];
		result[i][3] = 0;
		ft_strrev(result[i]);
		i++;
	}
	result[i] = malloc(ft_strlen2(str) % 3 + 1);
	if (!result[i])
		return (0);
	j = 0;
	while (i * 3 + j < ft_strlen2(str))
	{
		result[i][j] = str[i * 3 + j];
		j++;
	}
	result[i][j] = 0;
	ft_strrev(result[i]);
	return (result);
}

int	ft_check_number(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			write(1, "Error2\n", 7);
			return (0);
		}
		i++;
	}
	return (1);
}
