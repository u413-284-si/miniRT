/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:30:57 by u413q             #+#    #+#             */
/*   Updated: 2024/01/26 14:24:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colour.h"

t_colour	ft_add_colour(t_colour c1, t_colour c2)
{
	return ((t_colour){
		.r = c1.r + c2.r,
		.b = c1.b + c2.b,
		.g = c1.g + c2.g
	});
}

t_colour	ft_scale_colour(t_colour c, float scale)
{
	return ((t_colour){
		.r = c.r * scale,
		.g = c.g * scale,
		.b = c.b * scale
	});
}

t_colour	ft_hadamard_colour(t_colour c1, t_colour c2)
{
	const t_interval	interval = (t_interval){.min = 0.0, .max = 1.0};

	return ((t_colour){
		.r = ft_clamp(c1.r * c2.r, interval),
		.b = ft_clamp(c1.b * c2.b, interval),
		.g = ft_clamp(c1.g * c2.g, interval)
	});
}

uint32_t	ft_convert_colour2int(t_colour colour)
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	a = 0;
	r = (uint8_t)(255.9 * colour.r);
	g = (uint8_t)(255.9 * colour.g);
	b = (uint8_t)(255.9 * colour.b);
	return ((a << 24) | (r << 16) | (g << 8) | b);
}

t_colour	ft_convert_int2colour(uint32_t colour)
{
	t_colour	ret;

	ret.r = colour >> 16 & 0xFF;
	ret.g = colour >> 8 & 0xFF;
	ret.b = colour & 0xFF;
	return (ret);
}
