/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paintpsycho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:07:05 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/24 09:21:41 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_paintpsycho2(int num, double i, t_mlx *mlx)
{
	if (i >= 10 && i < 15)
		mlx->str[num] = 0xff1493;
	else if (i >= 15 && i < 20)
		mlx->str[num] = 0x8b008b;
	else if (i >= 20 && i < 30)
		mlx->str[num] = 0x458B00;
	else if (i >= 30 && i < 40)
		mlx->str[num] = 0xee0000;
	else if (i >= 40 && i < 50)
		mlx->str[num] = 0x00008b;
	else if (i >= 50 && i < 60)
		mlx->str[num] = 0xffe1ff;
	else if (i >= 60 && i < 70)
		mlx->str[num] = 0x9b30ff;
	else if (i >= 70 && i < 80)
		mlx->str[num] = 0xff3030;
	else if (i >= 80 && i < 90)
		mlx->str[num] = 0xff6a6a;
	else if (i >= 90 && i < 100)
		mlx->str[num] = 0xffff00;
	else if (i >= 100 && i < 110)
		mlx->str[num] = 0xc0ff3e;
	else
		mlx->str[num] = 0x00ee00;
}

void	ft_paintpsycho(int num, double i, t_mlx *mlx)
{
	if (i >= 0.1 && i < 1)
		mlx->str[num] = 0x4eee94;
	else if (i >= 1 && i < 2)
		mlx->str[num] = 0x00ffff;
	else if (i >= 2 && i < 3)
		mlx->str[num] = 0x6959cd;
	else if (i >= 3 && i < 4)
		mlx->str[num] = 0xff0000;
	else if (i >= 4 && i < 5)
		mlx->str[num] = 0xc71585;
	else if (i >= 5 && i < 6)
		mlx->str[num] = 0xba55d3;
	else if (i >= 6 && i < 7)
		mlx->str[num] = 0x9400d3;
	else if (i >= 7 && i < 8)
		mlx->str[num] = 0x9370db;
	else if (i >= 8 && i < 9)
		mlx->str[num] = 0xff4500;
	else if (i >= 9 && i < 10)
		mlx->str[num] = 0xcd5c5c;
	else if (i >= 10 && i < 15)
		mlx->str[num] = 0xffff00;
	else
		ft_paint2(num, i, mlx);
}
