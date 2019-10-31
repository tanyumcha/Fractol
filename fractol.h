/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:31:06 by mernser           #+#    #+#             */
/*   Updated: 2019/10/24 09:19:10 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <pthread.h>

# define STR_SIZE IMG_X
# define WIN_X 1900
# define WIN_Y 1200
# define IMG_X 1200
# define IMG_Y 1200
# define C_RE_J -0.70176
# define C_IM_J -0.3842
# define THREADS 12
# define IMG_TOTAL IMG_X * IMG_Y
# define DIAMETER 6
# define ITER 40
# define ABS(x) ((x) >= 0 ? (x) : ((x) * -1))

typedef struct	s_mlx
{
	char			*name;
	int				*str;
	void			*ptr;
	void			*win;
	void			*img;
	int				endian;
	int				bits_per_pixel;
	int				size_len;
	int				x;
	int				y;
	int				i;
	int				num;
	int				xmin;
	int				xmax;
	double			c_re;
	double			c_im;
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_im;
	double			zoom;
	double			zoomx;
	double			zoomy;
	double			move_x;
	double			move_y;
	unsigned int	color;
	long long		tmp;
	int				psycho;
}				t_mlx;

void			ft_fill_whole(t_mlx *mlx);
void			ft_free_mlx(t_mlx *mlx);
void			ft_init(t_mlx *mlx);
void			ft_renew(t_mlx *mlx);
void			ft_redo(t_mlx *mlx);
void			ft_copycomplex(t_mlx *mlxcopy, t_mlx *mlx);
void			ft_create_threads(t_mlx *mlx);
void			ft_choose_fr(pthread_t *threads, t_mlx *mlxcopy, t_mlx *mlx);
void			ft_free_threads(pthread_t **threads);
int				ft_savethename(char *str, t_mlx *mlx);
int				ft_press(int key, void *mlx);
int				ft_close(void *param);
int				ft_mouse_press(int button, int x, int y, void *param);
void			ft_choose_color(t_mlx *mlx, int x, int y);
int				ft_mouse_move(int x, int y, void *param);
void			ft_move_up(t_mlx *mlx);
void			ft_move_down(t_mlx *mlx);
void			ft_move_left(t_mlx *mlx);
void			ft_move_right(t_mlx *mlx);
void			ft_zoom_plus(t_mlx *mlx);
void			ft_zoom_minus(t_mlx *mlx);
void			ft_paint(int num, double i, t_mlx *mlx);
void			ft_paint2(int num, double i, t_mlx *mlx);
void			ft_paintpsycho(int num, double i, t_mlx *mlx);
void			ft_mandelbrot_count(t_mlx *mlx);
void			ft_draw_mandelbrot(t_mlx *mlx);
void			ft_julia_count(t_mlx *mlx);
void			ft_draw_julia(t_mlx *mlx);
void			ft_ship_count(t_mlx *mlx);
void			ft_draw_ship(t_mlx *mlx);
void			ft_trio_count(t_mlx *mlx);
void			ft_draw_trio(t_mlx *mlx);
void			ft_koi_count(t_mlx *mlx);
void			ft_draw_koi(t_mlx *mlx);
void			ft_broccoli_count(t_mlx *mlx);
void			ft_draw_broccoli(t_mlx *mlx);
void			menu(t_mlx *mlx);

#endif
