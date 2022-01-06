/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:21:59 by                   #+#    #+#             */
/*   Updated: 2022/01/05 18:21:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
