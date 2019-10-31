/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:09:50 by eharrag-          #+#    #+#             */
/*   Updated: 2019/07/25 15:10:10 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom_plus(t_mlx *mlx)
{
	mlx->zoom = mlx->zoom + 0.1;
	ft_renew(mlx);
	ft_create_threads(mlx);
}

void	ft_zoom_minus(t_mlx *mlx)
{
	mlx->zoom = mlx->zoom - 0.1;
	ft_renew(mlx);
	ft_create_threads(mlx);
}
