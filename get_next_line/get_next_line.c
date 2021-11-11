/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjeannot <bjeannot@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:45:30 by njennes           #+#    #+#             */
/*   Updated: 2021/11/10 23:56:37 by bjeannot         ###   ########lyon.fr   */
/*   Updated: 2021/11/09 14:57:09 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_print(char c)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, "\\", 1);
	write(1, &base[c / 16], 1);
	write(1, &base[c % 16], 1);
}

void	print_buffer(char *buff, int size)
{
	int i = 0;
	while (i < size)
	{
		ft_print(buff[i]);
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*fileRead;
	static int	oldFd;

	if (fd != oldFd)
	{
		oldFd = fd;
		if (!read_new_file(&fileRead))
			return (NULL);
	}
	return (find_line(fd, &fileRead));
}

int	read_new_file(char **fileRead)
{
	if (*fileRead)
		free(*fileRead);
	*fileRead = malloc(1 * sizeof(char));
	if (!*fileRead)
		return (0);
	(*fileRead)[0] = 0;
	return (1);
}

char	*find_line(int fd, char **fileRead)
{
	char	buffer[BUFFER_SIZE];
	int		bytesRead;

	bytesRead = read(fd, buffer, BUFFER_SIZE);
	print_buffer(buffer, BUFFER_SIZE);
	if (bytesRead == 0 && ft_strlen(*fileRead) > 0)
		return (ft_cut_line(fileRead));
	else if (bytesRead == 0)
	{
		free(*fileRead);
		return (NULL);
	}
	if (!ft_concat(fileRead, buffer, bytesRead))
		return (NULL);
	if (ft_strchr(*fileRead, '\n') || ft_strchr(*fileRead, EOF))
		return (ft_cut_line(fileRead));
	else
		return (find_line(fd, fileRead));
}

int	ft_get_line_length(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] != '\n' && line[i] != EOF)
	{
		i++;
	}
	if (line[i] == '\n')
		i++;
	return (i);
}

char	*ft_cut_line(char **fileRead)
{
	int		i;
	int		size;
	int		buffer_size;
	char	*new;
	char	*newTwo;

	size = ft_get_line_length(*fileRead);
	new = malloc((size + 1) * sizeof(char));
	i = 0;
	while (i < size)
	{
		new[i] = (*fileRead)[i];
		i++;
	}
	new[i] = 0;
	buffer_size = ft_strlen(&((*fileRead)[i]));
	newTwo = malloc((buffer_size + 1) * sizeof(char));
	if (newTwo)
	{
		while ((*fileRead)[i])
		{
			*newTwo = (*fileRead)[i];
			newTwo++;
			i++;
		}
		*newTwo = 0;
		newTwo = &newTwo[-buffer_size];
	}
	if (*fileRead)
		free(*fileRead);
	*fileRead = newTwo;
	return (new);
}

int	ft_concat(char **fileRead, char *buffer, size_t bytesRead)
{
	char	*new;
	size_t	i;
	size_t	oldSize;

	oldSize = ft_strlen(*fileRead);
	new = malloc((oldSize + bytesRead + 1) * sizeof(char));
	if (!new)
		return (0);
	i = 0;
	while ((*fileRead)[i])
	{
		new[i] = (*fileRead)[i];
		i++;
	}
	while (i < oldSize + bytesRead)
	{
		new[i] = *buffer;
		i++;
		buffer++;
	}
	new[i] = 0;
	if (*fileRead)
		free(*fileRead);
	*fileRead = new;
	return (1);
}
