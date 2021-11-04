/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:41:22 by njennes           #+#    #+#             */
/*   Updated: 2021/08/25 10:41:31 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_realloc_char(char *str, char *buffer, int size)
{
	char	*new_str;	
	int		old_len;
	int		i;

	old_len = ft_strlen(str);
	new_str = malloc(old_len + size + 1);
	if (!new_str)
		return (0);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (*buffer)
	{
		new_str[i] = *buffer;
		i++;
		buffer++;
	}
	new_str[i] = 0;
	free(str);
	return (new_str);
}

char	*ft_read_file(char	*path)
{
	char	buffer[4096 * 8 + 1];
	char	*str;
	int		found;
	int		file;

	str = malloc(1);
	if (!str)
		return (0);
	str[0] = 0;
	file = open(path, O_RDONLY);
	if (!file)
	{
		write(1, "File Error\n", 12);
		return (0);
	}
	found = 1;
	while (found > 0)
	{
		found = read(file, buffer, 4096 * 8);
		if (found > 0)
		{
			buffer[found] = '\0';
			str = ft_realloc_char(str, buffer, found);
		}
	}
	close(file);
	return (str);
}
