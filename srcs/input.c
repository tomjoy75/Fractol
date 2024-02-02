/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:42:00 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/02 15:39:39 by tjoyeux          ###   ########.fr       */
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