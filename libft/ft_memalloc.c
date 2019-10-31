/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:23:50 by mernser           #+#    #+#             */
/*   Updated: 2018/12/11 17:12:06 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*d;
	size_t			i;

	i = 0;
	if (size == 0)
	{
		d = NULL;
		return (d);
	}
	d = (unsigned char*)malloc((sizeof(*d) * size));
	if (d == NULL)
		return (NULL);
	while (size)
	{
		d[i] = '\0';
		size--;
		i++;
	}
	return (d);
}
