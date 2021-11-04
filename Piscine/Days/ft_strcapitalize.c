/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:20:43 by njennes           #+#    #+#             */
/*   Updated: 2021/08/10 14:20:44 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i = i + 1;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	ft_strlowcase(str);
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			error++;
		if (str[i] >= 'a' && str[i] <= 'z')
			error++;
		if (str[i] >= 'A' & str[i] <= 'Z')
		{
			error++;
		}
		if (str[i + 1] >= 'a' && str[i + 1] <= 'z' && error == 0)
			str[i + 1] = str[i + 1] - 32;
		i = i + 1;
		error = 0;
	}
	return (str);
}
