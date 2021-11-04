#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_read_file(char	*path);
int	ft_my_ln(unsigned long long number);
int	ft_strlen(char *str, char second);
char	*ft_num_to_letters(char	*comb, int offset, int max, char ***dict);
int	ft_check_number(char *str);
char	**ft_parse_input(char *str);
char	*ft_realloc(char *str, char *buffer, int size);

unsigned long long	ft_atoi(char *str)
{
	unsigned long long	nb;
	int					moins;
	int					passed;

	nb = 0;
	moins = 1;
	passed = 0;
	while (*str != '+' && *str != '-' && *str < 33)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			moins *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + ((int)*str - '0');
		str++;
		passed = 1;
	}
	if (!passed)
		return (-1);
	return (nb * moins);
}

char	*ft_get_next_line(char *str, int *index)
{
	int		length;
	int		i;
	char	*line;

	length = 0;
	i = 0;
	while (str[(*index) + i] != '\n' && str[(*index) + i] != '\0')
	{
		i++;
		length++;
	}
	line = malloc(length + 1);
	if (!line)
		return(0);
	i = 0;
	while (i < length)
	{
		line[i] = str[*index + i];
		i++;
	}
	*index = *index + length + 1;
	line[i] = '\0';
	return (line);
}

char	***ft_allocate_dict(int units, int tens, int thousands)
{
	char	***dict;

	dict = malloc(3 * sizeof(char*));
	if (!dict)
		return (0);
	dict[0] = malloc(units * sizeof(char*));
	if (!dict[0])
		return (0);
	dict[1] = malloc(tens * sizeof(char*));
	if (!dict[1])
		return (0);
	dict[2] = malloc(thousands * sizeof(char*));
	if (!dict[2])
		return (0);
	return (dict);
}

int	ft_validate(char *line)
{
	int	i;

	i = 0;
	while (line[i] < 33)
		i++;
	while (line[i] == '-' || line[i] == '+')
		i++;
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] == ':')
		i++;
	while (line[i] == ' ')
		i++;
	while (line[i] >= 33 && line[i] <= 126)
		i++;
	if (line[i] == '\0')
		return (1);
	return (0);
}

int	ft_get_number_length(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[i] < 33)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		length++;
	}
	return (length);
}

int	ft_is_accepted_big_number(char *line)
{
	int	i;
	int	zeros;

	i = 0;
	while (line[i] < 33)
		i++;
	if (line[i] == '1')
	{
		i++;
		zeros = 0;
		while (line[i] == '0')
		{
			zeros++;
			i++;
		}
		if (zeros % 3 == 0 && zeros > 0)
			return (1);
	}
	return (0);
}

int	ft_is_accepted_number(char *line)
{
	int	result;
	int	number;

	if (ft_get_number_length(line) > 3)
		return (ft_is_accepted_big_number(line));
	result = ft_atoi(line);
	if (result < 0)
		return (0);
	if (result < 20)
		return (1);
	number = 20;
	while (number <= 100)
	{
		if (result == number)
			return (1);
		number = number + 10;
	}
	return (0);
}

char	*ft_get_value(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (line[i] != ':')
		i++;
	i++;
	while (line[i] == ' ')
		i++;
	str = malloc(ft_strlen(&line[i], '\n') + 1);
	if (!str)
		return (0);
	while (line[i] != '\0')
	{
		str[j] = line[i];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_add_to_dict(char ***dict, char *line)
{
	unsigned long long	number;

	number = ft_atoi(line);
	if (number < 20)
		dict[0][number] = ft_get_value(line);
	else if (number < 1000)
		dict[1][number / 10 - 2] = ft_get_value(line);
	else
		dict[2][ft_my_ln(number)] = ft_get_value(line);
}

int	ft_get_lines_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	count++;
	return (count);
}

char	**ft_get_lines(char *str)
{
	int		i;
	int		index;
	char	*current;
	char	**result;

	result = malloc((ft_get_lines_count(str) + 1) * sizeof(char*));
	if (!result)
		return (0);
	index = 0;
	i = 0;
	current = ft_get_next_line(str, &index);
	while (current[0] != 0)
	{
		result[i] = current;
		current = ft_get_next_line(str, &index);
		i++;
	}
	return (result);
}

int	ft_get_big_numbers_count(char **lines)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (lines[i] != 0)
	{
		if (ft_validate(lines[i]) && ft_is_accepted_big_number(lines[i]))
		{
			if (ft_get_number_length(lines[i]) - 1 > count)
				count = ft_get_number_length(lines[i]) - 1;
		}
		i++;
	}
	return (count / 3);
}

char	***ft_parse_str(char *str)
{
	int		i;
	char	**lines;
	char	***dict;

	lines = ft_get_lines(str);
	dict = ft_allocate_dict(20, 9, ft_get_big_numbers_count(lines));
	i = 0;
	while (lines[i] != 0)
	{
		if (ft_validate(lines[i]) && ft_is_accepted_number(lines[i]))
			ft_add_to_dict(dict, lines[i]);
		i++;
	}
	free(lines);
	return (dict);
}

int	ft_is_zeros(char *str, int offset)
{
	if (str[offset] == '0' && str[offset + 1] == '0' && str[offset + 2] == '0')
		return (1);
	return (0);
}

int	ft_is_all_zeros(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (str[i] == 0)
		return (1);
	return (0);
}

void	ft_put_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv) 
{
	char *str = ft_read_file("test.dict");
	char ***dict = ft_parse_str(str);
	
	argc = 0;
	if(!ft_check_number(argv[1]))
		return (0);


	char *result = malloc(1);
	if (!result)
		return (0);
	result[0] = 0;
	char *num;
	int offset;
	offset = 0;
	if (ft_is_all_zeros(str))
	{
		result = dict[0][0];
	}
	else
	{
		if (ft_strlen(argv[1], 0) % 3 > 0)
		{
			num = ft_num_to_letters(argv[1], 0, ft_strlen(argv[1], 0) % 3, dict);
			result = ft_realloc(result, num, ft_strlen(num, 0));
			result = ft_realloc(result, " ", 1);
			if (ft_strlen(argv[1], 0) > 3 && result[0] != 0)
			{
				if (dict[2][ft_strlen(argv[1], 0) / 3 - 1] != NULL)
				{
					result = ft_realloc(result, dict[2][ft_strlen(argv[1], 0) / 3 - 1], ft_strlen(dict[2][ft_strlen(argv[1], 0) / 3 - 1], 0));
				}
				else
				{
					write(1, "Dict Error\n", 11);
					return (0);
				}
			}
			offset = ft_strlen(argv[1], 0) % 3;
		}
		int i = 0;
		while (i < ft_strlen(argv[1], 0) / 3)
		{
			num = ft_num_to_letters(argv[1], offset, ft_strlen(argv[1], 0) % 3 + i * 3 + 3, dict);
			result = ft_realloc(result, num, ft_strlen(num, 0));
			result = ft_realloc(result, " ", 1);
			if (i + 1 != ft_strlen(argv[1], 0) / 3 && !ft_is_zeros(argv[1], offset))
			{
				if (dict[2][ft_strlen(argv[1], 0) / 3 - 2 - i] != NULL)
				{
					result = ft_realloc(result, dict[2][ft_strlen(argv[1], 0) / 3 - 2 - i], ft_strlen(dict[2][ft_strlen(argv[1], 0) / 3 - 2 - i], 0));
					result = ft_realloc(result, " ", 1);
				}
				else
				{
					write(1, "Dict Error\n", 11);
					return (0);
				}
			}
			offset += 3;
			i++;
		}
	}
	ft_put_str(result);
	return 0;
}