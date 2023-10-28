/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:02:44 by u413q             #+#    #+#             */
/*   Updated: 2023/10/28 19:39:49 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

/* ====== LIBRARIES ====== */

# include "vec3.h"
# include "colour.h"

/* ====== DEFINITIONS ====== */

/**
 * @brief Represents a ray
 * @param origin	point of ray origin
 * @param direction	vector of ray direction
 * @param d			distance into ray direction
 */
typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
	float	d;
}	t_ray;

/**
 * @brief Shows point of intersection
 * @param point		point of intersection
 * @param normal	normal vector at point of intersection
 * @param d			distance into ray direction when point is hit
 */
typedef struct s_hitrecord
{
	t_vec3	point;
	t_vec3	normal;
	float	d;
}	t_hitrecord;

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

/* ====== DECLARATIONS ====== */

/**
 * @brief 
 * 
 * @param origin 
 * @param direction 
 * @param d 
 * @return t_vec3 
 */
t_vec3		ft_ray(t_ray ray, float d);

/**
 * @brief Returns the colour of a ray
 * 
 * @param ray Ray sent into the scene
 * @return t_colour Ray colour
 */
t_colour	ft_ray_colour(t_ray ray);

#endif
