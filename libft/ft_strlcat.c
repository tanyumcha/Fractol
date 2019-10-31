/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:52:30 by mernser           #+#    #+#             */
/*   Updated: 2018/12/06 19:39:54 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		l_dst;
	size_t		l_src;
	size_t		i;

	i = 0;
	l_src = ft_strlen(src);
	l_dst = ft_strlen(dst);
	if (size <= l_dst)
		return (size + l_src);
	while (dst[i] != '\0' && i < (size - 1))
		i++;
	while (*src != '\0' && i < (size - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (l_dst + l_src);
}
