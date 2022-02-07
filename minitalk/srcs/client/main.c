/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:26:19 by                   #+#    #+#             */
/*   Updated: 2022/01/06 18:08:08 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"
#include "../lib/libtalk.h"

t_infos	g_infos;

void	ft_memset(void *dest, int value, size_t len)
{
	char	*dest_cp;
	size_t	i;

	dest_cp = (char *)dest;
	i = 0;
	while (i < len)
	{
		dest_cp[i] = value;
		i++;
	}
}

void	send_char(int pid, char c)
{
	int	one;
	int	i;

	one = 1;
	i = 7;
	while (i >= 0)
	{
		if (c & (one << i))
		{
			kill(pid, SIGUSR1);
			usleep(50);
		}
		kill(pid, SIGUSR2);
		usleep(50);
		i--;
	}
}

int	error_exit(const char *message, int code)
{
	ft_printf("%s\n", message);
	exit(code);
}

int	check_args(int argc)
{
	if (argc < 3)
		return (error_exit("Too few args!"), 1);
	if (argc > 3)
		return (error_exit("Too many args!"), 1);
	return (0);
}

void	send_str(int pid, const char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
}

int	send_length(int pid, const char *message)
{
	int		length;
	char	*str;

	length = ft_strlen(message);
	str = ft_itoa(length);
	if (!str)
		return (error_exit("Allocaton error!\n", 1));
	send_str(pid, str);
	free(str);
	return (0);
}

int	send_hash(int pid, int hash)
{
	char	*str;

	str = ft_itoa(hash);
	if (!str)
		return (error_exit("Allocation error!\n", 1));
	send_str(pid, str);
	free(str);
	return (0);
}

int	hash_str(const char *str)
{
	int	i;
	int	hash;

	hash = 0;
	i = 0;
	while (str[i])
	{
		hash += str[i];
		hash = hash % 255;
		i++;
	}
	return (hash);
}

void	handler()
{
	if (g_infos.server_hash == 500)
		g_infos.server_hash = 0;

}

void	init_global(int hash)
{
	ft_memset(&g_infos, 0, sizeof (t_infos));
	sigemptyset(&g_infos.sa.sa_mask);
	g_infos.sa.sa_handler = handler;
	g_infos.sa.sa_flags = SA_SIGINFO;
	g_infos.server_hash = 500;
}

int main(int argc, char **argv)
{
	int	pid;
	int	hash;

	check_args(argc);
	pid = ft_atoi(argv[1]);
	hash = hash_str(argv[2]);
	init_global(hash);
	while (hash != g_infos.server_hash)
	{
		send_length(pid, argv[2]);
		send_str(pid, argv[2]);
		send_hash(pid, hash);
		while (!g_infos.got_hash)
			pause();
	}
	return (0);
}
