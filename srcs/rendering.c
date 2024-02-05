/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:30:45 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/05 18:12:04 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_fractal(t_img *img, t_draw draw, int fractal_mode)
{
	int			x;
	int			y;
	t_complex	n;
	int			iter;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			n.real = x * (draw.x_max - draw.x_min) / WINDOW_WIDTH + draw.x_min;
			n.i = (WINDOW_HEIGHT - y) * (draw.y_max - draw.y_min)
				/ WINDOW_HEIGHT + draw.y_min;
			if (fractal_mode == 1)
				iter = is_divergent(n, draw.nb_iter, next_complex_nb);
			else if (fractal_mode == 2)
				iter = is_divergent_julia(n, draw.nb_iter, draw.c_julia);
			else if (fractal_mode == 3)
				iter = is_divergent(n, draw.nb_iter, next_complex_burn);
			if (!iter)
				img_pix_put(img, x, y, 0x00);
			else
				img_pix_put(img, x, y, draw.get_color(iter));
			x++;
		}
		++y;
	}
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_fractal(&data->img, data->draw, data->fractal_mode);
	mlx_put_image_to_window(data->mlx, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
