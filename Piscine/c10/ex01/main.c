/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:36:34 by njennes           #+#    #+#             */
/*   Updated: 2021/08/26 15:58:43 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void	ft_putstr(char *buffer);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_open_file(char *path)
{
	int	file;
	
	file = open(path, O_RDONLY);
	if (file == -1)
	{
		write(1, "cat: ", 5);
		ft_putstr(path);
		write(1, ": ", 2);
		ft_putstr(strerror(errno));
		write(1, "\n", 1);
		return (0);
	}
	return (file);
}

int	ft_read_file(int file, char *buffer)
{
	int	found;
	
	found = read(file, buffer, 4096);
	if (found > 0)
	{
		buffer[found] = '\0';
	}
	return (found);
}

void	ft_putstr(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		write(1, &buffer[i], 1);
		i++;
	}
}

int	ft_write_file(char *path)
{
	int		file;
	int		found;
	char	buffer[4097];
	
	file = ft_open_file(path);
	if (!file)
		return (1);
	found = ft_read_file(file, buffer);
	while (found)
	{
		ft_putstr(buffer);
		found = ft_read_file(file, buffer);
	}
	close(file);
	return (0);
}

void	ft_read_from_stdin(void)
{
	char	buffer[30001];
	int		found;

	while (1)
	{
		found = read(1, buffer, 30000);
		buffer[found] = 0;
		ft_putstr(buffer);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 1 && argv[i][0] == '-')
			ft_read_from_stdin();
		if (ft_write_file(argv[i]))
			return (1);
		i++;
	}
	return (0);
}