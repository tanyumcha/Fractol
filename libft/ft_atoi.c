/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:07:05 by mernser           #+#    #+#             */
/*   Updated: 2018/12/22 16:45:23 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_skip(unsigned char **s, int *sign)
{
	while (**s == '\t' || **s == '\n' || **s == '\v'
	|| **s == '\f' || **s == '\r' || **s == ' ')
		(*s)++;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			*sign = -1;
		(*s)++;
	}
	while (**s == '0')
		(*s)++;
}

static int		ft_dgt(unsigned char *s)
{
	int	i;
	int	d;

	d = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]))
		{
			while (ft_isdigit(s[i]))
			{
				d++;
				i++;
			}
			return (d);
		}
		i++;
	}
	return (d);
}

int				ft_atoi(const char *str)
{
	long long		res;
	int				sign;
	int				length;
	unsigned char	*s;

	sign = 1;
	res = 0;
	s = (unsigned char *)str;
	ft_skip(&s, &sign);
	length = ft_dgt(s);
	while (*s > 47 && *s < 58)
	{
		res = res * 10 + (*s - '0');
		if (res < 0 || length > 19)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		s++;
	}
	return (sign * res);
}
