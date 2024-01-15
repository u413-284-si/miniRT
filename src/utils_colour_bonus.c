/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colour_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:41:43 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/15 11:46:08 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colour_bonus.h"

void	ft_init_colour(t_colour *colour)
{
	colour->b = 0;
	colour->g = 0;
	colour->r = 0;
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
