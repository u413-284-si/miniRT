/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:05:05 by u413q             #+#    #+#             */
/*   Updated: 2023/10/31 18:26:21 by u413q            ###   ########.fr       */
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

#endif
