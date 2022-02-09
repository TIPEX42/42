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

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		i--;
	}
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

void	handler(int signo, siginfo_t *siginfo, void *content)
{
	(void)content;
	(void)signo;
	while (g_infos.handling)
		pause();
	g_infos.handling = 1;
	if (siginfo->si_pid == g_infos.server_pid)
		g_infos.server_response = 1;
	g_infos.handling = 0;
	return ;
}

int	main(int argc, char **argv)
{
	check_args(argc);
	ft_memset(&g_infos, 0, sizeof (t_infos));
	sigemptyset(&g_infos.sa.sa_mask);
	g_infos.sa.sa_flags = SA_SIGINFO;
	g_infos.sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &g_infos.sa, NULL);
	sigaction(SIGUSR2, &g_infos.sa, NULL);
	g_infos.server_pid = ft_atoi(argv[1]);
	send_str(g_infos.server_pid, argv[2]);
	while (!g_infos.server_response)
		usleep(1);
	ft_printf("Sent message to pid:%d\n", g_infos.server_pid);
	return (0);
}
