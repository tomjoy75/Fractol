/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:40:01 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/26 13:49:53 by tjoyeux          ###   ########.fr       */
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
# define MAX_ITER 100
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
//color
typedef struct s_color
{
	uint8_t	red;
	uint8_t green;
	uint8_t	blue;
}		t_color;

// Rendering
int	render(t_data *data);
// Graphics
int	get_color(int iter);
void	img_pix_put(t_img *img, int x, int y, int color);
t_draw	define_drawing_zone(void);
// Input
int	handle_keypress(int keysym, t_data *data);
// Zoom
// Fractal
int	is_divergent(t_complex n);



#endif
