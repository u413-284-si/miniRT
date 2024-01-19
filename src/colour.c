/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:30:57 by u413q             #+#    #+#             */
/*   Updated: 2024/01/17 00:04:44 by sqiu             ###   ########.fr       */
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
	const t_interval	interval = (t_interval){.min = 0.0, .max = 1.0};

	return ((t_colour){
		.r = ft_clamp(c1.r * c2.r, interval),
		.b = ft_clamp(c1.b * c2.b, interval),
		.g = ft_clamp(c1.g * c2.g, interval)
	});
}

t_colour	ft_get_colour(t_col_name col_name)
{
	if (col_name == RED)
		return ((t_colour){1.0, 0.0, 0.0});
	else if (col_name == GREEN)
		return ((t_colour){0.0, 1.0, 0.0});
	else if (col_name == BLUE)
		return ((t_colour){0.0, 0.0, 1.0});
	else if (col_name == YELLOW)
		return ((t_colour){1.0, 1.0, 0.0});
	else if (col_name == PURPLE)
		return ((t_colour){1.0, 0.0, 1.0});
	else if (col_name == CYAN)
		return ((t_colour){0.0, 1.0, 1.0});
	else if (col_name == WHITE)
		return ((t_colour){1.0, 1.0, 1.0});
	else if (col_name == BLACK)
		return ((t_colour){0.0, 0.0, 0.0});
	else if (col_name == ORANGE)
		return ((t_colour){1.0, 0.5, 0.0});
	else if (col_name == PINK)
		return ((t_colour){1.0, 0.0, 0.5});
	else
		return ((t_colour){0.0, 0.0, 0.0});
}
