/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:02:53 by                   #+#    #+#             */
/*   Updated: 2022/01/09 18:22:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

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

double	dict_get(t_dict *dict, char *key)
{
	size_t	hash_code;
	size_t	start;

	if (!dict_exists(dict) || key == NULL)
		return (0);
	hash_code = dict_hash(dict, key);
	start = hash_code;
	while (dict->items[hash_code].key == NULL ||
			ft_strncmp(key, dict->items[hash_code].key, ft_strlen(key)) != 0)
	{
		hash_code++;
		if (hash_code == dict->capacity)
			hash_code = 0;
		if (hash_code == start)
			return (0);
	}
	return (dict->items[hash_code].value);
}

int	dict_key_exists(t_dict *dict, char *key)
{
	size_t	hash_code;
	size_t	start;

	if (!dict_exists(dict) || key == NULL)
		return (0);
	hash_code = dict_hash(dict, key);
	start = hash_code;
	while (dict->items[hash_code].key == NULL ||
		   ft_strncmp(key, dict->items[hash_code].key, ft_strlen(key)) != 0)
	{
		hash_code++;
		if (hash_code == dict->capacity)
			hash_code = 0;
		if (hash_code == start)
			return (0);
	}
	return (1);
}
