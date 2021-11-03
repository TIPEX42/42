#include "libft.h"

static int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	new = malloc((ft_min(ft_strlen(s) - start, len) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s[start], ft_min(ft_strlen(s) - start, len) + 1);
	return (new);
}