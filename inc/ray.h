/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:02:44 by u413q             #+#    #+#             */
/*   Updated: 2024/01/12 20:37:01 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

/* ====== LIBRARIES ====== */

# if IS_BONUS == 1
#  include "entities_bonus.h"
# else
#  include "entities.h"
# endif

/* ====== TYPEDEFS ====== */

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

/* ====== FUNCTIONS ====== */

/**
 * @brief Represents a ray
 *
 * @param ray			General ray created by the image manager
 * @param d 			Distance traveled upon hit
 * @return t_vec3 		Ray vector to hit
 */
t_vec3		ft_ray(t_ray ray, float d);

/**
 * @brief Returns the colour of a ray
 *
 * @param ray 		Ray sent into the scene
 * @param scene		Scene containing all hittable entities
 * @return t_colour Ray colour
 */
t_colour	ft_ray_colour(t_ray ray, t_entities scene);

/**
 * @brief Returns the background colour
 *
 * The background colour depends on the ray direction
 * and creates a transition between two colours
 * @param ray 			Ray shot into scene
 * @return t_colour
 */
t_colour	ft_background_colour(t_ray ray);

#endif
