/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_colour.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:47:04 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/15 22:22:50 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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
	const t_colour	colour1 = ft_get_colour(index);
	t_colour		colour2;

	if (index + 1 < NUM_RAINBOW_COLOURS)
		colour2 = ft_get_colour(index + 1);
	else
		colour2 = ft_get_colour(0);
	result->r = colour1.r + frac * (colour2.r - colour1.r);
	result->g = colour1.g + frac * (colour2.g - colour1.g);
	result->b = colour1.b + frac * (colour2.b - colour1.b);
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

void	ft_keyhook_change_col(int key, t_colour *col, float inc)
{
	if (key == XK_1)
		*col = ft_get_colour(RED);
	else if (key == XK_2)
		*col = ft_get_colour(ORANGE);
	else if (key == XK_3)
		*col = ft_get_colour(YELLOW);
	else if (key == XK_4)
		*col = ft_get_colour(GREEN);
	else if (key == XK_5)
		*col = ft_get_colour(BLUE);
	else if (key == XK_6)
		*col = ft_get_colour(INDIGO);
	else if (key == XK_7)
		*col = ft_get_colour(PURPLE);
	else if (key == XK_8)
		*col = ft_get_colour(BLACK);
	else if (key == XK_9)
		ft_static_interpolate(col, inc);
	else if (key == XK_0)
		ft_static_interpolate(col, -inc);
}
