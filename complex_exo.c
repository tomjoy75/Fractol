/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_exo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjoyeux <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:13:00 by tjoyeux           #+#    #+#             */
/*   Updated: 2024/01/23 16:11:02 by tjoyeux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#define MAX_ITER 50

typedef struct s_complex
{
	double	real;
	double	i;
}		t_complex;

void	next_complex_nb(t_complex c, t_complex *z)
{
	t_complex	tmp;

	tmp.real = z->real;
	tmp.i =  z->i;
	z->real = (tmp.real * tmp.real) - (tmp.i * tmp.i) + c.real;
	z->i = 2 * tmp.real * tmp.i + c.i;
}

double	magnitude(t_complex z)
{
	return (sqrt((z.real * z.real) + (z.i * z.i)));
}

int	main(void)
{
	t_complex	c = {-0.666, 0.367};
	t_complex	z = {0, 0};
	int		iter;
	int		divergent = 0;

	iter = 0;
	while (++iter < MAX_ITER && !divergent)
	{
		next_complex_nb(c, &z);
		printf("iteration %d: z = %f + %fi\n", iter, z.real, z.i);
		if (magnitude(z) > 2)
		{
			printf("\nThis value diverge after %d iteration !!!\n", iter);
			divergent++;
		}
	}
	if (!divergent)
		printf("\nThis value converge .\n");
}
