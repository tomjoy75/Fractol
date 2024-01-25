/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:18:31 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/22 17:47:10 by tjoyeux          ###   ########.fr       */
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
#define GREEN_PIXEL 0xFF00
typedef unsigned char uint8_t;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}		t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win_ptr;
	t_img	img;
}		t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int 	height;
	int	color;
}		t_rect;

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
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

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

//	if (data->win_ptr == NULL)
//		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

//	if (data->win_ptr == NULL)
//		return ;
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

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
//	void	*mlx;
//	void	*win_ptr;
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
//clang basic_setup.c -o basic_setup -I../mlx/ -L../mlx/ $(pkg-config --cflags --libs x11 xext) ../mlx/libmlx_Linux.a
//https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx
