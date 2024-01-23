/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joyeux <joyeux@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:40:01 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/23 23:49:24 by joyeux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
#include "mlx/mlx.h"
# define MLX_ERROR 1
# define WIDTH 1920
# define HEIGHT 500
//structure image
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}		t_img;
//structure de base
typedef struct s_data
{
	void	*mlx;
	void	*win_ptr;
	t_img	img;
}		t_data;

#endif
