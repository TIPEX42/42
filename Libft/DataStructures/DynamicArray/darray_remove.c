/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:31:35 by njennes           #+#    #+#             */
/*   Updated: 2022/01/09 17:15:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	darray_remove(t_darray *array, size_t index)
{
	void	*from;
	void	*to;
	size_t	len;

	if (index >= array->size || index < 0)
		return ;
	if (index == array->size - 1)
	{
		array->size--;
		return ;
	}
	from = array->items + (index + 1) * array->item_size;
	to = from - array->item_size;
	len = (array->size - (index + 1)) * array->item_size;
	ft_memmove(to, from, len);
	array->size--;
}
