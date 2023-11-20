/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:30:57 by u413q             #+#    #+#             */
/*   Updated: 2023/11/20 22:48:56 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colour.h"

void	ft_write_colour(t_colour pixel)
{
	int		ir;
	int		ig;
	int		ib;

	ir = (int)(255.99 * pixel.r);
	ig = (int)(255.99 * pixel.g);
	ib = (int)(255.99 * pixel.b);
	printf("%d %d %d\n", ir, ig, ib);
}

t_colour	ft_add_colour(t_colour c1, t_colour c2)
{
	return ((t_colour){
		.r = c1.r + c2.r,
		.b = c1.b + c2.b,
		.g = c1.g + c2.g
	});
}

t_colour	ft_hadamard_colour(t_colour c1, t_colour c2)
{
	return ((t_colour){
		.r = c1.r * c2.r,
		.b = c1.b * c2.b,
		.g = c1.g * c2.g
	});
}

int	ft_convert_colour2int(t_colour colour)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = 0;
	r = (int)(255.99 * colour.r);
	g = (int)(255.99 * colour.g);
	b = (int)(255.99 * colour.b);
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

t_colour	ft_convert_int2colour(int colour)
{
	t_colour	ret;

	ret.r = colour >> 16 & 0xFF;
	ret.g = colour >> 8 & 0xFF;
	ret.b = colour & 0xFF;
	return (ret);
}
