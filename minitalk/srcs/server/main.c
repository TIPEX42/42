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

void	handle_byte(int byte)
{
	if (byte == 0)
		kill(g_infos.client_pid, SIGUSR1);
	else
		ft_printf("%c", (char)g_infos.current);
}

void	signal_handler(int signo, siginfo_t *siginfo, void *content)
{
	(void)content;
	while (g_infos.handling)
		usleep(1);
	g_infos.handling = 1;
	g_infos.client_pid = siginfo->si_pid;
	if (signo == SIGUSR2)
	{
		g_infos.current = g_infos.current * 2;
		g_infos.sigs++;
	}
	else if (signo == SIGUSR1)
	{
		g_infos.current = g_infos.current * 2 + 1;
		g_infos.sigs++;
	}
	if (g_infos.sigs == 8)
	{
		handle_byte(g_infos.current);
		g_infos.current = 0;
		g_infos.sigs = 0;
	}
	g_infos.handling = 0;
	return ;
}

void	init(void)
{
	ft_memset(&g_infos, 0, sizeof(t_infos));
	sigemptyset(&g_infos.sa.sa_mask);
	g_infos.sa.sa_flags = SA_SIGINFO;
	g_infos.sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &g_infos.sa, NULL);
	sigaction(SIGUSR2, &g_infos.sa, NULL);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
		{
			kill(pid, SIGUSR1);
			usleep(50);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(50);
		}
		i--;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	init();
	while (1)
		pause();
}
