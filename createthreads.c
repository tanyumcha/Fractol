/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createthreads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:53:56 by eharrag-          #+#    #+#             */
/*   Updated: 2019/10/23 12:55:14 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_create_threads(t_mlx *mlx)
{
	t_mlx		mlxcopy[THREADS];
	pthread_t	threads[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		ft_copycomplex(&mlxcopy[i], mlx);
		mlxcopy[i].xmin = mlx->xmin + 100 * i;
		mlxcopy[i].xmax = mlx->xmax + 100 * i;
		ft_choose_fr(&threads[i], &mlxcopy[i], mlx);
		i++;
	}
	i--;
	while (i >= 0)
	{
		pthread_join((void *)threads[i], NULL);
		i--;
	}
}
