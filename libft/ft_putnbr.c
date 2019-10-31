/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:01:31 by mernser           #+#    #+#             */
/*   Updated: 2018/12/12 21:04:04 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digits(int n)
{
	int	counter;

	counter = 0;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static int	ft_power_ten(int p)
{
	int	d;

	d = 1;
	if (p == 0)
		return (1);
	while (p--)
		d = d * 10;
	return (d);
}

void		ft_putnbr(int n)
{
	char	d;
	int		i;
	int		c;

	i = 1;
	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n < 0)
	{
		i = -1;
		ft_putchar('-');
	}
	c = ft_count_digits(n);
	while (c--)
	{
		d = i * ((n / ft_power_ten(c)) % 10) + '0';
		ft_putchar(d);
	}
}
