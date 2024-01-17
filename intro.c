/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:42:46 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/17 23:55:17 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>

#define	WIDTH 500
#define	HEIGHT 500

int	main()
{
	void	*mlx;
	void	*mlx_window;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx,
					WIDTH,
					HEIGHT,
					"My first window");
	for (int i = HEIGHT * 0.1; i < HEIGHT * 0.9; ++i)
		for (int j = WIDTH * 0.1; j < WIDTH * 0.9; ++j)
	{
		mlx_pixel_put(mlx, mlx_window, i, j, rand() % 1000000);
	}
	mlx_loop(mlx);
}
