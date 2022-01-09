/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 17:31:57 by                   #+#    #+#             */
/*   Updated: 2022/01/09 19:03:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int dict_grow(t_dict *dict)
{
	t_dict_node	*new_items;
	size_t		new_cap;

	if (dict->capacity > 10000)
		new_cap = dict->capacity + 10000;
	else
		new_cap = dict->capacity * 2;
	new_items = ft_calloc(new_cap, sizeof(t_dict_node));
	if (!new_items)
		return (0);
	ft_memmove(new_items, dict->items, dict->capacity * sizeof(t_dict_node));
	free(dict->items);
	dict->items = new_items;
	dict->capacity = new_cap;
	return (1);
}

static size_t dict_hash(t_dict *dict, char *key)
{
	size_t	code;
	int	i;
	int	j;

	code = 0;
	i = 0;
	j = ft_strlen(key) - 1;
	while (key[i])
	{
		code += key[i];
		code *= key[j];
		code = code % dict->capacity;
		i++;
		j--;
	}
	return (code);
}

static size_t	dict_find_next_place(t_dict *dict, char *key)
{
	size_t	hash_code;

	hash_code = dict_hash(dict, key);
	while (dict->items[hash_code].key != NULL &&
		   dict->capacity / dict->size < dict->cap_size_ratio)
	{
		if (!dict_grow(dict))
			return (0);
		hash_code = dict_hash(dict, key);
	}
	while (dict->items[hash_code].key != NULL)
	{
		hash_code++;
		if (hash_code == dict->capacity)
			hash_code = 0;
	}
	return (hash_code);
}

int	dict_add(t_dict *dict, char *key, double value)
{
	t_dict_node	node;
	size_t		hash_code;

	if (!dict_exists(dict) || key == NULL)
		return (0);
	if (dict_key_exists(dict, key))
		return (0);
	node.key = key;
	node.value = value;
	hash_code = dict_find_next_place(dict, key);
	ft_memmove(dict->items, &node, sizeof(t_dict_node));
	dict->size++;
	return (1);
}
