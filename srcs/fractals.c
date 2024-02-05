/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:40:37 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/05 14:26:53 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	next_complex_nb(t_complex c, t_complex *z)
{
	t_complex	tmp;

	tmp.real = z->real;
	tmp.i = z->i;
	z->real = (tmp.real * tmp.real) - (tmp.i * tmp.i) + c.real;
	z->i = 2 * tmp.real * tmp.i + c.i;
}

void	next_complex_burn(t_complex c, t_complex *z)
{
	t_complex	tmp;

	tmp.real = z->real;
	tmp.i = z->i;
	z->real = (tmp.real * tmp.real) - (tmp.i * tmp.i) + c.real;
	z->i = 2 * fabs(tmp.real) * fabs(tmp.i) + c.i;
}

double	magnitude_squared(t_complex z)
{
	return ((z.real * z.real) + (z.i * z.i));
}

int	is_divergent(t_complex n, int nb_iter, void (*f)(t_complex, t_complex *))
{
	t_complex	z;
	int			iter;

	iter = 0;
	z.real = 0;
	z.i = 0;
	while (++iter < nb_iter)
	{
		f(n, &z);
		if (magnitude_squared(z) > 4)
			return (iter);
	}
	return (0);
}

int	is_divergent_julia(t_complex n, int nb_iter, t_complex c)
{
	t_complex	z;
	int			iter;

	iter = 0;
	z.real = n.real;
	z.i = n.i;
	while (++iter < nb_iter)
	{
		next_complex_nb(c, &z);
		if (magnitude_squared(z) > 4)
			return (iter);
	}
	return (0);
}
/*
int	is_divergent3(t_complex n, int nb_iter)
{
	t_complex	z;
	int		iter;

	iter = 0;
	z.real = 0;
	z.i = 0;
	while (++iter < nb_iter)
	{
		next_complex_burn(n, &z);
		if (magnitude_squared(z) > 4)
			return (iter);
	}
	return (0);
}
*/