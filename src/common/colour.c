/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:30:57 by u413q             #+#    #+#             */
/*   Updated: 2024/01/10 18:16:24 by gwolf            ###   ########.fr       */
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

t_colour	ft_get_colour(t_col_name col_name)
{
	static const t_colour	colour_array[NUM_COLOURS] = {
	[RED] = (t_colour){1.0, 0.0, 0.0},
	[ORANGE] = (t_colour){1.0, 0.5, 0.0},
	[YELLOW] = (t_colour){1.0, 1.0, 0.0},
	[GREEN] = (t_colour){0.0, 1.0, 0.0},
	[BLUE] = (t_colour){0.0, 0.0, 1.0},
	[INDIGO] = (t_colour){0.75, 0.0, 1.0},
	[PURPLE] = (t_colour){1.0, 0.0, 1.0},
	[WHITE] = (t_colour){1.0, 1.0, 1.0},
	[BLACK] = (t_colour){0.0, 0.0, 0.0}};

	return (colour_array[col_name]);
}

void	ft_interpolate_colour(t_colour *result, float progress)
{
	const int		index = (int)(progress * (NUM_RAINBOW_COLOURS - 1));
	const float		frac = fmod(progress * (NUM_RAINBOW_COLOURS - 1), 1.0);
	const t_colour	color1 = ft_get_colour(index);
	t_colour		color2;

	if (index + 1 < NUM_RAINBOW_COLOURS)
		color2 = ft_get_colour(index + 1);
	else
		color2 = ft_get_colour(0);
	result->r = color1.r + frac * (color2.r - color1.r);
	result->g = color1.g + frac * (color2.g - color1.g);
	result->b = color1.b + frac * (color2.b - color1.b);
}

void	ft_static_interpolate(t_colour *result, float inc)
{
	static float	progress = 0.0;
	const float		factor = 0.05;

	progress += (inc * factor);
	if (progress > 1.0)
		progress = 0.0;
	else if (progress < 0.0)
		progress = 1.0;
	ft_interpolate_colour(result, progress);
}
