/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:28:09 by mernser           #+#    #+#             */
/*   Updated: 2018/12/10 22:08:29 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	if (*str1 == '\0' && *str2 == '\0')
		return (1);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str1 != *str2)
			return (0);
		str1++;
		str2++;
	}
	return (1);
}
