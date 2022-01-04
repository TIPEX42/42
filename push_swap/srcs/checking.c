/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:41:25 by njennes           #+#    #+#             */
/*   Updated: 2022/01/03 14:41:25 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atol(str) > INT_MAX || ft_atol(str) < INT_MIN)
		return (0);
	return (1);
}

t_params	get_input(int argc, char **argv)
{
	int			i;
	int			*result;
	t_params	params;

	if (argc == 2)
		return (split_input(argv));
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0 || !is_number(argv[i]))
			print_error_and_exit();
		i++;
	}
	result = ft_calloc(argc, sizeof(int));
	if (!result)
		print_error_and_exit();
	i = 0;
	while (i < argc - 1)
	{
		result[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	params.size = argc - 1;
	params.values = result;
	return (params);
}

int	check_for_doubles(t_params params)
{
	int	i;
	int	j;

	i = 0;
	while (i < params.size)
	{
		j = i + 1;
		while (j < params.size)
		{
			if (params.values[i] == params.values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_params	check_args(int argc, char **argv)
{
	t_params	params;

	if (argc == 1)
		exit(0);
	params = get_input(argc, argv);
	if (check_for_doubles(params))
	{
		free(params.values);
		print_error_and_exit();
	}
	return (params);
}
