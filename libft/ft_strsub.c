/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:12:59 by mernser           #+#    #+#             */
/*   Updated: 2018/12/15 20:29:40 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	char			*str;
	unsigned int	i;

	i = 0;
	str = NULL;
	if (s == NULL)
		return (str);
	str = (char*)malloc(sizeof(*str) * len + 1);
	if (str == NULL)
		return (NULL);
	s1 = (char*)s;
	while (len > 0)
	{
		str[i] = s1[i + start];
		len--;
		i++;
	}
	str[i] = '\0';
	return (str);
}
