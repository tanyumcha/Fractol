/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 11:50:45 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/24 09:19:05 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_savethename(char *str, t_mlx *mlx)
{
	if (ft_strcmp(str, "julia") == 0)
		mlx->name = "julia";
	else if (ft_strcmp(str, "mandelbrot") == 0)
		mlx->name = "mandelbrot";
	else if (ft_strcmp(str, "ship") == 0)
		mlx->name = "ship";
	else if (ft_strcmp(str, "trio") == 0)
		mlx->name = "trio";
	else if (ft_strcmp(str, "koi") == 0)
		mlx->name = "koi";
	else if (ft_strcmp(str, "broccoli") == 0)
		mlx->name = "broccoli";
	else
	{
		write(1, "Usage: ./fractol filename (julia / mandelbrot / koi /", 54);
		write(1, " ship / trio / newton / broccoli)\n", 35);
	}
	return (0);
}

void	ft_choose_color(t_mlx *mlx, int x, int y)
{
	if (mlx->psycho == 0 && x > 1400 && x < 1530 && y > 670 && y < 690)
	{
		mlx->psycho = 1;
		ft_redo(mlx);
	}
	else if (mlx->psycho == 1 && x > 1400 && x < 1530 && y > 670 && y < 690)
	{
		mlx->psycho = 0;
		ft_redo(mlx);
	}
}

void	ft_choose_fr(pthread_t *threads, t_mlx *mlxcopy, t_mlx *mlx)
{
	if (ft_strcmp(mlx->name, "julia") == 0)
		pthread_create((void *)threads, NULL,
				(void *)ft_draw_julia, (void *)(mlxcopy));
	else if (ft_strcmp(mlx->name, "mandelbrot") == 0)
		pthread_create((void *)threads, NULL,
				(void *)ft_draw_mandelbrot, (void *)(mlxcopy));
	else if (ft_strcmp(mlx->name, "ship") == 0)
		pthread_create((void *)threads, NULL,
				(void *)ft_draw_ship, (void *)(mlxcopy));
	else if (ft_strcmp(mlx->name, "trio") == 0)
		pthread_create((void *)threads, NULL,
				(void *)ft_draw_trio, (void *)(mlxcopy));
	else if (ft_strcmp(mlx->name, "koi") == 0)
		pthread_create((void *)threads, NULL,
				(void *)ft_draw_koi, (void *)(mlxcopy));
	else if (ft_strcmp(mlx->name, "broccoli") == 0)
		pthread_create((void *)threads, NULL,
				(void *)ft_draw_broccoli, (void *)(mlxcopy));
}

void	ft_copycomplex(t_mlx *mlxcopy, t_mlx *mlx)
{
	mlxcopy->name = mlx->name;
	mlxcopy->str = mlx->str;
	mlxcopy->c_re = mlx->c_re;
	mlxcopy->c_im = mlx->c_im;
	mlxcopy->new_re = mlx->new_re;
	mlxcopy->new_im = mlx->new_im;
	mlxcopy->old_re = mlx->old_re;
	mlxcopy->old_im = mlx->old_im;
	mlxcopy->zoom = mlx->zoom;
	mlxcopy->move_x = mlx->move_x;
	mlxcopy->move_y = mlx->move_y;
	mlxcopy->color = mlx->color;
	mlxcopy->psycho = mlx->psycho;
}
