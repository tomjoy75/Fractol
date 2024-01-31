/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:40:37 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/31 15:49:28 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	next_complex_nb(t_complex c, t_complex *z)
{
	t_complex	tmp;

	tmp.real = z->real;
	tmp.i =  z->i;
	z->real = (tmp.real * tmp.real) - (tmp.i * tmp.i) + c.real;
	z->i = 2 * tmp.real * tmp.i + c.i;
}

double	magnitude_squared(t_complex z)
{
	return ((z.real * z.real) + (z.i * z.i));
}

int	is_divergent(t_complex n, int nb_iter)
{
	//t_complex	c = {-0.666, 0.367};
	t_complex	z = {0, 0};
	int		iter;
	//int		divergent = 0;

	iter = 0;
	while (++iter < nb_iter) /*&& !divergent*/
	{
		next_complex_nb(n, &z);
		//printf("iteration %d: z = %f + %fi\n", iter, z.real, z.i);
		if (magnitude_squared(z) > 4)
			return (iter);
/*		{
			printf("\nThis value diverge after %d iteration !!!\n", iter);

			divergent++;
		}*/
	}
	return (0);
/*	if (!divergent)
		printf("\nThis value converge .\n");*/
}
