/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:29:16 by mernser           #+#    #+#             */
/*   Updated: 2018/12/15 20:25:58 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	i;
	size_t	d;

	d = 0;
	if (f == NULL || s == NULL)
		return ;
	if (*s == '\0')
		return ;
	i = ft_strlen(s);
	while (i > 0)
	{
		f(&s[d]);
		d++;
		i--;
	}
	return ;
}
