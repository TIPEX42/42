/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:41:09 by njennes           #+#    #+#             */
/*   Updated: 2021/11/24 15:16:21 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_print_integer(va_list *parameters_infos, int *chars_printed)
{
	int	integer;

	integer = (int)va_arg(*parameters_infos, int);
	ft_putnbr_fd(integer, 1);
}
