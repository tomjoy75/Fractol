/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 22:56:46 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/22 12:08:25 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#define MLX_ERROR 1

#define	WINDOW_WIDTH 600
#define	WINDOW_HEIGHT 300

typedef struct s_data
{
	void	*mlx;
	void	*win_ptr;
}		t_data;

int	handle_no_event(void *data)
{
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win_ptr);
	printf("Keypress : %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease : %d\n", keysym);
	return (0);
}

int	main(void)
{
//	void	*mlx;
//	void	*win_ptr;
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My window");
	if (!data.win_ptr)
		return (free(data.mlx), MLX_ERROR);
	mlx_loop_hook(data.mlx, &handle_no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
//	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_loop(data.mlx);
//	mlx_destroy_window(mlx, win_ptr);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
//clang basic_setup.c -o basic_setup -I../mlx/ -L../mlx/ $(pkg-config --cflags --libs x11 xext) ../mlx/libmlx_Linux.a
//https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx

