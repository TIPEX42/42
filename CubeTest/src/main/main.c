/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:30:09 by njennes           #+#    #+#             */
/*   Updated: 2022/04/08 18:55:23 by njennes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "libft.h"
#include <stdio.h>

int	**generate_walls()
{
	size_t	i;
	size_t	j;
	int		**walls;

	walls = gc_calloc()
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{

		}
		i++;
	}
}

void	init_map(t_map *map)
{
	map->width = 10;
	map->height = 10;
	map->walls = generate_walls();
}

int main()
{
	t_map	map;

	init_map(&map);
	return (0);
}
