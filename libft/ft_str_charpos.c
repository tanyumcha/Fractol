/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_charpos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:54:04 by mernser           #+#    #+#             */
/*   Updated: 2018/12/21 20:54:51 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_charpos(char const *str, char c)
{
	size_t	i;
	char	*s;

	if (str == NULL)
		return (-1);
	i = 0;
	s = (char*)str;
	if (c == '\0' && *s == '\0')
		return (i);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
	{
		i = ft_strlen(s);
		return (i);
	}
	return (-1);
}
