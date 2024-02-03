/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <tjoyeux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:43:30 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/02/03 13:24:17 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
double	magnitude_squared(t_complex z)
{
	return ((z.real * z.real) + (z.i * z.i));
}
*/
double	ft_atodbl(char *s)
{
	int		int_part;
	double	decimal_part;
	int		sign;
	double	decimal_pos;

	sign = 1;
	int_part = 0;
	decimal_part = 0.0;
	decimal_pos = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign *= -1;
	while (*s >= '0' && *s <= '9')
		int_part = 10 * int_part + (*s++ - 48);
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		decimal_pos *= 0.1;
		decimal_part += decimal_pos * (*s++ - 48);		
	}
	return (sign * (int_part + decimal_part));
}