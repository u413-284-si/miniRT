/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:36:21 by u413q             #+#    #+#             */
/*   Updated: 2023/12/25 13:18:18 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_MANAGER_H
# define HIT_MANAGER_H

/* ====== LIBRARIES ====== */

# include "ray.h"
# include "utils.h"

/* ====== MACROS ====== */

/* ====== TYPEDEFS ====== */

/* ====== FUNCTIONS ====== */

/**
 * @brief Investigate a hittable and returns whether a hit
 * occured or not
 * 
 * @param obj		Hittable in question
 * @param rec		Hit record of ray with hittable
 * @param ray_d 	Interval of accepted values of the ray distance for a hit
 * @return true		If hittable is hit
 * @return false	If hittable is missed
 */
bool	ft_hit_hittable(t_hittable obj, t_hitrecord *rec, t_interval ray_d);

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
 * @param rec		Hit record of ray containing most recent hit
 * @param ray_d 	Interval of accepted values of the ray distance for a hit
 * @return true		If sphere is hit
 * @return false	If sphere is missed
 */
bool	ft_hit_sphere(t_sphere sp, t_hitrecord *rec, t_interval ray_d);

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
 * @param rec 		Hit record of ray containing most recent hit
 * @param ray_d 	Interval of accepted values of the ray distance for a hit
 * @return true 	If plane is hit
 * @return false 	If plane is missed
 */
bool	ft_hit_plane(t_plane pl, t_hitrecord *rec, t_interval ray_d);

// CYLINDER
/**
 * @brief Calculates if a cylinder was hit by a ray
 * 
 * The ray can hit the cylinder in four different spots. Two represent the wall 
 * of the cylinder. Further two the respective end caps. The four potential 
 * hits are calculated and checked whether they are "visible" - not blocked 
 * by another object - and if the calculated hit is actually a hit and not
 * result of a rounding error.
 * @param cy 		Cylinder
 * @param rec 		Hit record of ray containing most recent hit
 * @param ray_d 	Interval of accepted values of the ray distance for a hit
 * @return true 	If cylinder is hit
 * @return false 	If cylinder is missed
 */
bool	ft_hit_cylinder(t_cylinder cy, t_hitrecord *rec, t_interval ray_d);

/**
 * @brief Calculates all four potential hits of a cylinder
 * 
 * @param cy				Cylinder
 * @param ray				Ray shot into scene
 * @param ray_d				Interval of accepted values of the ray distance for a hit
 * @param potential_hits	Array holding the values of the potential hits
 * @return true 			If cylinder is hit
 * @return false 			If cylinder is missed
 */
bool	ft_cy_calculate_pot_hits(t_cylinder cy, t_ray ray, t_interval ray_d, \
	float potential_hits[4]);

/**
 * @brief Calculates the hit point of the ray with the cylinder cap
 * 
 * Utilises the ft_hit_plane() function with the cap parameters given to
 * the plane.
 * @param cy 		Cylinder
 * @param ray 		Ray shot into scene
 * @param cap 		Cap in question
 * @param d 		Distance of ray, if a hit was detected
 */
void	ft_cy_hit_cap(t_cylinder cy, t_ray ray, t_vec3 cap, float *d);

/**
 * @brief Determines if the potential hits are accurate
 * 
 * @param cy				Cylinder
 * @param potential_hits	Array holding the values of the potential hits
 * @param rec 				Hit record of ray containing most recent hit
 * @return true 			If cylinder is hit
 * @return false 			If cylinder is missed
 */
void	ft_cy_identify_hits(t_cylinder cy, float potential_hits[4], \
	t_hitrecord *rec);

/**
 * @brief Calculates the normal on the point of intersection of the cylinder
 * 
 * @param rec 			Hit record of ray containing intersection with cylinder
 * @param cy 			Cylinder
 * @return t_vec3 
 */
t_vec3	ft_cy_normal(t_hitrecord rec, t_cylinder cy);

/**
 * @brief Checks if the ray actually hit the cylinder wall
 * 
 * Verifies if hit point is within the boundaries of the cylinder height
 * and radius. Also discriminates rounding errors.
 * @param cy 			Cylinder
 * @param d 			Distance of ray indicating the potential hit
 * @param rec 			Hit record of ray containing most recent hit
 * @return true 		If wall is hit
 * @return false 		If wall is missed
 */
bool	ft_cy_check_wall(t_cylinder cy, float d, t_hitrecord *rec);

/**
 * @brief Checks if the ray actually hit the cylinder cap
 * 
 * Verifies if hit point is within the boundaries of the cylinder radius.
 * Also discriminates rounding errors.
 * @param cy 			Cylinder
 * @param cap			Cap in question
 * @param d 			Distance of ray indicating the potential hit
 * @param rec			Hit record of ray containing most recent hit
 * @return true 		If cap is hit
 * @return false 		If cap is missed
 */
bool	ft_cy_check_cap(t_cylinder cy, t_vec3 cap, float d, t_hitrecord *rec);

/**
 * @brief Checks if cylinder is not blocked by another object
 * 
 * Takes potential hits and verifies that they lie within the
 * boundaries defined by ray_d
 * @param eq		Equation holding values one and two
 * @param ray_d		Interval of min and max defining area of visibility
 * @param d3		Distance of ray indicating potential hit with one cap
 * @param d4		Distance of ray indicating potential hit with other cap
 */
bool	ft_cy_visible(t_equation eq, t_interval ray_d, float d3, \
	float d4);

#endif
