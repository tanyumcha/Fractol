/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 11:16:01 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/24 09:26:07 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fill_whole(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < IMG_TOTAL)
	{
		mlx->str[i] = 0x000000;
		i++;
	}
}

void	ft_init(t_mlx *mlx)
{
	mlx->zoom = 1;
	mlx->psycho = 0;
	mlx->move_x = 0;
	mlx->move_y = 0;
	mlx->xmin = 0;
	mlx->xmax = 100;
	mlx->endian = 0;
	mlx->bits_per_pixel = 4;
	mlx->size_len = 1200;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIN_X, WIN_Y, "stroke of genius");
	mlx->img = mlx_new_image(mlx->ptr, IMG_X, IMG_Y);
	mlx->str = (int *)mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->size_len, &mlx->endian);
	menu(mlx);
}

void	ft_renew(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	ft_fill_whole(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	menu(mlx);
}

int		main(int argc, char **argv)
{
	t_mlx		mlx;

	if ((argc > 1 && argc < 3 && ft_strcmp(argv[1], "julia") == 0) ||
			(argc > 1 && argc < 3 && ft_strcmp(argv[1], "mandelbrot") == 0) ||
			(argc > 1 && argc < 3 && ft_strcmp(argv[1], "koi") == 0) ||
			(argc > 1 && argc < 3 && ft_strcmp(argv[1], "broccoli") == 0) ||
			(argc > 1 && argc < 3 && ft_strcmp(argv[1], "trio") == 0) ||
			(argc > 1 && argc < 3 && ft_strcmp(argv[1], "ship") == 0))
		ft_savethename(argv[1], &mlx);
	else
	{
		write(1, "Usage: ./fractol filename (julia / mandelbrot / koi /", 54);
		write(1, " ship / trio / broccoli)\n", 26);
		return (0);
	}
	ft_init(&mlx);
	ft_create_threads(&mlx);
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	mlx_hook(mlx.win, 17, (1L << 17), ft_close, (void *)&mlx);
	mlx_hook(mlx.win, 2, 0, ft_press, (void *)&mlx);
	mlx_hook(mlx.win, 6, (1L << 6), ft_mouse_move, (void *)&mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_press, (void *)&mlx);
	mlx_loop(mlx.ptr);
	return (1);
}
