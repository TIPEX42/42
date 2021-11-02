#include "libft.h"

#include <stdio.h>
#include <string.h>

#define TEST_EQ1(name, fun1, fun2, param) if (fun1(param) != fun2(param)) {printf("%s [FAILED] at line: %d in %s\n", name, __LINE__, __FILE__);}
#define TEST_EQ2(name, fun1, fun2, param1, param2) if (fun1(param1, param2) != fun2(param1, param2)) {printf("%s [FAILED] at line: %d in %s\n", name, __LINE__, __FILE__);}
#define TEST_EQ3(name, fun1, fun2, param1, param2, param3) if (fun1(param1, param2, param3) != fun2(param1, param2, param3)) {printf("%s [FAILED] at line: %d in %s\n", name, __LINE__, __FILE__);}


int main()
{
	TEST_EQ1("strlen", ft_strlen, strlen, "hey")
	TEST_EQ1("strlen", ft_strlen, strlen, "")

	TEST_EQ3("strnstr", ft_strnstr, strnstr, "hey", "e", -1)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "hey", "e", 0)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "hey", "e", 1)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "hey", "e", 2)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "hey", "h", -1)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "hey", "h", 0)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "hey", "h", 1)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "hey", "h", 2)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "hey", "", -1)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "hey", "", 0)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "hey", "", 1)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "hey", "", 2)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "", "h", -1)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "", "h", 0)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "", "h", 1)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "", "h", 2)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "", "", -1)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "", "", 0)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "", "", 1)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "", "", 2)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "comment ca va", "g", -1)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "comment ca va", "g", 0)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "comment ca va", "g", 10)
	TEST_EQ3("strnstr", ft_strnstr, strnstr, "comment ca va", "g", 20)

	TEST_EQ2("strchr", ft_strchr, strchr, "hey", 'a')
	TEST_EQ2("strchr", ft_strchr, strchr, "hey", 'e')
	TEST_EQ2("strchr", ft_strchr, strchr, "hey", 'b')
	TEST_EQ2("strchr", ft_strchr, strchr, "hey", 0)
	TEST_EQ2("strchr", ft_strchr, strchr, "", 'a')
	TEST_EQ2("strchr", ft_strchr, strchr, "", 'e')
	TEST_EQ2("strchr", ft_strchr, strchr, "", 'b')
	TEST_EQ2("strchr", ft_strchr, strchr, "", 0)
	TEST_EQ2("strchr", ft_strchr, strchr, "comment ca va", 'a')
	TEST_EQ2("strchr", ft_strchr, strchr, "comment ca va", 'e')
	TEST_EQ2("strchr", ft_strchr, strchr, "comment ca va", 'b')
	TEST_EQ2("strchr", ft_strchr, strchr, "comment ca va", ' ')
	TEST_EQ2("strchr", ft_strchr, strchr, "comment ca va", 0)

	TEST_EQ2("strrchr", ft_strrchr, strrchr, "hey", 'a')
	TEST_EQ2("strrchr", ft_strrchr, strrchr, "hey", 'e')
	TEST_EQ2("strrchr", ft_strrchr, strrchr, "hey", 'b')
	TEST_EQ2("strrchr", ft_strrchr, strrchr, "hey", 0)
	TEST_EQ2("strrchr", ft_strrchr, strrchr, "", 'a')
	TEST_EQ2("strrchr", ft_strrchr, strrchr, "", 'e')
	TEST_EQ2("strrchr", ft_strrchr, strrchr, "", 'b')
	TEST_EQ2("strrchr", ft_strrchr, strrchr, "", 0)
	TEST_EQ2("strrchr", ft_strrchr, strrchr, "comment ca va", 'a')
	TEST_EQ2("strrchr", ft_strrchr, strrchr, "comment ca va", 'e')
	TEST_EQ2("strrchr", ft_strrchr, strrchr, "comment ca va", 'b')
	TEST_EQ2("strrchr", ft_strrchr, strrchr, "comment ca va", ' ')
	TEST_EQ2("strrchr", ft_strrchr, strrchr, "comment ca va", 0)

	TEST_EQ3("strncmp", ft_strncmp, strncmp, "hey", "e", -1)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "hey", "e", 0)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "hey", "e", 1)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "hey", "e", 2)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "hey", "heyy", -1)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "hey", "heyy", 0)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "hey", "heyy", 1)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "hey", "heyy", 5)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "hey", "", -1)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "hey", "", 0)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "hey", "", 1)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "hey", "", 2)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "", "h", -1)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "", "h", 0)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "", "h", 1)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "", "h", 2)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "", "", -1)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "", "", 0)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "", "", 1)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "", "", 2)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "comment ca va", "g", -1)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "comment ca va", "g", 0)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "comment ca va", "g", 10)
	TEST_EQ3("strncmp", ft_strncmp, strncmp, "comment ca va", "g", 20)

	char *test = "hey comment ca va ?";
	char *s1 = ft_strdup(test);
	char *s2 = strdup(test);
	if (ft_strncmp(s1, s2, 10000))
		printf("[FAILED] strdup \n");
	free(s1);
	free(s2);
	test = "";
	s1 = ft_strdup(test);
	s2 = strdup(test);
	if (ft_strncmp(s1, s2, 10000))
		printf("[FAILED] strdup2 \n");
	free(s1);
	free(s2);

	s1 = calloc(20, sizeof(char));
	s2 = calloc(20, sizeof(char));
	ft_strlcat(s1, "hey", 20);
	strlcat(s2, "hey", 20);
	if (ft_strncmp(s1, s2, 10000))
		printf("[FAILED] strlcat1 \n");
	ft_strlcat(s1, "koment ca va ? mwa ui", 20);
	strlcat(s2, "koment ca va ? mwa ui", 20);
	if (ft_strncmp(s1, s2, 10000))
		printf("[FAILED] strlcat2 \n");
	free(s1);
	free(s2);

	printf("%d\n", atoi("+123"));
	printf("%d\n", atoi("+-123"));
	printf("%d\n", atoi("--123"));
	printf("%d\n", atoi("- 123"));
	printf("%d\n", atoi("+123"));
	printf("%d\n", atoi("+123"));
	printf("%d\n", atoi("+123"));
	printf("%d\n", atoi("+123"));

}