/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:34:39 by mernser           #+#    #+#             */
/*   Updated: 2018/12/15 20:33:20 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	d;

	d = 0;
	if (f == NULL || s == NULL)
		return ;
	if (*s == '\0')
		return ;
	i = ft_strlen(s);
	while (i > 0)
	{
		i--;
		f(d, &s[d]);
		d++;
	}
	return ;
}
