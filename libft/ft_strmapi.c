/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 21:17:46 by mernser           #+#    #+#             */
/*   Updated: 2018/12/10 21:25:26 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			t;
	char			*str;

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
		str[i] = f(i, s[i]);
		i++;
		t--;
	}
	str[i] = '\0';
	return (str);
}
