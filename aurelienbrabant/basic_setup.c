/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:29:14 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/19 16:18:48 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"

#define	WINDOW_WIDTH 600
#define	WINDOW_HEIGHT 300

int	main(void)
{
	void	*mlx;
	void	*win_ptr;

	mlx = mlx_init();
	win_ptr = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My window");
	mlx_destroy_window(mlx, win_ptr);
	mlx_destroy_display(mlx);
	free(mlx);
}
//clang basic_setup.c -o basic_setup -I../mlx/ -L../mlx/ $(pkg-config --cflags --libs x11 xext) ../mlx/libmlx_Linux.a
//https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx
