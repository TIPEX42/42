/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:51:56 by njennes           #+#    #+#             */
/*   Updated: 2021/08/09 13:51:58 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	error;

	error = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
		{
			error++;
		}
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			error++;
		}
		i = i + 1;
		if (error == 2)
		{
			return (0);
		}
		error = 0;
	}
	return (1);
}
