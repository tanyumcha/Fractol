/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:12:23 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/24 09:07:26 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia_count(t_mlx *mlx)
{
	mlx->old_re = mlx->new_re;
	mlx->old_im = mlx->new_im;
	mlx->new_re = mlx->old_re * mlx->old_re - mlx->old_im * mlx->old_im
		+ mlx->c_re;
	mlx->new_im = 2 * mlx->old_re * mlx->old_im + mlx->c_im;
	mlx->num = STR_SIZE * mlx->x + mlx->y;
	if ((mlx->new_re * mlx->new_re + mlx->new_im * mlx->new_im) < DIAMETER)
	{
		if (mlx->psycho == 1)
			ft_paintpsycho(mlx->num, mlx->i, mlx);
		else
			ft_paint(mlx->num, mlx->i, mlx);
	}
	mlx->i++;
}

void	ft_draw_julia(t_mlx *mlx)
{
	mlx->c_re += C_RE_J;
	mlx->c_im += C_IM_J;
	mlx->x = mlx->xmin;
	mlx->y = 0;
	while (mlx->y < STR_SIZE)
	{
		mlx->x = mlx->xmin;
		while (mlx->x < mlx->xmax)
		{
			mlx->new_re = (mlx->y - STR_SIZE / 2) / (0.3
					* mlx->zoom * STR_SIZE) + mlx->move_y;
			mlx->new_im = (mlx->x - STR_SIZE / 2) / (0.3
					* mlx->zoom * STR_SIZE) + mlx->move_x;
			mlx->i = 0;
			while (mlx->i < ITER)
				ft_julia_count(mlx);
			mlx->x++;
		}
		mlx->y++;
	}
}
