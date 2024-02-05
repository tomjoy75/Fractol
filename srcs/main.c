/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:48:15 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/05 17:36:29 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	init_data(int argc, char **argv)
{
	t_data	data;

	if (2 == argc && !ft_strncmp(argv[1], "mandelbrot", 10))
	{
		data.name = argv[1];
		data.fractal_mode = 1;
	}
	else if (4 == argc && !ft_strncmp(argv[1], "julia", 5))
	{
		data.name = argv[1];
		data.draw.c_julia.real = ft_atodbl(argv[2]);
		data.draw.c_julia.i = ft_atodbl(argv[3]);
		data.fractal_mode = 2;
	}
	else if (2 == argc && !ft_strncmp(argv[1], "burning_ship", 12))
	{
		data.name = argv[1];
		data.fractal_mode = 3;
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		exit(EXIT_FAILURE);
	}
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data = init_data(argc, argv);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, data.name);
	if (!data.win_ptr)
		return (free(data.mlx), MLX_ERROR);
	data.img.mlx_img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	define_drawing_zone(data.fractal_mode, &data.draw);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win_ptr, 4, (1L << 2), &mouse_handler, &data);
	mlx_hook(data.win_ptr, 2, (1L << 0), handle_keypress, &data);
	mlx_hook(data.win_ptr, 17, (1L << 17), close_window, &data);
	mlx_loop(data.mlx);
	mlx_destroy_image(data.mlx, data.img.mlx_img);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}
// gcc ./main.c ./mlx/libmlx_Linux.a -lXext -lX11 -lm -o fractol
// gcc srcs/*.c -L./mlx/ -lmlx_Linux -I. -lXext -lX11 -lm -o fractol