/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:23:43 by mernser           #+#    #+#             */
/*   Updated: 2018/12/21 20:38:48 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_letters(char c, char **d)
{
	int	l;

	l = 0;
	while (**d != '\0')
	{
		if (**d != c && **d != '\0')
		{
			while (**d != c && **d != '\0')
			{
				l++;
				(*d)++;
			}
			return (l);
		}
		(*d)++;
	}
	return (l);
}

static int	ft_count_words(char c, char *d, int *words)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	*words = w;
	while (d[i] != '\0')
	{
		if (d[i] != c && d[i] != '\0')
		{
			w++;
			while (d[i] != c && d[i] != '\0')
				i++;
		}
		if (d[i] == '\0')
		{
			*words = w;
			return (*words);
		}
		*words = w;
		i++;
	}
	return (*words);
}

static void	ft_fill(char ***a, int i, char c, char *d)
{
	int	k;
	int	l;

	k = 0;
	l = 0;
	i = 0;
	while (d[k] != '\0')
	{
		if (d[k] != c && d[k] != '\0')
		{
			while (d[k] != c && d[k] != '\0')
			{
				(*a)[i][l] = d[k];
				l++;
				k++;
			}
			(*a)[i][l] = '\0';
			l = 0;
			i++;
			if (d[k] == '\0')
				return ;
		}
		k++;
	}
}

static void	ft_free(char ***a, int *i)
{
	while ((*i)-- != 0)
	{
		free((*a)[*i]);
		(*a)[*i] = NULL;
	}
	free(*a);
	*a = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**a;
	char	*d;
	int		i;
	int		words;

	if (s == NULL)
		return (NULL);
	d = (char*)s;
	i = -1;
	a = (char**)malloc(sizeof(d) * (ft_count_words(c, d, &words) + 1));
	if (a == NULL)
		return (NULL);
	while (++i != words)
	{
		a[i] = (char*)malloc(sizeof(char) * ft_count_letters(c, &d) + 1);
		if (a[i] == NULL)
		{
			ft_free(&a, &i);
			return (NULL);
		}
	}
	a[i] = NULL;
	d = (char*)s;
	ft_fill(&a, i, c, d);
	return (a);
}
