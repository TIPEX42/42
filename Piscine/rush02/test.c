#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
	return (str);
}

char	**ft_parse_input(char *str)
{
	int		i;
	//int		j;
	char	**result;
	
	ft_strrev(str);
	if (ft_strlen(str) % 3 > 0)
		result = malloc(ft_strlen(str) / 3 + 1);
	else
		result = malloc(ft_strlen(str) / 3);
	
	if (!result)
		return (0);
	i = 0;
	while (i < ft_strlen(str) / 3)
	{
		result[i] = malloc(4);
		if (!result[i])
			return (0);
		result[i][0] = str[i * 3];
		result[i][1] = str[i * 3 + 1];
		result[i][2] = str[i * 3 + 2];
		result[i][3] = 0;
		ft_strrev(result[i]);
		i++;
	}
	/*
	result[i] = malloc(ft_strlen(str) % 3 + 1);
	if (!result[i])
		return (0);
	j = 0;
	while (i * 3 + j < ft_strlen(str))
	{
		result[i][j] = str[i * 3 + j];
		j++;
	}
	result[i][j] = 0;
	*/
	ft_strrev(result[i]);
	return (result);
}

int main(int argc, char **argv) 
{
	argc = 0;
	char **result = ft_parse_input(argv[1]);
	printf("%s\n", result[0]);
	printf("%s\n", result[1]);
	printf("%s\n", result[2]);
	return 0;
}