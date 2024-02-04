/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:42:00 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/03 23:47:46 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_window(t_data *data)
	{
		mlx_destroy_window(data->mlx, data->win_ptr);
		data->win_ptr = NULL;
        return (0);
	}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
        close_window(data);
	/*{
		mlx_destroy_window(data->mlx, data->win_ptr);
		data->win_ptr = NULL;
	}*/
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
    else if (keysym == XK_KP_F9)
        printf("x_min : %f x_max : %f y_min : %f y_max : %f \n", data->draw.x_min, data->draw.x_max, data->draw.y_min, data->draw.y_max);
    else if (keysym == XK_Left)
    {
        printf("Left Key");
        move_left(&data->draw);
    }
    else if (keysym == XK_Right)
    {
        printf("right key");
        move_right(&data->draw);
    }
    else if (keysym == XK_Up)
    {
        printf("up key");
        move_up(&data->draw);
    }
    else if (keysym == XK_Down)
    {
        printf("down key");
        move_down(&data->draw);
    }
    else if (keysym == 119)
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
    else if (keysym == 105)
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
//    else if (keysym == ´q´)
//    else if (keysym == XK_Right)
//    else if (keysym == XK_Up)
//    else if (keysym == XK_Down)

	printf("%d\n", keysym);
	return (0);
}

int mouse_handler(int mousecode, int x, int y, t_data *data)
{
    /* x and y parameters are the pixel coordinates of the mouse
     * in the window when the event was emitted
     * you can use them to check that the user clicked in a specific region
     * of the window
     */
    //(void)data;
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
        zoom_out(x, y, &data->draw);
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

int mouse_movement(int x, int y, t_data *data)
{
    (void)data;
    printf("x:%d, y:%d\n", x, y);
    return (0);
}