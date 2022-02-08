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

#include "server.h"
#include "../lib/libtalk.h"

t_infos	g_infos;

int	error_exit(char *message, int code)
{
	ft_printf("%s\n", message);
	exit(code);
}

void	handle_byte()
{
	if (!g_infos.got_length)
	{
		if (g_infos.current == 0)
		{
			g_infos.got_length = 1;
			ft_printf("Length received: %d\n", g_infos.str_length);
			if (g_infos.str_length < 0 || g_infos.str_length > g_infos.max_length)
				g_infos.str_length = 0;
			g_infos.str = ft_calloc(g_infos.str_length + 1, sizeof(char));
			if (!g_infos.str)
				error_exit("Allocation error!\n", 1);
			return ;
		}
		ft_printf("Got: %d\n", g_infos.current);
		ft_printf("curr length %d\n", g_infos.str_length);
		g_infos.max_length = g_infos.max_length * 10 + 9;
		g_infos.str_length *= 10;
		g_infos.str_length += g_infos.current - '0';
	}
	else if (!g_infos.got_str)
	{
		if (g_infos.curr_length < g_infos.str_length)
			g_infos.str[g_infos.curr_length] = g_infos.current;
		g_infos.curr_length++;
		if (g_infos.current == 0)
			g_infos.got_str = 1;
	}
	else if (!g_infos.got_hash)
	{
		if (g_infos.current == 0)
			g_infos.got_hash = 1;
		else
			g_infos.hash = g_infos.current;
	}
}

void	signal_handler(int signo, siginfo_t *siginfo, void *content)
{
	(void)content;
	while (g_infos.handling)
		usleep(1);
	g_infos.handling = 1;
	if (g_infos.send_mode)
	{
		if (signo == SIGUSR1)
		{
			g_infos.can_send = 1;
			g_infos.handling = 0;
		}
		return ;
	}
	if (g_infos.got_hash)
		g_infos.send_mode = 1;
	g_infos.client_pid = siginfo->si_pid;
	if (signo == SIGUSR2 && g_infos.last != SIGUSR1)
	{
		g_infos.current = g_infos.current * 2;
		g_infos.sigs++;
		ft_printf("0");
	}
	else if (signo == SIGUSR2 && g_infos.last == SIGUSR1)
	{
		g_infos.current = g_infos.current * 2 + 1;
		g_infos.sigs++;
		ft_printf("1");
	}
	g_infos.last = signo;
	if (g_infos.sigs == 8)
	{
		handle_byte();
		g_infos.current = 0;
		g_infos.sigs = 0;
		ft_printf("\n");
	}
	g_infos.handling = 0;
	kill(g_infos.client_pid, SIGUSR1);
	return;
}

void	init_global()
{
	ft_memset(&g_infos, 0, sizeof (t_infos));
	sigemptyset(&g_infos.sa.sa_mask);
	g_infos.sa.sa_flags = SA_SIGINFO;
	g_infos.sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &g_infos.sa, NULL);
	sigaction(SIGUSR2, &g_infos.sa, NULL);
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

void	send_char(int pid, unsigned char c)
{
	int	one;
	int	i;

	one = 1;
	i = 7;
	ft_printf("%d\n", (int)c);
	while (i >= 0)
	{
		if (c & (one << i))
		{
			kill(pid, SIGUSR1);
			ft_printf("Sending 1\n");
			usleep(50);
		}
		else
			ft_printf("Sending 0\n");
		kill(pid, SIGUSR2);
		usleep(50);
		i--;
	}
}

int main()
{
	pid_t	pid;

	pid = getpid();

	init_global();
	ft_printf("%d\n", pid);
	while (1)
	{
		init_global();
		ft_printf("after init\n");
		while (!g_infos.send_mode)
			usleep(1);
		ft_printf("after hash\n");
		if (g_infos.hash == hash_str(g_infos.str))
			ft_printf("%s\n", g_infos.str);
		g_infos.can_send = 1;
		send_char(g_infos.client_pid, g_infos.hash);
		free(g_infos.str);
	}
}
