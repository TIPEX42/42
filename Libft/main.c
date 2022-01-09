#include "libft.h"

void	dprint(t_dict *dict)
{
	printf("Dictionary : ------\n");
	for (int i = 0; i < dict->capacity - 1; i++)
	{
		if (dict->items[i * sizeof(t_dict_node)].key)
			printf("\tKey: %s, Value: %f\n", dict->items[i * sizeof(t_dict_node)].key, dict->items[i * sizeof(t_dict_node)].value);
		else
			printf("\t----\n");
	}
}

int main()
{
	t_dict dict = dict_create();
	dprint(&dict);
}