/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:42:46 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/18 15:44:49 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>

#define	WIDTH 1920
#define	HEIGHT 500

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bpp;
	int	len;
	int	endian;
}		t_data;
typedef struct s_vars
{
	void *mlx;
	void *win;
}		t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	void	*mlx;
	t_data	img;
	t_vars  vars;
	void	*mlx_window;
	int	color;

	color = 0x000000;
	mlx = mlx_init();
	if (NULL == mlx)
		return (1);
	mlx_window = mlx_new_window(mlx,WIDTH,HEIGHT,"My first window");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.endian);
	for (int i = HEIGHT * 0.1; i < HEIGHT * 0.9; ++i)
	{
		for (int j = WIDTH * 0.1; j < WIDTH * 0.9; ++j)
		{
//			mlx_pixel_put(mlx, mlx_window, j, i, 0xFF0000);
			my_mlx_pixel_put(&img, j, i, color);
		}
		color += i;
	}
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(mlx);
}
