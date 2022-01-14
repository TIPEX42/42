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

#include "../../server.h"

char	result = 0;
int		sigs = 0;
int		last = 0;
int		handling = 0;

void	signal_handler(int signo)
{
	while (handling);
	handling = 1;
	if (signo == SIGUSR2 && last != SIGUSR1)
	{
		result = result * 2;
		sigs++;
	}
	else if (signo == SIGUSR1)
	{
		result = result * 2 + 1;
		sigs++;
	}
	last = signo;
	if (sigs == 8)
	{
		ft_printf("%c", result);
		result = 0;
		sigs = 0;
	}
	handling = 0;
	return;
}

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

int main()
{
	pid_t	pid;

	pid = getpid();

	struct sigaction sa;
	ft_memset(&sa, 0, sizeof (struct sigaction));
	sa.sa_handler = signal_handler;
	//sigaction (SIGUSR1, &sa, NULL);
	//sigaction (SIGUSR2, &sa, NULL);
	signal(SIGUSR2, signal_handler);
	signal(SIGUSR1, signal_handler);
	ft_printf("%d\n", pid);
	while (1)
	{
		sleep(1);
	}
}
