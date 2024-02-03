/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:39:08 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/03 15:57:14by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	get_color_blue(int iter)
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

int	get_color_blue_invert(int iter)
{
	t_color	end = {0, 0, 51};
	t_color	start = {255, 255, 255};
	t_color actual;
	double	fraction;

	fraction = (double)iter / MAX_ITER;
	actual.red = (uint8_t)(start.red + fraction * (end.red - start.red));
	actual.green = (uint8_t)(start.green + fraction * (end.green - start.green));
	actual.blue = (uint8_t)(start.blue + fraction * (end.blue - start.blue));
	return (encode_rgb(actual.red, actual.green, actual.blue));
}

int	get_color_red(int iter)
{
	t_color	start = {55, 0, 0};
	t_color	end = {255, 255, 255};
	t_color actual;
	double	fraction;

	fraction = (double)iter / MAX_ITER;
	actual.red = (uint8_t)(start.red + fraction * (end.red - start.red));
	actual.green = (uint8_t)(start.green + fraction * (end.green - start.green));
	actual.blue = (uint8_t)(start.blue + fraction * (end.blue - start.blue));
	return (encode_rgb(actual.red, actual.green, actual.blue));
}

int	get_color_palette(int iter)
{
	/*t_color	start = {55, 0, 0};
	t_color	end = {255, 255, 255};*/
	t_color actual;
	/*double	fraction;

	fraction = (double)iter / MAX_ITER;
	actual.red = (uint8_t)(start.red + fraction * (end.red - start.red));
	actual.green = (uint8_t)(start.green + fraction * (end.green - start.green));
	actual.blue = (uint8_t)(start.blue + fraction * (end.blue - start.blue));*/
	actual.red = (uint8_t)(sin(0.016 * iter + 4) * 230 + 25);
	actual.green = (uint8_t)(sin(0.013 * iter + 2) * 230 + 25);
	actual.blue = (uint8_t)(sin(0.01 * iter + 1) * 230 + 25);
	return (encode_rgb(actual.red, actual.green, actual.blue));
}

int get_color_log(int iter)
{
	t_color	start = {0, 0, 51};
	t_color	end = {255, 255, 255};
	t_color actual;
	double	fraction;

	fraction = log10((double)iter) / log10(MAX_ITER);
	actual.red = (uint8_t)(start.red + fraction * (end.red - start.red));
	actual.green = (uint8_t)(start.green + fraction * (end.green - start.green));
	actual.blue = (uint8_t)(start.blue + fraction * (end.blue - start.blue));
	return (encode_rgb(actual.red, actual.green, actual.blue));
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
//	t_draw	draw;

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
	//draw.zoom = WINDOW_WIDTH / (draw.x_max - draw.x_min);
	draw->zoom = 2.0;
	draw->nb_iter = (double)MAX_ITER;
	draw->get_color = get_color_blue;
//	draw.c_julia.real = 0.12;
//	draw.c_julia.i = 0.75;
	return (0);
}
