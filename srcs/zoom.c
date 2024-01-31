/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:42:40 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/31 13:17:05 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	convert_to_complex(int x, int y, t_draw *draw)
{
	t_complex	n;

	n.real = x * (draw->x_max - draw->x_min) / WINDOW_WIDTH + draw->x_min;
	n.i = (WINDOW_HEIGHT - y) * (draw->y_max - draw->y_min) / WINDOW_HEIGHT + draw->y_min;
	return (n);
}

int	zoom_in(int x, int y, t_draw *draw)
{
	t_complex	n;

	n = convert_to_complex(x, y, draw);
	printf("n.real = %f, n.i = %f\n", n.real, n.i);
	printf("Before : x_min : %f, x_max : %f\ny_min : %f, y_max : %f\n\n", draw->x_min, draw->x_max, draw->y_min, draw->y_max);
	draw->x_min += (n.real - draw->x_min) / draw->zoom;
	draw->x_max = n.real + ((draw->x_max - n.real) / draw->zoom);
	draw->y_min += (n.i - draw->y_min) / draw->zoom;
	draw->y_max = n.i + ((draw->y_max - n.i) / draw->zoom);
	printf("After : x_min : %f, x_max : %f\ny_min : %f, y_max : %f\n\n", draw->x_min, draw->x_max, draw->y_min, draw->y_max);
	return (0);
}