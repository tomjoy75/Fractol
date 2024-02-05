/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:42:00 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/05 18:00:57 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

int	handle_keypress_color(int keysym, t_data *data)
{
	if (keysym == XK_ESC)
		close_window(data);
	else if (keysym == XK_KP_F1)
		data->draw.get_color = get_color_blue;
	else if (keysym == XK_KP_F2)
		data->draw.get_color = get_color_blue_invert;
	else if (keysym == XK_KP_F3)
		data->draw.get_color = get_color_red;
	else if (keysym == XK_KP_F4)
		data->draw.get_color = get_color_palette;
	else if (keysym == XK_KP_F5)
		data->draw.get_color = get_color_log;
	else if (keysym == XK_KP_F6)
		data->draw.get_color = get_color_psyche;
	return (0);
}

int	handle_keypress_moves(int keysym, t_data *data)
{
	if (keysym == XK_LEFT)
	{
		move_left(&data->draw);
	}
	else if (keysym == XK_RIGHT)
	{
		move_right(&data->draw);
	}
	else if (keysym == XK_UP)
	{
		move_up(&data->draw);
	}
	else if (keysym == XK_DOWN)
	{
		move_down(&data->draw);
	}
	return (0);
}

int	handle_keypress_julia(int keysym, t_data *data)
{
	if (keysym == 119)
		data->draw.c_julia.i += 0.1;
	else if (keysym == 115)
		data->draw.c_julia.i -= 0.1;
	else if (keysym == 97)
		data->draw.c_julia.real -= 0.1;
	else if (keysym == 100)
		data->draw.c_julia.real += 0.1;
	else if (keysym == 112)
	{
		data->draw.c_julia.real = -0.835;
		data->draw.c_julia.i = -0.2321;
	}
	else if (keysym == 111)
	{
		data->draw.c_julia.real = 0.285;
		data->draw.c_julia.i = 0;
	}
	return (0);
}

int	handle_keypress_julia2(int keysym, t_data *data)
{
	if (keysym == 105)
	{
		data->draw.c_julia.real = 0.4;
		data->draw.c_julia.i = 0.4;
	}
	else if (keysym == 117)
	{
		data->draw.c_julia.real = 0;
		data->draw.c_julia.i = 0.8;
	}
	else if (keysym == 121)
	{
		data->draw.c_julia.real = 0.285;
		data->draw.c_julia.i = 0.01;
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	handle_keypress_color(keysym, data);
	handle_keypress_moves(keysym, data);
	if (data->fractal_mode == 2)
	{
		handle_keypress_julia(keysym, data);
		handle_keypress_julia2(keysym, data);
	}
	return (0);
}

int	mouse_handler(int mousecode, int x, int y, t_data *data)
{
	printf("Mouse handler called\n");
	if (mousecode == 1)
		printf("Left Click");
	else if (mousecode == 2)
		printf("Right Click");
	else if (mousecode == 3)
		printf("Middle Click");
	else if (mousecode == 4)
	{
		printf("Scroll UP");
		zoom_in(x, y, &data->draw);
	}
	else if (mousecode == 5)
	{
		printf("Scroll DOWN");
		zoom_out(&data->draw);
	}
	else if (mousecode == 6)
		printf("Scroll right");
	else if (mousecode == 7)
		printf("Scroll left");
	else
		printf("%d\n", mousecode);
	printf ("x : %d, y : %d\n", x, y);
	return (0);
}
/*
int	mouse_movement(int x, int y, t_data *data)
{
	(void)data;
	printf("x:%d, y:%d\n", x, y);
	return (0);
}*/
