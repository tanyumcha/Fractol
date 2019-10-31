/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:07:05 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/23 11:01:47 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_paint2(int num, double i, t_mlx *mlx)
{
	if (i >= 10 && i < 15)
		mlx->str[num] = 0x990026;
	else if (i >= 15 && i < 20)
		mlx->str[num] = 0xa10028;
	else if (i >= 20 && i < 30)
		mlx->str[num] = 0xad002b;
	else if (i >= 30 && i < 40)
		mlx->str[num] = 0xbd002f;
	else if (i >= 40 && i < 50)
		mlx->str[num] = 0xcc0033;
	else if (i >= 50 && i < 60)
		mlx->str[num] = 0xd40236;
	else if (i >= 60 && i < 70)
		mlx->str[num] = 0x8f0023;
	else if (i >= 70 && i < 80)
		mlx->str[num] = 0x990026;
	else if (i >= 80 && i < 90)
		mlx->str[num] = 0xa10028;
	else if (i >= 90 && i < 100)
		mlx->str[num] = 0xad002b;
	else if (i >= 100 && i < 110)
		mlx->str[num] = 0xbd002f;
	else
		mlx->str[num] = 0x1c0007;
}

void	ft_paint(int num, double i, t_mlx *mlx)
{
	if (i >= 0.1 && i < 1)
		mlx->str[num] = 0x260009;
	else if (i >= 1 && i < 2)
		mlx->str[num] = 0x36000d;
	else if (i >= 2 && i < 3)
		mlx->str[num] = 0x40000f;
	else if (i >= 3 && i < 4)
		mlx->str[num] = 0x4d0012;
	else if (i >= 4 && i < 5)
		mlx->str[num] = 0x570015;
	else if (i >= 5 && i < 6)
		mlx->str[num] = 0x610018;
	else if (i >= 6 && i < 7)
		mlx->str[num] = 0x69001a;
	else if (i >= 7 && i < 8)
		mlx->str[num] = 0x78001e;
	else if (i >= 8 && i < 9)
		mlx->str[num] = 0x820020;
	else if (i >= 9 && i < 10)
		mlx->str[num] = 0x8f0023;
	else if (i >= 10 && i < 15)
		mlx->str[num] = 0x990026;
	else
		ft_paint2(num, i, mlx);
}

void	menu(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->win, 1400, 500, 0x00becc,
			"SCALE UP: + / SCROLL UP");
	mlx_string_put(mlx->ptr, mlx->win, 1400, 520, 0x00becc,
			"SCALE DOWN: - / SCROLL DOWN");
	mlx_string_put(mlx->ptr, mlx->win, 1400, 550, 0x00becc,
			"MOVE UP: ARROW UP");
	mlx_string_put(mlx->ptr, mlx->win, 1400, 570, 0x00becc,
			"MOVE DOWN: ARROW DOWN");
	mlx_string_put(mlx->ptr, mlx->win, 1400, 590, 0x00becc,
			"MOVE RIGHT: ARROW RIGHT");
	mlx_string_put(mlx->ptr, mlx->win, 1400, 610, 0x00becc,
			"MOVE LEFT: ARROW LEFT");
	mlx_string_put(mlx->ptr, mlx->win, 1400, 640, 0x00becc,
			"ROTATE JULIA: MOVE THE MOUSE");
	mlx_string_put(mlx->ptr, mlx->win, 1400, 670, 0x00becc,
			"PSYCHO COLORS");
}
