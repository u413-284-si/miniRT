/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 11:46:04 by u413q             #+#    #+#             */
/*   Updated: 2023/10/30 11:41:52 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ====== LIBRARIES ====== */

# include <math.h>
# include <stdbool.h>

/* ====== MACROS ====== */

# define RAD 0.01745329251

/* ====== TYPEDEFS ====== */

/**
 * @brief Interval of accepted values
 * @param min	Minimum of interval
 * @param max 	Maximum of interval
 */
typedef struct s_interval
{
	float	min;
	float	max;
}	t_interval;

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

#endif
