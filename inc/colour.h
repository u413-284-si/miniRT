/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:05:05 by u413q             #+#    #+#             */
/*   Updated: 2023/10/30 11:43:59 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_H
# define COLOUR_H

/* ====== LIBRARIES ====== */

# include <stdio.h>

/* ====== TYPEDEFS ====== */

/**
 * @brief Represents an RGB colour with float values from 0.0 - 1.0
 * @param r	red component
 * @param g	green component
 * @param b	blue component
 */
typedef struct s_colour
{
	float	r;
	float	g;
	float	b;
}	t_colour;

/* ====== FUNCTIONS ====== */

void	ft_write_colour(t_colour pixel);

#endif
