/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:40:01 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/25 00:34:35 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
#include "mlx/mlx.h"
# define MLX_ERROR 1
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 960
# define XK_Escape 0xff1b
typedef unsigned char uint8_t;
//structure image
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}		t_img;
//drawing zone
typedef struct s_draw
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	zoom;
}		t_draw;
//structure de base
typedef struct s_data
{
	void	*mlx;
	void	*win_ptr;
	t_img	img;
	t_draw	draw;
}		t_data;
//nombre complexe
typedef struct s_complex
{
	double	real;
	double	i;
}		t_complex;

int	is_convergent(t_complex n);



#endif
