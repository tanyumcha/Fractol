/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powerof_positive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mernser <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:08:02 by mernser           #+#    #+#             */
/*   Updated: 2018/12/21 18:18:40 by mernser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_powerof_positive(size_t n, size_t p)
{
	size_t	d;

	d = n;
	if (p == 0)
		return (1);
	if (p == 1)
		return (n);
	while (--p)
		n = n * d;
	return (n);
}
