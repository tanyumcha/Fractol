/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:24:39 by mernser           #+#    #+#             */
/*   Updated: 2018/12/21 18:00:44 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstcount(t_list *lst)
{
	size_t	count;
	t_list	*current;

	if (lst == NULL)
		return (0);
	current = lst;
	count = 1;
	while (current->next != NULL)
	{
		if (current->next == lst)
			return (count);
		count++;
		current = current->next;
	}
	return (count);
}
