/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:41:13 by njennes           #+#    #+#             */
/*   Updated: 2021/11/25 17:28:47 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libtalk.h"
#include <limits.h>

void	ft_print_hex_big(va_list *parameters_infos, int *chars_printed)
{
	unsigned int	integer;

	integer = (unsigned int)va_arg(*parameters_infos, unsigned int);
	ft_putnbr_base(integer, "0123456789ABCDEF", chars_printed);
}
