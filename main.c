/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:48:15 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/23 23:54:56 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}
/*
int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}*/

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);

//		mlx_pixel_put(data->mlx, data->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	render_background(&data->img, 0xFFFFFF);
	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My window");
	if (!data.win_ptr)
		return (free(data.mlx), MLX_ERROR);
	/* Setup hooks */
	data.img.mlx_img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx);
//	mlx_destroy_window(mlx, win_ptr);
	mlx_destroy_image(data.mlx, data.img.mlx_img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}