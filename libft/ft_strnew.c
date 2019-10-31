/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:40:33 by mernser           #+#    #+#             */
/*   Updated: 2018/12/15 20:08:21 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char*)malloc((sizeof(*str) * size) + 1);
	if (str == NULL)
		return (NULL);
	if (size == 0)
	{
		str[0] = '\0';
		return (str);
	}
	else
	{
		while (size)
		{
			size--;
			str[i] = '\0';
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
