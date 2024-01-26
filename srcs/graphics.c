/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:39:08 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/25 18:40:27 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

