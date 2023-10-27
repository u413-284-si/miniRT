/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:02:44 by u413q             #+#    #+#             */
/*   Updated: 2023/10/27 15:30:08 by u413q            ###   ########.fr       */
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

/* ====== DECLARATIONS ====== */

/**
 * @brief 
 * 
 * @param origin 
 * @param direction 
 * @param d 
 * @return t_vec3 
 */
t_vec3		ft_ray(t_vec3 origin, t_vec3 direction, float d);

/**
 * @brief Returns the colour of a ray
 * 
 * @param ray Ray sent into the scene
 * @return t_colour Ray colour
 */
t_colour	ft_ray_colour(t_ray ray);

#endif
