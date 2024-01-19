/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:30:57 by u413q             #+#    #+#             */
/*   Updated: 2024/01/19 16:15:54 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colour_bonus.h"

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
