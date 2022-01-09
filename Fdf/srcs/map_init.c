/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:26:50 by                   #+#    #+#             */
/*   Updated: 2022/01/09 15:06:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_vec4	**generate_verticies(t_map_info *infos)
{
	t_vec4	**tab;
	int		i;
	int		j;

	tab = ft_calloc(infos->size_z, sizeof(t_vec4));
	if (!tab)
		ft_error_exit("Allocation error\n");
	i = 0;
	while (i < infos->size_z)
	{
		tab[i] = ft_calloc(infos->size_x, sizeof(t_vec4));
		if (!tab[i])
			ft_error_exit("Allocation error\n");
		j = 0;
		while (j < infos->size_x)
		{
			tab[i][j] = vec4(j - infos->size_x / 2, infos->heights[i][j], i - infos->size_z / 2, 1);
			j++;
		}
		i++;
	}
	return (tab);
}

t_vec4	**init_projections(t_map_info *infos)
{
	t_vec4	**tab;
	int		i;

	tab = ft_calloc(infos->size_z, sizeof(t_vec4));
	if (!tab)
		ft_error_exit("Allocation error\n");
	i = 0;
	while (i < infos->size_z)
	{
		tab[i] = ft_calloc(infos->size_x, sizeof(t_vec4));
		if (!tab[i])
			ft_error_exit("Allocation error\n");
		i++;
	}
	return (tab);
}

int	**init_colors(t_map_info *infos, t_vec3 base_color, t_vec3 high_color)
{
	float	gradient;
	int		**tab;
	int		i;
	int		j;

	tab = ft_calloc(infos->size_z, sizeof(int));
	if (!tab)
		ft_error_exit("Allocation error\n");
	i = 0;
	while (i < infos->size_z)
	{
		tab[i] = ft_calloc(infos->size_x, sizeof(int));
		if (!tab[i])
			ft_error_exit("Allocation error\n");
		j = 0;
		while (j < infos->size_x)
		{
			gradient = ft_ilerpf(infos->lowest_point, infos->highest_point,
								 infos->heights[i][j]);
			tab[i][j] = get_colorv3(vec3_lerpf(base_color, high_color, gradient));
			j++;
		}
		i++;
	}
	return (tab);
}

void	create_map(t_map *map, char *file)
{
	t_vec3	base_color;
	t_vec3	high_color;

	base_color = vec3(200, 200, 200);
	high_color = vec3(255, 100, 100);
	load_map(&map->infos, file);
	map->pos = vec3(1920 / 2, 1080 / 2, 0);
	map->rotation = vec3_zero();
	map->scale = vec3(50, 5, 50);
	map->verticies = generate_verticies(&map->infos);
	map->projection = init_projections(&map->infos);
	map->colors = init_colors(&map->infos, base_color, high_color);
}