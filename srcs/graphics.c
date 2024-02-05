/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:39:08 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/05 15:56:19 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	encode_rgb(t_uint8 red, t_uint8 green, t_uint8 blue)
{
	return (red << 16 | green << 8 | blue);
}

int	get_color_psyche(int iter)
{
	if (iter % 4 == 0)
		return (encode_rgb(0, 51, 102));
	else if (iter % 4 == 1)
		return (encode_rgb(72, 209, 204));
	else if (iter % 4 == 2)
		return (encode_rgb(255, 223, 0));
	else if (iter % 4 == 3)
		return (encode_rgb(255, 99, 71));
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	define_drawing_zone(int fractal_mode, t_draw *draw)
{
	if (fractal_mode == 2)
	{
		draw->x_min = -1.35;
		draw->x_max = 1.35;
	}
	else
	{
		draw->x_min = -2.1;
		draw->x_max = 0.6;
	}
	draw->y_min = -1.2;
	draw->y_max = 1.2;
	draw->zoom = 2.0;
	draw->nb_iter = 200.0;
	draw->get_color = get_color_blue;
	return (0);
}
