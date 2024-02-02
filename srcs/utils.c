/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:43:30 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/02 16:03:51 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
double	magnitude_squared(t_complex z)
{
	return ((z.real * z.real) + (z.i * z.i));
}
*/
double	atodbl(char *s)
{
	double	int_part;
	double	frac_part;
	int		sign;

	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign *= -1;
}
