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

void	wait_for(int *value)
{
	while (!(*value))
		usleep(1);
}

void	send_char(int pid, unsigned char c)
{
	int	one;
	int	i;

	one = 1;
	i = 7;
	while (i >= 0)
	{
		if (c & (one << i))
		{
			ft_printf("1");
			wait_for(&g_infos.can_send);
			kill(pid, SIGUSR1);
			g_infos.can_send = 0;
			usleep(50);
		}
		else
			ft_printf("0");
		wait_for(&g_infos.can_send);
		g_infos.can_send = 0;
		ft_printf("Sending to pid:%d\n", pid);
		kill(pid, SIGUSR2);
		usleep(50);
		i--;
	}
	ft_printf("\n");
}

int	error_exit(const char *message, int code)
{
	ft_printf("%s\n", message);
	exit(code);
}

int	check_args(int argc)
{
	if (argc < 3)
		return (error_exit("Too few args!", 1));
	if (argc > 3)
		return (error_exit("Too many args!", 1));
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
	send_char(pid, 0);
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
	char	c[2];

	c[0] = hash;
	c[1] = 0;
	send_str(pid, c);
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

void	handler(int signo, siginfo_t *siginfo, void *content)
{
	(void)siginfo;
	(void)content;
	while (g_infos.handling)
		pause();
	g_infos.handling = 1;
	ft_printf("Server hqash: %d\n", g_infos.server_hash);
	ft_printf("Receiving %d\n", signo);
	if (g_infos.send_mode)
	{
		if (signo == SIGUSR1)
		{
			g_infos.can_send = 1;
			g_infos.handling = 0;
		}
		return ;
	}
	if (g_infos.server_hash == 500)
		g_infos.server_hash = 0;
	if (signo == SIGUSR2 && g_infos.last != SIGUSR1)
	{
		g_infos.server_hash = g_infos.server_hash * 2;
		g_infos.sigs++;
	}
	else if (signo == SIGUSR2 && g_infos.last == SIGUSR1)
	{
		g_infos.server_hash = g_infos.server_hash * 2 + 1;
		g_infos.sigs++;
	}
	g_infos.last = signo;
	if (g_infos.sigs == 8)
	{
		g_infos.got_hash = 1;
		g_infos.sigs = 0;
		ft_printf("\n");
	}
	g_infos.handling = 0;
	kill(g_infos.server_pid, SIGUSR1);
	return;
}

void	init_global()
{
	ft_memset(&g_infos, 0, sizeof (t_infos));
	sigemptyset(&g_infos.sa.sa_mask);
	g_infos.sa.sa_flags = SA_SIGINFO;
	g_infos.sa.sa_sigaction = handler;
	g_infos.server_hash = 500;
	g_infos.send_mode = 1;
	g_infos.can_send = 1;
}

int main(int argc, char **argv)
{
	int	hash;

	check_args(argc);
	init_global();
	g_infos.server_pid = ft_atoi(argv[1]);
	hash = hash_str(argv[2]);
	sigaction(SIGUSR1, &g_infos.sa, NULL);
	sigaction(SIGUSR2, &g_infos.sa, NULL);
	while (hash != g_infos.server_hash)
	{
		printf("retry\n");
		g_infos.server_hash = 500;
		g_infos.got_hash = 0;
		g_infos.send_mode = 1;
		send_length(g_infos.server_pid, argv[2]);
		send_str(g_infos.server_pid, argv[2]);
		send_hash(g_infos.server_pid, hash);
		g_infos.send_mode = 0;
		ft_printf("Finish sending\n");
		while (!g_infos.got_hash)
			pause();
		printf("Hash got: %d instead of %d\n", g_infos.server_hash, hash);
	}
	ft_printf("Message sent successfully!\n");
	return (0);
}
