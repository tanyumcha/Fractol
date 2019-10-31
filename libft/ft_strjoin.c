/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:29:52 by mernser           #+#    #+#             */
/*   Updated: 2019/01/27 15:37:46 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	size_t			str1l;
	int				i;

	i = -1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		new = ft_strdup(s2);
	if (s2 == NULL)
		new = ft_strdup(s1);
	if (s1 == NULL || s2 == NULL)
		return (new);
	str1l = ft_strlen(s1) + ft_strlen(s2);
	new = (char*)malloc((sizeof(char) * str1l) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		new[i] = s1[i];
	str1l = 0;
	while (s2[str1l] != '\0')
		new[i++] = s2[str1l++];
	new[i] = '\0';
	return (new);
}
