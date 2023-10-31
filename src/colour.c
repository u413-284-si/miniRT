/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:30:57 by u413q             #+#    #+#             */
/*   Updated: 2023/10/31 17:53:06 by u413q            ###   ########.fr       */
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
		.g = c1.g + c2.g,
	});
}

t_colour	ft_hadamard_colour(t_colour c1, t_colour c2)
{
	return ((t_colour){
		.r = c1.r * c2.r,
		.b = c1.b * c2.b,
		.g = c1.g * c2.g,
	});
}
