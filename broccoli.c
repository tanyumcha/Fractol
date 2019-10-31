/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broccoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 11:21:44 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/24 09:08:02 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_broccoli_count(t_mlx *mlx)
{
	mlx->old_re = mlx->new_re;
	mlx->old_im = mlx->new_im;
	mlx->new_re = mlx->old_re * mlx->old_re * mlx->old_re
		- 3 * mlx->old_re * mlx->old_im * mlx->old_im + mlx->c_re;
	mlx->new_im = 3 * mlx->old_re * mlx->old_re * mlx->old_im
		- mlx->old_im * mlx->old_im * mlx->old_im + mlx->c_im;
	mlx->num = STR_SIZE * mlx->x + mlx->y;
	if (mlx->psycho == 1)
		ft_paintpsycho(mlx->num, mlx->i, mlx);
	else
		ft_paint(mlx->num, mlx->i, mlx);
	mlx->i++;
}

void	ft_draw_broccoli(t_mlx *mlx)
{
	mlx->num = 0;
	mlx->x = mlx->xmin;
	mlx->y = 0;
	mlx->c_re = 0.5;
	mlx->c_im = 0;
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
			while (mlx->i < (ITER + 70) && (mlx->new_re * mlx->new_re
					+ mlx->new_im * mlx->new_im) < DIAMETER)
				ft_broccoli_count(mlx);
			mlx->x++;
		}
		mlx->y++;
	}
}
