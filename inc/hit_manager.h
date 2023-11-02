/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:36:21 by u413q             #+#    #+#             */
/*   Updated: 2023/10/31 19:32:11 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_MANAGER_H
# define HIT_MANAGER_H

/* ====== LIBRARIES ====== */

# include "ray.h"
# include "utils.h"

/* ====== TYPEDEFS ====== */

/* ====== FUNCTIONS ====== */

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
 * @param sp		Sphere
 * @param ray 		Ray shot into scene
 * @param rec		Hit record of ray with sphere
 * @param ray_d 	Interval of accepted values of the ray distance for a hit
 * @return true		If sphere is hit
 * @return false	If sphere is missed
 */
bool	ft_hit_sphere(t_sphere sp, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d);

/**
 * @brief Iterates through all spheres in the scene and calls ft_hit_sphere()
 * 
 * @param scene		Scene containing the spheres
 * @param ray 		Ray shot into scene
 * @param rec		Hit record of ray with spheres
 * @param ray_d 	Interval of accepted values of the ray distance for a hit
 * @return true		If sphere is hit
 * @return false	If sphere is missed
 */
bool	ft_hit_scene_sp(t_entities scene, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d);

#endif
