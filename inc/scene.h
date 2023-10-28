/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:02:07 by u413q             #+#    #+#             */
/*   Updated: 2023/10/28 18:03:46 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

/* ====== LIBRARIES ====== */

// Standard C libs
# include <stdbool.h>

// Home-grown libs
# include "ray.h"

/* ====== DEFINITIONS ====== */


/* ====== DECLARATIONS ====== */

/**
 * @brief Calculates if a sphere was hit by a ray
 * 
 * A quadratic equation gives input on whether the sphere was hit or not.
 * Solutions to this equation can be determined with the discriminant of
 * -b +- sqr(b² - 4ac)/(2a)
 * 
 * Discriminant
 * - is positive => two real solutions = sphere hit twice
 * - is zero => one real solution = one tangential hit
 * - is negative => no real solutions = miss
 * @param sp_centre Centre of the sphere
 * @param r 		Radius of the sphere
 * @param ray 		Ray shot into scene
 * @return float 	Smallest solution = Closest hit point (the one seen by the 
 * camera)
 */
float	ft_hit_sphere(t_vec3 sp_centre, float r, t_ray ray);

#endif
