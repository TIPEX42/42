/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:21:21 by njennes           #+#    #+#             */
/*   Updated: 2021/08/18 14:38:42 by njennes          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

double	ft_abs(double nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	ft_sqrt(int nb)
{
	double	guess;
	double	nbcpy;

	nbcpy = (double)nb;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (0);
	guess = 1.0;
	while (ft_abs(guess - ((nbcpy / guess) + guess) / 2.0) > 0.005)
		guess = ((nbcpy / guess) + guess) / 2.0;
	if ((int)guess * (int)guess == nb)
		return ((int)guess);
	return (0);
}

int	ft_is_prime(int nb)
{
	int	sqrt;
	int	div;
	int	nbcpy;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	nbcpy = nb;
	while (ft_sqrt(nbcpy) == 0 && nbcpy > 0)
	{
		nbcpy--;
	}
	sqrt = ft_sqrt(nbcpy);
	div = 2;
	while (div <= sqrt && (nb / div) * div != nb)
		div++;
	if ((nb / div) * div == nb)
		return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
