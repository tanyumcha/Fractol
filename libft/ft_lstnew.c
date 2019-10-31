/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:38:35 by mernser           #+#    #+#             */
/*   Updated: 2019/06/07 19:55:20 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;

	a = (t_list*)malloc(sizeof(t_list));
	if (a == NULL)
		return (NULL);
	if (content == NULL)
	{
		(*a).content = NULL;
		(*a).content_size = 0;
	}
	else
	{
		a->content = (void*)malloc(content_size);
		if (a->content == NULL)
		{
			free(a);
			return (NULL);
		}
		a->content = ft_memmove(a->content, content, content_size);
		a->content_size = content_size;
	}
	a->next = NULL;
	return (a);
}
