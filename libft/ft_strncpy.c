/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:27:45 by mernser           #+#    #+#             */
/*   Updated: 2018/12/04 20:40:04 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;

	i = 0;
	while (len)
	{
		if (src[i] != '\0')
			dst[i] = src[i];
		else
		{
			while (len)
			{
				dst[i] = '\0';
				len--;
				i++;
			}
			return (dst);
		}
		len--;
		i++;
	}
	return (dst);
}
