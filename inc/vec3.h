/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:45:53 by sqiu              #+#    #+#             */
/*   Updated: 2023/10/16 16:20:26 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

/* ====== DEFINITIONS ====== */

/**
 * @brief Represents a tridimensional vector
 * @param x	The x coordinate
 * @param y	The y coordinate
 * @param z	The z coordinate
 */
typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

/* ====== DECLARATIONS ====== */

/**
 * @brief Add two vectors
 * @param v1	The first vector
 * @param v2	The second vector
 * @return t_vec3
 */
t_vec3	ft_vec3_add(t_vec3 v1, t_vec3 v2);

/**
 * @brief Subtract two vectors
 * @param v1	The vector from which to subtract (minuend)
 * @param v2	The vector being subtracted (subtrahend)
 * @return t_vec3
 */
t_vec3	ft_vec3_sub(t_vec3 v1, t_vec3 v2);

/**
 * @brief Scale a vector
 * @param v		The vector to be scaled
 * @param a		Scalar	
 * @return t_vec3
 */
t_vec3	ft_vec3_scale(t_vec3 v, float a);

/**
 * @brief Calculate the scalar product of two vectors
 * @param v1	The first vector
 * @param v2	The second vector
 * @return float
 */
float	ft_vec3_dot(t_vec3 v1, t_vec3 v2);

/**
 * @brief Calculate the cross product of two vectors
 * @param v1	The first vector
 * @param v2	The second vector
 * @return t_vec3
 */
t_vec3	ft_vec3_cross(t_vec3 v1, t_vec3 v2);

/**
 * @brief Calculate the absolute value of a vector
 * @param v	The vector
 * @return float
 */
float	ft_vec3_abs(t_vec3 v);

/**
 * @brief Normalise a vector
 * @param v	The vector
 * @return t_vec3
 */
t_vec3	ft_vec3_norm(t_vec3 v);

/**
 * @brief Calculate the angle betwee two vectors
 * @param v1	The first vector
 * @param v2	The second vector
 * @return float
 */
float	ft_vec3_angle(t_vec3 v1, t_vec3 v2);

#endif
