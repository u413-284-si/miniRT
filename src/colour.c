/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:30:57 by u413q             #+#    #+#             */
/*   Updated: 2023/12/19 22:59:32 by gwolf            ###   ########.fr       */
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

int32_t	ft_convert_colour2int(t_colour colour)
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	a = 0;
	r = (uint8_t)(255.0 * colour.r);
	g = (uint8_t)(255.0 * colour.g);
	b = (uint8_t)(255.0 * colour.b);
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