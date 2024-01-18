/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:46:04 by u413q             #+#    #+#             */
/*   Updated: 2024/01/18 23:50:46 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ====== LIBRARIES ====== */

# include <math.h>
# include <stdbool.h>

//home-grown libs

/* ====== MACROS ====== */

# define RAD 0.01745329251
# define DEG 57.2957795131
# define EPSILON 1e-3

/* ====== TYPEDEFS ====== */

/**
 * @brief Interval of accepted values
 *
 * @param min	Minimum of interval
 * @param max 	Maximum of interval
 */
typedef struct s_interval
{
	float	min;
	float	max;
}	t_interval;

/**
 * @brief Contains factors to solve linear and quadratic equations.
 *
 * ax² + bx + c = 0
 *
 * x = (-b +/- sqr(b² - 4ac)) / 2a
 * Here we use d instead of x as variable to represent the distance of the
 * ray traveled.
 * @param a		Factor of quadratic component
 * @param b		Factor of linear component
 * @param c		Constant
 * @param d1	First solution
 * @param d2	Second solution
 */
typedef struct s_equation
{
	float	a;
	float	b;
	float	c;
	float	d1;
	float	d2;
}	t_equation;

/* ====== FUNCTIONS ====== */

/**
 * @brief Transforms degrees into radian
 *
 * @param degrees 	Angle in degrees
 * @return float 	Angle in radians
 */
float	ft_degree_to_radian(float degrees);

/**
 * @brief Transforms radians into degrees
 *
 * @param radians 	Angle in radians
 * @return float 	Angle in degrees
 */
float	ft_radian_to_degree(float radians);

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
 * @brief Ensure that the returned float lies within the interval
 * 
 * @param x 			Float given
 * @param interval 		Interval with min and max value
 * @return float 
 */
float	ft_clamp(float x, t_interval interval);

#endif
