/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:37:26 by                   #+#    #+#             */
/*   Updated: 2022/01/25 19:02:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	**grow_tab(t_gc *gc, int **old_tab, int old_cap)
{
	int	**new_tab;

	new_tab = gc_calloc(gc, old_cap + 1, sizeof(int **));
	if (old_tab)
	{
		ft_memmove(new_tab, old_tab, old_cap * sizeof(int **));
		gc_free(gc, old_tab);
	}
	return (new_tab);
}

void	populate_heights(t_map_info *map, int *heights,
							int *colors, char **split)
{
	int	size;
	int	i;
	int	j;

	size = ft_split_size(split);
	i = 0;
	while (i < size)
	{
		heights[i] = ft_atoi(split[i]);
		if (heights[i] > map->highest_point)
			map->highest_point = heights[i];
		if (heights[i] < map->lowest_point)
			map->lowest_point = heights[i];
		j = 0;
		while (ft_isdigit(split[i][j]))
			j++;
		if (split[i][j] == ',')
		{
			j += 3;
			colors[i] = ft_atol_base(split[i] + j, "0123456789abcdef");
		}
		else
			colors[i] = get_color(0, 255, 255, 255);
		i++;
	}
}

void	add_heights(t_gc *gc, t_map_info *map, char *line)
{
	char	**heights_split;
	int		*new_heights;
	int		*new_colors;
	int		size;

	map->heights = grow_tab(gc, map->heights, map->size_z);
	map->colors = grow_tab(gc, map->colors, map->size_z);
	heights_split = ft_split(line, ' ');
	if (!heights_split)
	{
		free(line);
		gc->callback(gc->param);
	}
	size = ft_split_size(heights_split);
	map->size_x = size;
	new_heights = gc_calloc(gc, size, sizeof(int));
	new_colors = gc_calloc(gc, size, sizeof(int));
	populate_heights(map, new_heights, new_colors, heights_split);
	map->heights[map->size_z] = new_heights;
	map->colors[map->size_z] = new_colors;
	ft_split_free(heights_split);
	free(line);
}

void	load_map(t_gc *gc, t_map_info *infos, char *file)
{
	char		*line;
	int			fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		ft_error_exit("Couldn't open the file\n");
	line = ft_get_next_line(fd);
	infos->size_z = 0;
	infos->heights = NULL;
	infos->lowest_point = INT_MAX;
	infos->highest_point = INT_MIN;
	while (line)
	{
		ft_trimr(line);
		add_heights(gc, infos, line);
		infos->size_z++;
		line = ft_get_next_line(fd);
	}
	close(fd);
}
