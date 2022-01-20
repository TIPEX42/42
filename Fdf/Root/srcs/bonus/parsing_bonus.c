/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:37:26 by                   #+#    #+#             */
/*   Updated: 2022/01/09 14:31:43 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	get_map_width(char *line)
{
	int	i;
	int	width;

	if (!line)
		return (0);
	width = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			width++;
			while (line[i] && ft_isdigit(line[i]))
				i++;
		}
		i++;
	}
	return (width);
}

int	**grow_tab(int **old_tab, int old_cap)
{
	int	**new_tab;

	new_tab = ft_calloc(old_cap + 1, sizeof(int **));
	if (!new_tab)
		ft_error_exit("Allocation Error\n");
	if (old_tab)
	{
		ft_memmove(new_tab, old_tab, old_cap * sizeof(int **));
		free(old_tab);
	}
	return (new_tab);
}

void	populate_new_heights(t_map_info *map, int *new_heights, char **split)
{
	int	size;
	int	i;

	size = ft_split_size(split);
	i = 0;
	while (i < size)
	{
		new_heights[i] = ft_atoi(split[i]);
		if (new_heights[i] > map->highest_point)
			map->highest_point = new_heights[i];
		if (new_heights[i] < map->lowest_point)
			map->lowest_point = new_heights[i];
		i++;
	}
}

void	add_heights(t_map_info *map, char *line)
{
	char	**heights_split;
	int		*new_heights;
	int		size;

	map->heights = grow_tab(map->heights, map->size_z);
	heights_split = ft_split(line, ' ');
	if (!heights_split)
		ft_error_exit("Allocation Error\n");
	size = ft_split_size(heights_split);
	new_heights = ft_calloc(size, sizeof(int));
	if (!new_heights)
		ft_error_exit("Allocation Error\n");
	populate_new_heights(map, new_heights, heights_split);
	map->heights[map->size_z] = new_heights;
	ft_split_free(heights_split);
	free(line);
}

void	load_map(t_map_info *infos, char *file)
{
	char		*line;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_error_exit("Couldn't open the file\n");
	line = ft_get_next_line(fd);
	infos->size_x = get_map_width(line);
	infos->size_z = 0;
	infos->heights = NULL;
	infos->lowest_point = INT_MAX;
	infos->highest_point = INT_MIN;
	while (line)
	{
		add_heights(infos, line);
		infos->size_z++;
		line = ft_get_next_line(fd);
	}
	close(fd);
}
