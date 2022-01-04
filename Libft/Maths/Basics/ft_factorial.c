long	ft_fact(long value)
{
	long	result;

	result = 1;
	while (value > 0)
	{
		result *= value;
		value--;
	}
	return (result);
}