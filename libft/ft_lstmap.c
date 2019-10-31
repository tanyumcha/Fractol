/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:29:38 by mernser           #+#    #+#             */
/*   Updated: 2018/12/27 21:09:04 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *d, size_t n)
{
	n = 0;
	ft_memdel(&d);
	return ;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*start;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = f(lst);
	start = tmp;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp->next = f(lst);
		tmp = tmp->next;
		if (tmp == NULL)
		{
			ft_lstdel(&start, &del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (start);
}
