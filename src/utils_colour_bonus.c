/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colour_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:41:43 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/20 15:21:49 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colour_bonus.h"

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
