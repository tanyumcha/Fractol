/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 21:07:49 by mernser           #+#    #+#             */
/*   Updated: 2018/12/06 21:20:30 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hst;
	char	*ndl;
	int		i;
	size_t	d;

	i = 0;
	hst = (char *)haystack;
	ndl = (char *)needle;
	if (*ndl == '\0')
		return (hst);
	while (*hst != '\0' && len > 0)
	{
		d = len;
		while (hst[i] == ndl[i] && d > 0)
		{
			if (ndl[i + 1] == '\0')
				return (hst);
			i++;
			d--;
		}
		i = 0;
		hst++;
		len--;
	}
	return (NULL);
}
