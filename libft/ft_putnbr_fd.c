/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:19:48 by mernser           #+#    #+#             */
/*   Updated: 2018/12/12 21:21:32 by mernser          ###   ########.fr       */
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

void		ft_putnbr_fd(int n, int fd)
{
	char	d;
	int		i;
	int		c;

	i = 1;
	if (fd < 0)
		return ;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (n < 0)
	{
		i = -1;
		ft_putchar_fd('-', fd);
	}
	c = ft_count_digits(n);
	while (c--)
	{
		d = i * ((n / ft_power_ten(c)) % 10) + '0';
		ft_putchar_fd(d, fd);
	}
}
