/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 21:12:11 by mernser           #+#    #+#             */
/*   Updated: 2018/12/12 21:16:01 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char	*d;
	int		i;

	i = 0;
	if (s == NULL || fd < 0)
		return ;
	d = (char*)s;
	while (d[i] != '\0')
	{
		ft_putchar_fd(d[i], fd);
		i++;
	}
}
