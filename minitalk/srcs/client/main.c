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

#include "../../client.h"

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

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	ptr = malloc(n * size);
	ft_memset(ptr, 0, n * size);
	return (ptr);
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
	printf("\n");
}

int main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	return (0);
}
