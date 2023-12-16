/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:30:57 by u413q             #+#    #+#             */
/*   Updated: 2023/12/16 16:50:12 by u413q            ###   ########.fr       */
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

t_colour	ft_hadamard_colour(t_colour c1, t_colour c2)
{
	return ((t_colour){
		.r = c1.r * c2.r,
		.b = c1.b * c2.b,
		.g = c1.g * c2.g
	});
}
