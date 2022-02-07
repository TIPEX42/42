/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:19:37 by njennes           #+#    #+#             */
/*   Updated: 2021/11/26 14:03:23 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libtalk.h"

void	ft_parse_param(const char *str, va_list *parameters, int *chars_printed)
{
	if (*str == 'c')
		ft_print_char(parameters, chars_printed);
	else if (*str == 's')
		ft_print_str(parameters, chars_printed);
	else if (*str == 'p')
		ft_print_ptr(parameters, chars_printed);
	else if (*str == 'd')
		ft_print_integer(parameters, chars_printed);
	else if (*str == 'i')
		ft_print_integer(parameters, chars_printed);
	else if (*str == 'u')
		ft_print_uinteger(parameters, chars_printed);
	else if (*str == 'x')
		ft_print_hex(parameters, chars_printed);
	else if (*str == 'X')
		ft_print_hex_big(parameters, chars_printed);
	else
	{
		write(1, str, 1);
		(*chars_printed)++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		chars_printed;
	va_list	parameters_infos;

	va_start(parameters_infos, str);
	i = 0;
	chars_printed = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			chars_printed++;
			i++;
		}
		else
		{
			i++;
			ft_parse_param(&str[i], &parameters_infos, &chars_printed);
			i++;
		}
	}
	va_end(parameters_infos);
	return (chars_printed);
}
