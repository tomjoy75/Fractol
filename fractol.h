/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:40:01 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/03 18:31:16 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
// # include <unistd.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# define MLX_ERROR 1
# define ERROR_MESSAGE "Please enter \n\t./fractol mandelbrot \nor \n\t./fractol burning_ship \nor \n\t./fractol julia <val_real> <val_imaginary>\n"
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 960
# define XK_Escape 0xff1b
// # define XK_KP_0                          0xffb0
// # define XK_KP_1                          0xffb1
// # define XK_KP_2                          0xffb2
// # define XK_KP_3                          0xffb3
// # define XK_KP_4                          0xffb4
// # define XK_KP_5                          0xffb5
// # define XK_KP_6                          0xffb6
// # define XK_KP_7                          0xffb7
// # define XK_KP_8                          0xffb8
// # define XK_KP_9                          0xffb9
# define XK_KP_F1                         0xffbe
# define XK_KP_F2                         0xffbf
# define XK_KP_F3                         0xffc0
# define XK_KP_F4                         0xffc1
# define XK_KP_F5                         0xffc2
# define XK_KP_F6                         0xffc3
# define XK_KP_F9                         0xffc6
#define XK_Left                          0xff51  /* Move left, left arrow */
#define XK_Up                            0xff52  /* Move up, up arrow */
#define XK_Right                         0xff53  /* Move right, right arrow */
#define XK_Down                          0xff54  /* Move down, down arrow */
# define MAX_ITER 200
typedef unsigned char uint8_t;
//nombre complexe
typedef struct s_complex
{
	double	real;
	double	i;
}		t_complex;
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
	double		nb_iter;
	int		(*get_color)(int);
	t_complex	c_julia;
}		t_draw;
//structure de base
typedef struct s_data
{
	void	*mlx;
	void	*win_ptr;
	t_img	img;
	t_draw	draw;
	char	*name;
	int		fractal_mode;
}		t_data;
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
int	get_color_blue(int iter);
int	get_color_blue_invert(int iter);
int	get_color_red(int iter);
int	get_color_palette(int iter);
int get_color_log(int iter);
int	get_color_psyche(int iter);
void	img_pix_put(t_img *img, int x, int y, int color);
int	define_drawing_zone(int fractal_mode, t_draw *draw);
// Input
int close_window(t_data *data);
int	handle_keypress(int keysym, t_data *data);
int mouse_handler(int mousecode, int x, int y, t_data *data);
int mouse_movement(int x, int y, t_data *data);
// Zoom
int	zoom_in(int x, int y, t_draw *draw);
int zoom_out(int x, int y, t_draw *draw);
// Movement
int	move_left(t_draw *draw);
int	move_right(t_draw *draw);
int	move_up(t_draw *draw);
int	move_down(t_draw *draw);
// Fractal
double	magnitude_squared(t_complex z);
int	is_divergent(t_complex n, int nb_iter);
int	is_divergent2(t_complex n, int nb_iter, t_complex c);
int	is_divergent3(t_complex n, int nb_iter);
// Utils
double	ft_atodbl(char *s);

#endif
