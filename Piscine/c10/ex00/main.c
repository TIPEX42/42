/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:54:51 by njennes           #+#    #+#             */
/*   Updated: 2021/08/26 14:46:39 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_open_file(char *path)
{
	int	file;
	
	file = open(path, O_RDONLY);
	if (file == -1)
	{
		write(1, "Cannot read file\n", 18);
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

int	ft_check_argc(int argc)
{
	if (argc <= 1)
	{
		write(1, "File name missing.\n", 20);
		return (0);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 21);
		return (0);
	}
	return (1);
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

int	main(int argc, char **argv)
{
	int		i;
	int		file;
	int		found;
	char	buffer[4097];

	if (!ft_check_argc(argc))
		return (1);
	i = 0;
	file = ft_open_file(argv[1]);
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