/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:42:40 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/05 18:04:45 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	convert_to_complex(int x, int y, t_draw *draw)
{
	t_complex	n;

	n.real = x * (draw->x_max - draw->x_min) / WINDOW_WIDTH + draw->x_min;
	n.i = (WINDOW_HEIGHT - y) * (draw->y_max - draw->y_min) / WINDOW_HEIGHT
		+ draw->y_min;
	return (n);
}

int	zoom_in(int x, int y, t_draw *draw)
{
	t_complex	n;

	n = convert_to_complex(x, y, draw);
	draw->x_min += (n.real - draw->x_min) / draw->zoom;
	draw->x_max = n.real + ((draw->x_max - n.real) / draw->zoom);
	draw->y_min += (n.i - draw->y_min) / draw->zoom;
	draw->y_max = n.i + ((draw->y_max - n.i) / draw->zoom);
	if (draw->nb_iter < MAX_ITER)
		draw->nb_iter += (MAX_ITER - draw->nb_iter) / 10;
	return (0);
}

int	zoom_out(t_draw *draw)
{
	double		x_diff;
	double		y_diff;

	x_diff = (draw->x_max - draw->x_min) / draw->zoom;
	y_diff = (draw->y_max - draw->y_min) / draw->zoom;
	draw->x_min -= x_diff;
	draw->x_max += x_diff;
	draw->y_min -= y_diff;
	draw->y_max += y_diff;
	if (draw->nb_iter > MIN_ITER)
		draw->nb_iter -= (draw->nb_iter - MIN_ITER) / 10;
	printf("nb_iter = %f\n\n", draw->nb_iter);
	return (0);
}
