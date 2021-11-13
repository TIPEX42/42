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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	oldFd;
	char		*line;

	if (fd != oldFd)
	{
		oldFd = fd;
		ft_memset(buffer, 0, BUFFER_SIZE);
	}
	line = malloc(1 * sizeof(char));
	if (!line)
		return (NULL);
	line[0] = 0;
	return (find_line(fd, buffer, &line));
}

char	*find_line(int fd, char *buffer, char **line)
{
	int		bytesRead;
	int		addLineResult;

	bytesRead = read(fd, buffer, BUFFER_SIZE);
	addLineResult = ft_add_to_line(line, buffer, bytesRead);
	if (addLineResult == -1)
	{
		free(*line);
		return (NULL);
	}
	if (addLineResult == 0)
		return (find_line(fd, buffer, line));
	if (addLineResult == 1)
		return (*line);

}

int	ft_get_line_length(char *buffer, int bytesRead)
{
	int i;

	i = 0;
	while (i < bytesRead && line[i] != '\n' && line[i] != EOF)
		i++;
	if (line[i] == '\n')
		i++;
	return (i);
}

int	ft_add_to_line(char **line, char *buffer, int bytesRead)
{
	char	*newLine;
	size_t	newLength;

	newLength = ft_get_line_length(buffer, bufferSize);
	newLine = malloc((ft_strlen(*line) + newLength + 1) * sizeof(char));
	if (!newLine)
		return (-1);
	ft_strlcpy(newLine, *line, ft_strlen(*line));
	ft_strlcpy(&newLine[ft_strlen(*line)], buffer, newLength);
	free(*line);
	*line = newLine;
	if (newLength < bytesRead)
	{
		ft_memmove(buffer, &buffer[newLength], bytesRead - newLength);
		return (1);
	}
	return (0);
}
