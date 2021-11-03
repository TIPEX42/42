#include "libft.h"

#include <stdio.h>
#include <string.h>

int main()
{
	printf("%d\n", atoi("+123"));
	printf("%d\n", atoi("+-123"));
	printf("%d\n", atoi("--123"));
	printf("%d\n", atoi("- 123"));
	printf("%d\n", atoi("+123a123"));
	printf("%d\n", atoi("123 123"));
	printf("%d\n", atoi("  - 123  06vrz"));
	printf("%d\n", atoi("+  -123"));

	char *test = "hey comment ca va ?";
	char *s1 = ft_substr(test, 3, 5);
	printf("%s\n", s1);
	free(s1);

}