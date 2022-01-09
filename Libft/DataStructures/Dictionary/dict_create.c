/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:21:03 by                   #+#    #+#             */
/*   Updated: 2022/01/09 18:03:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_dict	dict_create()
{
	t_dict	dict;

	dict.size = 0;
	dict.capacity = 10;
	dict.cap_size_ratio = 5;
	dict.items = ft_calloc(dict.capacity, sizeof(t_dict_node));
	if (!dict.items)
		dict.items = NULL;
	return (dict);
}

int	dict_exists(t_dict *dict)
{
	if (dict == NULL)
		return (0);
	return (dict->items != NULL);
}
