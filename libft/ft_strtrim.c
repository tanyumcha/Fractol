/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:03:26 by mernser           #+#    #+#             */
/*   Updated: 2018/12/15 21:26:59 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_skip(size_t *len, size_t *b, size_t *e, char *s1)
{
	while ((s1[*b] == '\n' || s1[*b] == ' '
	|| s1[*b] == '\t') && s1[*b] != '\0')
		(*b)++;
	if (*b != *len)
	{
		*e = *len - 1;
		while ((s1[*e] == '\n' || s1[*e] == ' ' || s1[*e] == '\t') && *e != 0)
			(*e)--;
		*e = *len - *e - 1;
	}
	if (*len == 0)
		*len = 1;
	else
		*len = *len - *b - *e;
	return ;
}

static void	ft_finish(char **s1, size_t e)
{
	if (**s1 == '\0')
	{
		*s1 = (char*)malloc(sizeof(char));
		if (*s1 == NULL)
			return ;
		**s1 = '\0';
	}
	else
		(*s1)[e] = '\0';
}

char		*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	b;
	size_t	e;
	char	*s1;

	len = 0;
	b = 0;
	e = 0;
	if (s == NULL)
		return (NULL);
	s1 = (char *)s;
	len = ft_strlen(s);
	if (len != 0)
	{
		ft_skip(&len, &b, &e, s1);
		s1 = (char*)malloc(sizeof(char) * (len) + 1);
		if (s1 == NULL)
			return (NULL);
		e = 0;
		len++;
		while (--len != 0)
			s1[e++] = (char)s[b++];
	}
	ft_finish(&s1, e);
	return (s1);
}
