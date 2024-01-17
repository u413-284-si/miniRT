/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:05:05 by u413q             #+#    #+#             */
/*   Updated: 2024/01/17 16:31:34 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_BONUS_H
# define COLOUR_BONUS_H

/* ====== LIBRARIES ====== */

# include <stdio.h>
# include <stdint.h>

# include "utils_bonus.h"

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

typedef enum e_col_name
{
	RED,
	GREEN,
	BLUE,
	YELLOW,
	PURPLE,
	CYAN,
	WHITE,
	BLACK,
	ORANGE,
	PINK
}	t_col_name;

/* ====== FUNCTIONS ====== */

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
 * @brief Scales the colour values 
 * 
 * @param c 			Colour to be scaled
 * @param scale 		Scalar
 * @return t_colour 
 */
t_colour	ft_scale_colour(t_colour c, float scale);

/**
 * @brief Converts a t_colour struct to an int32_t.
 *
 * @param colour	Colour to convert.
 * @return int32_t	Converted colour.
 */
int32_t		ft_convert_colour2int(t_colour colour);

/**
 * @brief Converts an int colour to a t_colour struct.
 *
 * @param colour	Int Colour to convert.
 * @return t_colour	Converted t_colour.
 */
t_colour	ft_convert_int2colour(int colour);

/**
 * @brief Returns a colour based on the given colour name.
 *
 * @param col_name	Colour name.
 * @return t_colour	Colour.
 */
t_colour	ft_get_colour(t_col_name col_name);

#endif
