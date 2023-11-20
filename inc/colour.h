/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:05:05 by u413q             #+#    #+#             */
/*   Updated: 2023/11/20 16:12:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_H
# define COLOUR_H

/* ====== LIBRARIES ====== */

# include <stdio.h>

/* ====== TYPEDEFS ====== */

/**
 * @brief Represents an RGB colour with float values from 0.0 - 1.0
 * @param r		Red component
 * @param g		Green component
 * @param b		Blue component
 */
typedef struct s_colour
{
	float	r;
	float	g;
	float	b;
}	t_colour;

/* ====== FUNCTIONS ====== */

void		ft_write_colour(t_colour pixel);

/**
 * @brief Add two colours
 *
 * @param c1 	First colour
 * @param c2 	Second colour
 * @return t_colour
 */
t_colour	ft_add_colour(t_colour c1, t_colour c2);

/**
 * @brief Calculates the Hadamard product of two colours
 *
 * Component-wise colour multiplication
 * @param c1 	First colour
 * @param c2 	Second colour
 * @return t_colour
 */
t_colour	ft_hadamard_colour(t_colour c1, t_colour c2);

/**
 * @brief Returns the int value of a t_colour.
 *
 * The colour is saved in t_colour as three floats in range 0.0 to 0.1.
 * Converts floats into ints in range 0 to 255.
 * Uses bit shifting to create new value.
 * @param colour	Colour to convert.
 * @return int		Int value of the color
 */
int	ft_convert_colour2int(t_colour colour);

#endif
