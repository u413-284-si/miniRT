/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:02:44 by u413q             #+#    #+#             */
/*   Updated: 2023/12/25 15:35:38 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

/* ====== LIBRARIES ====== */

# include "entities.h"

/* ====== TYPEDEFS ====== */

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

/**
 * @brief Initiates hitrecord struct
 * 
 * @param rec 		Hitrecord to be initiated
 */
void		ft_init_hitrecord(t_hitrecord *rec);

#endif
