/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:30:02 by mernser           #+#    #+#             */
/*   Updated: 2018/12/12 19:44:27 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count_digits(int *d, int *i, int *flag, int *n)
{
	if (*d != 0)
	{
		while (*d != 0)
		{
			*d = *d / 10;
			(*i)++;
		}
	}
	else
		*i = 1;
	*d = *n;
	if (*d < 0)
	{
		*flag = -1;
		(*i)++;
	}
	return ;
}

char		*ft_itoa(int n)
{
	int		flag;
	int		d;
	int		i;
	char	*str;

	flag = 1;
	d = n;
	i = 0;
	ft_count_digits(&d, &i, &flag, &n);
	str = (char*)malloc(sizeof(*str) * i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (--i != -1)
	{
		str[i] = flag * (n % 10) + '0';
		n = n / 10;
		if (i == 0 && d < 0)
		{
			str[i] = '-';
			return (str);
		}
	}
	return (str);
}
