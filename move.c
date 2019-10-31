/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 09:19:35 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/23 10:55:01 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_move_up(t_mlx *mlx)
{
	mlx->move_x = (mlx->move_x - 0.1);
	ft_renew(mlx);
	ft_create_threads(mlx);
}

void	ft_move_down(t_mlx *mlx)
{
	mlx->move_x = (mlx->move_x + 0.1);
	ft_renew(mlx);
	ft_create_threads(mlx);
}

void	ft_move_left(t_mlx *mlx)
{
	mlx->move_y = (mlx->move_y - 0.1);
	ft_renew(mlx);
	ft_create_threads(mlx);
}

void	ft_move_right(t_mlx *mlx)
{
	mlx->move_y = (mlx->move_y + 0.1);
	ft_renew(mlx);
	ft_create_threads(mlx);
}
