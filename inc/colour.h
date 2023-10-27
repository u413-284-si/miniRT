/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:05:05 by u413q             #+#    #+#             */
/*   Updated: 2023/10/27 11:37:22 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_H
# define COLOUR_H

/* ====== LIBRARIES ====== */

# include <stdio.h>

/* ====== DEFINITIONS ====== */

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

/* ====== DECLARATIONS ====== */

void	ft_write_colour(t_colour pixel);

#endif
