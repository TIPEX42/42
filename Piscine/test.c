#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	copy = malloc(ft_strlen(src) + 1);
	if (copy == 0)
		return (0);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int main(void)
{
	char src[] = "Bonjour !";
	char *copy = ft_strdup(src);
	printf("%s\n", src);
	printf("%s\n", copy);
	free(copy);
	printf("%s\n", copy);
} 
