/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:40:12 by mernser           #+#    #+#             */
/*   Updated: 2018/12/10 20:14:09 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	t;
	size_t	i;
	char	*str;

	i = 0;
	t = 0;
	str = NULL;
	if (s == NULL || f == NULL)
		return (str);
	t = ft_strlen(s);
	str = (char*)malloc((sizeof(char) * t) + 1);
	if (str == NULL)
		return (str);
	while (t > 0)
	{
		str[i] = f(s[i]);
		i++;
		t--;
	}
	str[i] = '\0';
	return (str);
}
