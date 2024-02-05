/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:29:41 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/05 15:09:47 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color_blue(int iter)
{
	t_color	start;
	t_color	end;
	t_color	actual;
	double	fraction;

	start.red = 0;
	start.green = 0;
	start.blue = 51;
	end.red = 255;
	end.green = 255;
	end.blue = 255;
	fraction = (double)iter / MIN_ITER;
	actual.red = (t_uint8)(start.red + fraction * (end.red - start.red));
	actual.green = (t_uint8)(start.green + fraction
			* (end.green - start.green));
	actual.blue = (t_uint8)(start.blue + fraction * (end.blue - start.blue));
	return (encode_rgb(actual.red, actual.green, actual.blue));
}

int	get_color_blue_invert(int iter)
{
	t_color	end;
	t_color	start;
	t_color	actual;
	double	fraction;

	start.red = 255;
	start.green = 255;
	start.blue = 255;
	end.red = 0;
	end.green = 0;
	end.blue = 51;
	fraction = (double)iter / MIN_ITER;
	actual.red = (t_uint8)(start.red + fraction * (end.red - start.red));
	actual.green = (t_uint8)(start.green + fraction
			* (end.green - start.green));
	actual.blue = (t_uint8)(start.blue + fraction * (end.blue - start.blue));
	return (encode_rgb(actual.red, actual.green, actual.blue));
}

int	get_color_red(int iter)
{
	t_color	start;
	t_color	end;
	t_color	actual;
	double	fraction;

	start.red = 55;
	start.green = 0;
	start.blue = 0;
	end.red = 255;
	end.green = 255;
	end.blue = 255;
	fraction = (double)iter / MIN_ITER;
	actual.red = (t_uint8)(start.red + fraction * (end.red - start.red));
	actual.green = (t_uint8)(start.green + fraction
			* (end.green - start.green));
	actual.blue = (t_uint8)(start.blue + fraction * (end.blue - start.blue));
	return (encode_rgb(actual.red, actual.green, actual.blue));
}

int	get_color_palette(int iter)
{
	t_color	actual;

	actual.red = (t_uint8)(sin(0.016 * iter + 4) * 230 + 25);
	actual.green = (t_uint8)(sin(0.013 * iter + 2) * 230 + 25);
	actual.blue = (t_uint8)(sin(0.01 * iter + 1) * 230 + 25);
	return (encode_rgb(actual.red, actual.green, actual.blue));
}

int	get_color_log(int iter)
{
	t_color	start;
	t_color	end;
	t_color	actual;
	double	fraction;

	start.red = 0;
	start.green = 0;
	start.blue = 51;
	end.red = 255;
	end.green = 255;
	end.blue = 255;
	fraction = log10((double)iter) / log10(MAX_ITER);
	actual.red = (t_uint8)(start.red + fraction * (end.red - start.red));
	actual.green = (t_uint8)(start.green + fraction
			* (end.green - start.green));
	actual.blue = (t_uint8)(start.blue + fraction * (end.blue - start.blue));
	return (encode_rgb(actual.red, actual.green, actual.blue));
}
/*
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
}*/
