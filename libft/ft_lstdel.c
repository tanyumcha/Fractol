/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:06:45 by mernser           #+#    #+#             */
/*   Updated: 2018/12/20 19:45:46 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*current;
	t_list	*next;

	if (*alst == NULL || del == NULL)
		return ;
	current = (*alst);
	while (current != NULL)
	{
		next = current->next;
		ft_lstdelone(&current, del);
		current = next;
	}
	*alst = NULL;
}
