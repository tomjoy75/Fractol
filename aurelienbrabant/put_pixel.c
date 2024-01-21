/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:18:31 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/21 21:24:21 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#define MLX_ERROR 1

#define	WINDOW_WIDTH 600
#define	WINDOW_HEIGHT 300

#define RED_PIXEL 0xFF0000

typedef struct s_data
{
	void	*mlx;
	void	*win_ptr;
}		t_data;

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr != NULL)
		mlx_pixel_put(data->mlx, data->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
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
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx);
//	mlx_destroy_window(mlx, win_ptr);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
//clang basic_setup.c -o basic_setup -I../mlx/ -L../mlx/ $(pkg-config --cflags --libs x11 xext) ../mlx/libmlx_Linux.a
//https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx
