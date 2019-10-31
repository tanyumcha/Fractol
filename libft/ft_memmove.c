/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:28:00 by mernser           #+#    #+#             */
/*   Updated: 2018/12/21 21:26:14 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	size_t			d;

	d = len;
	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
		return (dst);
	}
	else if (dst > src)
	{
		while (i < d)
		{
			((unsigned char *)dst)[d - 1] = ((unsigned char *)src)[d - 1];
			d--;
		}
	}
	return (dst);
}
