/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:48:15 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/31 11:40:47 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	get_color(int iter)
{
	t_color	start = {0, 0, 51};
	t_color	end = {255, 255, 255};
	t_color actual;
	double	fraction;

	fraction = (double)iter / MAX_ITER;
	actual.red = (uint8_t)(start.red + fraction * (end.red - start.red));
	actual.green = (uint8_t)(start.green + fraction * (end.green - start.green));
	actual.blue = (uint8_t)(start.blue + fraction * (end.blue - start.blue));
	return (encode_rgb(actual.red, actual.green, actual.blue));
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

t_draw	define_drawing_zone(void)
{
	t_draw	draw;

	draw.x_min = -2.1;
	draw.x_max = 0.6;
	draw.y_min = -1.2;
	draw.y_max = 1.2;
	draw.zoom = WINDOW_WIDTH / (draw.x_max - draw.x_min);
	return (draw);
}

void	render_fractal(t_img *img, t_draw draw, int color)
{
	int	x;
	int	y;
	t_complex n;
	int	iter;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			n.real = x * (draw.x_max - draw.x_min) / WINDOW_WIDTH + draw.x_min;
			n.i = (WINDOW_HEIGHT - y) * (draw.y_max - draw.y_min) / WINDOW_HEIGHT + draw.y_min;
			iter = is_divergent(n);
			if (!iter)
				img_pix_put(img, x, y, color);
			else
				img_pix_put(img, x, y, get_color(iter));
			x++;
		}
		++y;
	}
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);

//		mlx_pixel_put(data->mlx, data->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	render_fractal(&data->img, data->draw, 0x000000);
//	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
//	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}
*/
int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fract'ol");
	if (!data.win_ptr)
		return (free(data.mlx), MLX_ERROR);
	/* Setup hooks */
	data.img.mlx_img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.draw = define_drawing_zone();
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win_ptr, 4, (1L<<2), &mouse_handler, &data);
//	mlx_hook(data.win_ptr, 6, 0L, &mouse_movement , &data);
	mlx_hook(data.win_ptr, 2, (1L<<0), handle_keypress, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img.mlx_img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
// gcc ./main.c ./mlx/libmlx_Linux.a -lXext -lX11 -lm -o fractol
// gcc srcs/*.c -L./mlx/ -lmlx_Linux -I. -lXext -lX11 -lm -o fractol