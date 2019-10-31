/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:03:01 by mernser           #+#    #+#             */
/*   Updated: 2018/12/06 21:04:22 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hst;
	char	*ndl;
	int		i;

	i = 0;
	hst = (char *)haystack;
	ndl = (char *)needle;
	if (*ndl == '\0')
		return (hst);
	while (*hst != '\0')
	{
		while (hst[i] == ndl[i])
		{
			if (ndl[i + 1] == '\0')
				return (hst);
			i++;
		}
		i = 0;
		hst++;
	}
	return (NULL);
}
