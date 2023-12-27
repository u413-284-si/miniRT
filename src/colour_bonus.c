/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:30:57 by u413q             #+#    #+#             */
/*   Updated: 2023/12/27 00:16:25 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colour_bonus.h"

void	ft_init_colour(t_colour *colour)
{
	colour->b = 0;
	colour->g = 0;
	colour->r = 0;
}

void	ft_write_colour(t_colour pixel, int samples)
{
	int			ir;
	int			ig;
	int			ib;
	float		scale;
	t_interval	interval;

	scale = 1.0 / samples;
	interval.max = 0.999;
	interval.min = 0.0;
	pixel.r *= scale;
	pixel.g *= scale;
	pixel.b *= scale;
	ir = (int)(256 * ft_clamp(pixel.r, interval));
	ig = (int)(256 * ft_clamp(pixel.g, interval));
	ib = (int)(256 * ft_clamp(pixel.b, interval));
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
	t_interval	interval;

	interval.min = 0.0;
	interval.max = 1.0;
	return ((t_colour){
		.r = ft_clamp(c1.r * c2.r, interval),
		.b = ft_clamp(c1.b * c2.b, interval),
		.g = ft_clamp(c1.g * c2.g, interval)
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
