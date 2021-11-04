/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 23:02:14 by eleroux           #+#    #+#             */
/*   Updated: 2021/08/22 23:02:23 by eleroux          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str, char second);

char	*ft_realloc(char *str, char *buffer, int size)
{
	char	*new_str;	
	int		old_len;
	int		i;

	old_len = ft_strlen(str, 0);
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
	char	buffer[2048 + 1];
	char	*str;
	int		found;

	str = malloc(1);
	if (!str)
		return (0);
	str[0] = 0;
	int	file = open(path, O_RDONLY);
	if (!file)
	{
		write(1, "Dict Error\n", 12);
		return (0);
	}
	found = 1;
	while (found > 0)
	{
		found = read(file, buffer, 2048);
		if (found > 0)
		{
			buffer[found] = '\0';
			str = ft_realloc(str, buffer, found);
		}
	}
	close(file);
	return (str);
}
