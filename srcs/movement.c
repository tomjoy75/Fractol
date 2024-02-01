/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:50:31 by joyeux            #+#    #+#             */
/*   Updated: 2024/02/01 14:31:52 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	move_left(t_draw *draw)
{
	double	x_diff;

	x_diff = draw->x_max - draw->x_min;
	draw->x_max -= x_diff / 10;
	draw->x_min -= x_diff / 10;
	return (0);
}

int	move_right(t_draw *draw)
{
	double	x_diff;

	x_diff = draw->x_max - draw->x_min;
	draw->x_max += x_diff / 10;
	draw->x_min += x_diff / 10;
	return (0);
}

int	move_up(t_draw *draw)
{
	double	y_diff;

	y_diff = draw->y_max - draw->y_min;
	draw->y_max += y_diff / 10;
	draw->y_min += y_diff / 10;
	return (0);
}

int	move_down(t_draw *draw)
{
	double	y_diff;

	y_diff = draw->y_max - draw->y_min;
	draw->y_max -= y_diff / 10;
	draw->y_min -= y_diff / 10;
	return (0);
}