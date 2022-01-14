/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:40:55 by njennes           #+#    #+#             */
/*   Updated: 2021/11/25 17:37:58 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *str, ...);

void	ft_print_char(va_list *parameters_infos, int *chars_printed);
void	ft_print_str(va_list *parameters_infos, int *chars_printed);
void	ft_print_decimal(va_list *parameters_infos, int *chars_printed);
void	ft_print_integer(va_list *parameters_infos, int *chars_printed);
void	ft_print_uinteger(va_list *parameters_infos, int *chars_printed);
void	ft_print_hex(va_list *parameters_infos, int *chars_printed);
void	ft_print_hex_big(va_list *parameters_infos, int *chars_printed);
void	ft_print_ptr(va_list *parameters_infos, int *chars_printed);
void	ft_putnbr_base(size_t nbr, char *base, int *chars_printed);
void	ft_putnbr_fd(long n, int fd, int *chars_printed);
size_t	ft_strlen(const char *str);

#endif