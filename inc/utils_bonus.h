/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:46:04 by u413q             #+#    #+#             */
/*   Updated: 2024/01/12 20:33:37 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

/* ====== LIBRARIES ====== */

# include <math.h>
# include <stdbool.h>
# include <stdlib.h>		// required for rand()

//home-grown libs
# include "vec3.h"

/* ====== MACROS ====== */

# define RAD 0.01745329251
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

/**
 * @brief Quaternion definition with
 * 
 * @param scalar	Real component
 * @param vector	Imaginary component consisting of three values/directions
 */
typedef struct s_quaternion
{
	float	scalar;
	t_vec3	vector;
}	t_quaternion;

/* ====== FUNCTIONS ====== */

/**
 * @brief Transforms degrees into radian
 * 
 * @param degrees 	Angle in degrees
 * @return float 	Angle in radians
 */
float			ft_degree_to_radian(float degrees);

/**
 * @brief Determines if value is inside the interval
 * 
 * @param x 			Value
 * @param interval 		Interval with min and max
 * @return true 		Value is inside the interval
 * @return false 		Value is outside the interval
 */
bool			ft_contains(float x, t_interval interval);

/**
 * @brief Determines if value is surrounded by the interval
 * 
 * @param x 			Value
 * @param interval 		Interval with min and max
 * @return true 		Value is surrounded by the interval
 * @return false 		Value is not surrounded by the interval
 */
bool			ft_surrounds(float x, t_interval interval);

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
float			ft_solve(t_equation *eq);

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
bool			ft_nearly_equal_flt(float one, float two);

/**
 * @brief Return a random float
 * 
 * @return float 
 */
float			ft_random_float(void);

/**
 * @brief Return a random float within min and max
 * 
 * @param min 		Lower bounder
 * @param max 		Upper bounder
 * @return float 
 */
float			ft_random_float_in(float min, float max);

/**
 * @brief Ensure that the returned float lies within the interval
 * 
 * @param x 			Float given
 * @param interval 		Interval with min and max value
 * @return float 
 */
float			ft_clamp(float x, t_interval interval);

/**
 * @brief Initiates interval
 * 
 * @param interval 			Interval to be initiated
 */
void			ft_init_interval(t_interval *interval);


/**
 * @brief 
 * 
 * @param q1 
 * @param q2 
 * @return t_quaternion 
 */
t_quaternion	ft_quaternion_mult(t_quaternion q1, t_quaternion q2);

/**
 * @brief 
 * 
 * @param vec 
 * @param axis 
 * @param angle 
 * @return t_vec3 
 */
t_vec3			ft_quaternion_rot(t_vec3 vec, t_vec3 axis, float angle);

#endif
