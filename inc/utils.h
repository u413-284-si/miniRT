/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:46:04 by u413q             #+#    #+#             */
/*   Updated: 2024/01/12 14:02:10 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ====== LIBRARIES ====== */

# include <math.h>
# include <stdbool.h>

//home-grown libs
# include "structs_bonus.h"

/* ====== MACROS ====== */

# define RAD 0.01745329251
# define EPSILON 1e-3

/* ====== TYPEDEFS ====== */

/* ====== FUNCTIONS ====== */

/**
 * @brief Transforms degrees into radian
 * 
 * @param degrees 	Angle in degrees
 * @return float 	Angle in radians
 */
float	ft_degree_to_radian(float degrees);

/**
 * @brief Determines if value is inside the interval
 * 
 * @param x 			Value
 * @param interval 		Interval with min and max
 * @return true 		Value is inside the interval
 * @return false 		Value is outside the interval
 */
bool	ft_contains(float x, t_interval interval);

/**
 * @brief Determines if value is surrounded by the interval
 * 
 * @param x 			Value
 * @param interval 		Interval with min and max
 * @return true 		Value is surrounded by the interval
 * @return false 		Value is not surrounded by the interval
 */
bool	ft_surrounds(float x, t_interval interval);

/**
 * @brief Solves the given equation
 * 
 * If the parameter a = 0, the equation is linear and the sole
 * solution is calculated and stored in d1.
 * Otherwise the equation is quadratic and dependent on the
 * discriminant real solutions exist or not:
 * 
 * Discriminant < 0: no real solution, return -1
 * Discriminant = 0: one solution, return 0
 * Discriminant > 0: two solutions, return > 0
 * @param eq 		Equation to solve
 * @return float
 */
float	ft_solve(t_equation *eq);

/**
 * @brief Checks if two floats are (almost) equal
 * 
 * If their absolute difference is below threshold EPSILON,
 * then they are declared equal
 * @param one 		First float
 * @param two 		Second float
 * @return true 	If both floats are (almost) equal
 * @return false 	If they are not equal
 */
bool	ft_nearly_equal_flt(float one, float two);

/**
 * @brief Initiates interval
 * 
 * @param interval 	Interval to be initiated
 */
void	ft_init_interval(t_interval *interval);

/**
 * @brief Ensure that the returned float lies within the interval
 * 
 * @param x 			Float given
 * @param interval 		Interval with min and max value
 * @return float 
 */
float	ft_clamp(float x, t_interval interval);

#endif
