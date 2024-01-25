/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exo_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:26:39 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/17 17:42:33 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	

	mlx = mlx_init();
	if (!mlx)
		return (1);
	mlx_new_window(mlx, 800, 600, "window");
	mlx_loop(mlx);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
//clang -lXext -lX11 ./exo_mlx.c ./mlx/libmlx_Linux.a ./mlx/mlx.h -lm
//gcc ./exo_mlx.c ./mlx/libmlx_Linux.a -lXext -lX11 -lm -o exo_mlx
