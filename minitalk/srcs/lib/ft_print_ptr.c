/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:41:05 by njennes           #+#    #+#             */
/*   Updated: 2021/11/24 15:32:17 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libtalk.h"

void	ft_print_ptr(va_list *parameters_infos, int *chars_printed)
{
	long	ptr;

	ptr = (long)va_arg(*parameters_infos, size_t);
	write(1, "0x", 2);
	(*chars_printed) += 2;
	ft_putnbr_base(ptr, "0123456789abcdef", chars_printed);
}
