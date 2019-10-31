/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:16:11 by mernser           #+#    #+#             */
/*   Updated: 2018/12/12 21:19:05 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	*d;

	if (s == NULL || fd < 0)
		return ;
	d = (char*)s;
	ft_putstr_fd(d, fd);
	ft_putchar_fd('\n', fd);
}
