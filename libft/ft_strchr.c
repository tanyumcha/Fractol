/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:26:39 by mernser           #+#    #+#             */
/*   Updated: 2018/12/06 18:37:14 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	kek;
	char	*a;

	a = (char *)s;
	kek = c;
	while (*a != '\0')
	{
		if (*a == kek)
			return (a);
		a++;
	}
	if (*a == '\0' && c == '\0')
		return (a);
	return (NULL);
}
