/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 23:01:55 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/05 23:03:40 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
