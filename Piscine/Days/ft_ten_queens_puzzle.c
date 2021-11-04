/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:47:19 by njennes           #+#    #+#             */
/*   Updated: 2021/08/18 17:17:59 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_init_queens(int queens[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		queens[i] = -1;
		i++;
	}
}

void	ft_show_board(int queens[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = '0' + queens[i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_check(int queens[10], int depth)
{
	int	i;

	i = 0;
	if (queens[depth] == -1)
		return (0);
	while (i < 10)
	{
		if (i != depth && queens[i] != -1)
		{
			if (queens[i] == queens[depth])
				return (0);
			if (depth - i == queens[i] - queens[depth] || \
			-(depth - i) == queens[i] - queens[depth])
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_move_queens(int queens[10], int depth, int *result)
{
	while (queens[depth] < 9)
	{
		queens[depth]++;
		if (!ft_check(queens, depth))
			continue ;
		else if (depth == 9)
		{
			ft_show_board(queens);
			*result = *result + 1;
		}
		else
			ft_move_queens(queens, depth + 1, result);
	}
	queens[depth] = -1;
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	result;

	result = 0;
	ft_init_queens(queens);
	ft_move_queens(queens, 0, &result);
	return (result);
}
