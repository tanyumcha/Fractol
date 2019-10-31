/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arrptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <mernser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 20:13:18 by mernser           #+#    #+#             */
/*   Updated: 2019/06/08 19:47:22 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_arrptr(char ***a, int *i)
{
	if (a == NULL)
		return ;
	if (*i < 0)
	{
		free(*a);
		return ;
	}
	while (*i > -1)
	{
		free((*a)[*i]);
		(*a)[*i] = NULL;
		(*i)--;
	}
	free(*a);
	*a = NULL;
}
