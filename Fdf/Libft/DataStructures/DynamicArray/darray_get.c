/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:31:35 by njennes           #+#    #+#             */
/*   Updated: 2021/11/05 16:41:39 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*darray_get(t_darray *array, size_t index)
{
	if (index >= array->size)
		return (NULL);
	return (array->items + index * array->item_size);
}
