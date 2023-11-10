/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:36:21 by u413q             #+#    #+#             */
/*   Updated: 2023/11/10 19:36:13 by sqiu             ###   ########.fr       */
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
 * @brief Investigate a hittable and returns whether a hit
 * occured or not
 * 
 * @param obj		Hittable in question
 * @param ray 		Ray shot into scene
 * @param rec		Hit record of ray with hittable
 * @param ray_d 	Interval of accepted values of the ray distance for a hit
 * @return true		If hittable is hit
 * @return false	If hittable is missed
 */
bool	ft_hit_scene(t_hittable obj, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d);

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

/**
 * @brief Calculates if a plane was hit by a ray
 * 
 * If the ray hits the plane, the dot product between the vector created
 * going from a point on the plane P0 to the point of intersection P and the
 * plane normal is zero. This gives an equation
 * d = dot((P0 - A), n) / dot(B, n)
 * 
 * with:
 * 			A: Point of origin of ray
 * 			B: Direction of ray
 * 			n: Plane normal 
 * 
 * to solve for the distance traveled d by the ray.
 * @param pl 		Plane
 * @param ray 		Ray shot into scene
 * @param rec 		Hit record of ray with plane
 * @param ray_d 	Interval of accepted values of the ray distance for a hit
 * @return true 	If plane is hit
 * @return false 	If plane is missed
 */
bool	ft_hit_plane(t_plane pl, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d);

/**
 * @brief Iterates through all planes in the scene and calls ft_hit_plane()
 * 
 * @param scene		Scene containing the planes
 * @param ray 		Ray shot into scene
 * @param rec		Hit record of ray with planes
 * @param ray_d 	Interval of accepted values of the ray distance for a hit
 * @return true		If plane is hit
 * @return false	If plane is missed
 */
bool	ft_hit_scene_pl(t_entities scene, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d);

/**
 * @brief Calculates if a cylinder was hit by a ray
 * 
 * If the ray hits the plane, the dot product between the vector created
 * going from a point on the plane P0 to the point of intersection P and the
 * plane normal is zero. This gives an equation
 * d = dot((P0 - A), n) / dot(B, n)
 * 
 * with:
 * 			A: Point of origin of ray
 * 			B: Direction of ray
 * 			n: Plane normal 
 * 
 * to solve for the distance traveled d by the ray.
 * @param pl 		Plane
 * @param ray 		Ray shot into scene
 * @param rec 		Hit record of ray with plane
 * @param ray_d 	Interval of accepted values of the ray distance for a hit
 * @return true 	If plane is hit
 * @return false 	If plane is missed
 */
bool	ft_hit_cylinder(t_cylinder cy, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d);

int		ft_hit_cylindersphere(t_sphere sp, t_ray ray, float d[2]);

#endif
