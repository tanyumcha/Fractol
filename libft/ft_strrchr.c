/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:42:23 by mernser           #+#    #+#             */
/*   Updated: 2018/12/06 20:02:33 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	char	kek;
	int		i;

	i = 0;
	kek = (char)c;
	a = (char *)s;
	while (a[i] != '\0')
		i++;
	if (kek == '\0')
		return (&a[i]);
	while (i != -1)
	{
		if (a[i] == kek)
			return (&a[i]);
		i--;
	}
	return (NULL);
}
