/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:08:30 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 16:08:34 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**split_and_check(char *arg)
{
	int		i;
	char	**split_arg;

	split_arg = ft_split(arg, ' ');
	i = 0;
	while (split_arg[i])
	{
		if (ft_strlen(split_arg[i]) == 0 || !is_number(split_arg[i]))
		{
			free_tab(split_arg);
			print_error_and_exit();
		}
		i++;
	}
	return (split_arg);
}

t_params	split_input(char **argv)
{
	int			i;
	char		**split_arg;
	int			*result;
	t_params	params;

	split_arg = split_and_check(argv[1]);
	i = 0;
	while (split_arg[i])
		i++;
	result = calloc(i, sizeof(int));
	if (!result)
	{
		free_tab(split_arg);
		print_error_and_exit();
	}
	i = 0;
	while (split_arg[i])
	{
		result[i] = ft_atoi(split_arg[i]);
		i++;
	}
	free_tab(split_arg);
	params.size = i;
	params.values = result;
	return (params);
}
