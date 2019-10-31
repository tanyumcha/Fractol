/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 09:08:03 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/24 09:19:02 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_press(int key, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (key == 53)
		exit(0);
	else if (key == 124)
		ft_move_right(mlx);
	else if (key == 123)
		ft_move_left(mlx);
	else if (key == 126)
		ft_move_up(mlx);
	else if (key == 125)
		ft_move_down(mlx);
	else if (key == 69)
		ft_zoom_plus(mlx);
	else if (key == 78)
		ft_zoom_minus(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return (0);
}

void	ft_redo(t_mlx *mlx)
{
	ft_renew(mlx);
	ft_create_threads(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
}

int		ft_mouse_press(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (button == 4 && mlx->zoom >= 1)
	{
		mlx->zoom /= pow(1.05, 2);
		mlx->zoomy -= ((y - (IMG_Y / 2)) / 3500.0 / mlx->zoom / 1.5);
		mlx->zoomx -= ((x - (IMG_X / 2)) / 3500.0 / mlx->zoom / 1.5);
		ft_redo(mlx);
	}
	else if (button == 5 && mlx->tmp < 4611686018427387904)
	{
		mlx->zoom *= pow(1.05, 2);
		mlx->zoomy -= ((y - (IMG_Y / 2)) / 3500.0 / mlx->zoom / 1.5);
		mlx->zoomx -= ((x - (IMG_X / 2)) / 3500.0 / mlx->zoom / 1.5);
		ft_redo(mlx);
	}
	else if (x > 1400 && x < 1530 && y > 670 && y < 690)
		ft_choose_color(mlx, x, y);
	return (0);
}

int		ft_mouse_move(int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (ft_strcmp(mlx->name, "julia") == 0 && x <= IMG_X &&
			x >= 0 && y <= IMG_Y && y >= 0)
	{
		mlx->c_re = ((double)x - (IMG_X / 2)) / IMG_X;
		mlx->c_im = ((double)y - (IMG_Y / 2)) / IMG_Y;
		ft_redo(mlx);
	}
	return (0);
}

int		ft_close(void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	exit(0);
	return (0);
}
