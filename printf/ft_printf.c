/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 14:19:37 by njennes           #+#    #+#             */
/*   Updated: 2021/11/22 17:19:21 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#include "libft.h"

void	ft_parse_param(const char *str, va_list *parameters_infos);
void	ft_print_char(va_list *parameters_infos);
void	ft_print_str(va_list *parameters_infos);
void	ft_print_decimal(va_list *parameters_infos);
void	ft_print_integer(va_list *parameters_infos);
void	ft_print_uinteger(va_list *parameters_infos);
void	ft_print_hex(va_list *parameters_infos);
void	ft_print_hex_big(va_list *parameters_infos);
void	ft_print_ptr(va_list *parameters_infos);
void	ft_putnbr_base(long nbr, char *base);

void	ft_putnbr(char *result)
{
	result += 32;
	while (*result != -1)
	{
		if (*result != -2)
			write(1, result, 1);
		result--;
	}
}

void	ft_prepare_list(char *result)
{
	int	i;

	i = 0;
	while (i < 33)
	{
		result[i] = -2;
		i++;
	}
	result[0] = -1;
}

void	ft_putnbr_base(long nbr, char *base)
{
	int		r;
	char	result[33];
	int		i;

	ft_prepare_list(result);
	i = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	while (nbr != 0 || result[i] == -1)
	{
		i++;
		r = nbr % ft_strlen(base);
		nbr = nbr / ft_strlen(base);
		result[i] = base[r];
	}
	ft_putnbr(result);
}

int	ft_printf(const char *str, ...)
{
	int	i;
    va_list parameters_infos;
    
	va_start(parameters_infos, str);
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
		}
		else
		{
			i++;
			ft_parse_param(&str[i], &parameters_infos);
			i++;
		}
	}
	va_end(parameters_infos);
	return (0);
}

void	ft_parse_param(const char *str, va_list *parameters_infos)
{
	if (*str == 'c')
		ft_print_char(parameters_infos);
	else if (*str == 's')
		ft_print_str(parameters_infos);
	else if (*str == 'p')
		ft_print_ptr(parameters_infos);
	else if (*str == 'd')
		ft_print_integer(parameters_infos);
	else if (*str == 'i')
		ft_print_integer(parameters_infos);
	else if (*str == 'u')
		ft_print_uinteger(parameters_infos);
	else if (*str == 'x')
		ft_print_hex(parameters_infos);
	else if (*str == 'X')
		ft_print_hex_big(parameters_infos);
	else if (*str == '%')
		write(1, "%%", 1);
}

void	ft_print_char(va_list *parameters_infos)
{
	char	c;

	c = (char)va_arg(*parameters_infos, int);
	write(1, &c, 1);
}

void	ft_print_str(va_list *parameters_infos)
{
	char	*s;

	s = (char *)va_arg((*parameters_infos), const char *);
	write(1, s, ft_strlen(s));
}

void	ft_print_integer(va_list *parameters_infos)
{
	int	integer;

	integer = (int)va_arg(*parameters_infos, int);
	ft_putnbr_fd(integer, 1);
}

void	ft_print_uinteger(va_list *parameters_infos)
{
	unsigned int	integer;

	integer = (unsigned int)va_arg(*parameters_infos, unsigned int);
	ft_putnbr_fd(integer, 1);
}

void	ft_print_hex(va_list *parameters_infos)
{
	long	integer;

	integer = (long)va_arg(*parameters_infos, long);
	ft_putnbr_base(integer, "0123456789abcdef");
}

void	ft_print_hex_big(va_list *parameters_infos)
{
	long	integer;

	integer = (long)va_arg(*parameters_infos, long);
	ft_putnbr_base(integer, "0123456789ABCDEF");
}

void	ft_print_ptr(va_list *parameters_infos)
{
	void	*ptr;

	ptr = (void *)va_arg(*parameters_infos, void *);
	write(1, "0x", 2);
	ft_putnbr_base(((unsigned long)ptr), "0123456789abcdef");
}

void	ft_print_decimal(va_list *parameters_infos)
{
	int		integer_part;
	double	decimal_part;
	double	decimal;

	decimal = (double)va_arg(*parameters_infos, double);
	integer_part = (int)decimal;
	decimal_part = decimal - (double)integer_part;
	while (decimal_part - (long)decimal_part > 0.00001)
		decimal_part *= 10;
	ft_putnbr_base(integer_part, "0123456789");
	write(1, ".", 1);
	ft_putnbr_base(decimal_part, "0123456789");
}
