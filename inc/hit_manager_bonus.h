/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_manager_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:36:21 by u413q             #+#    #+#             */
/*   Updated: 2024/01/09 11:35:29 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_MANAGER_BONUS_H
# define HIT_MANAGER_BONUS_H

/* ====== LIBRARIES ====== */

# include "ray_bonus.h"
# include "utils_bonus.h"
# include "miniRT_config_bonus.h"

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
 * @brief Transforms the Cartesian coordinates of a hit point on a sphere
 * into 2D texture UV-coordinates in the range {0, 1}.
 * 
 * @param rec 	Hit record of ray containing most recent hit
 * @param sp	Sphere struct containing its parameters
 */
void	ft_get_sp_uvcoords(t_hitrecord *rec, t_sphere sp);

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

/**
 * @brief Transforms the Cartesian coordinates of a hit point on a plane
 * into 2D texture UV-coordinates in the range {0, 1}.
 * 
 * @param rec 	Hit record of ray containing most recent hit
 */
void	ft_get_pl_uvcoords(t_hitrecord *rec);

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
 * @brief Transforms the Cartesian coordinates of a hit point on a cylinder wall
 * into 2D texture UV-coordinates in the range {0, 1}.
 * 
 * @param rec 	Hit record of ray containing most recent hit
 * @param cy 	Cylinder struct containing its parameters
 */
void	ft_get_cy_uvcoords(t_hitrecord *rec, t_cylinder cy);

/**
 * @brief Calculates all four potential hits of a cylinder
 * 
 * @param cy				Cylinder
 * @param ray				Ray shot into scene
 * @param potential_hits	Array holding the values of the potential hits
 * @return true 			If cylinder is hit
 * @return false 			If cylinder is missed
 */
bool	ft_cy_calc_pot_hits(t_cylinder cy, t_ray ray, float potential_hits[4]);

/**
 * @brief Calculates the hit point of the ray with the cylinder cap
 * 
 * Utilises the ft_hit_plane() function with the cap parameters given to
 * the plane.
 * @param cy 		Cylinder
 * @param ray 		Ray shot into scene
 * @param cap 		Cap in question
 */
float	ft_cy_cap_hit(t_cylinder cy, t_ray ray, t_vec3 cap);

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
 * @param ray_d				Interval of min and max defining area of visibility
 * @param potential_hits	Float array for four potential hits
 */
bool	ft_cy_visible(t_interval ray_d, float potential_hits[4]);

/**
 * @brief Overwrites the hit record "rec" with the new hit data found in the "tmp" hit
 * record
 * 
 * @param cy 	Cylinder struct containing its parameters
 * @param rec 	Main hit record responsible for colour definition
 * @param tmp 	Temporary hit record to identify the closest hit point
 */
void	ft_cy_set_hitrecord(t_cylinder cy, t_hitrecord *rec, t_hitrecord tmp);


// CONE

/**
 * @brief Calculates if a cone was hit by a ray
 * 
 * The calculation is very similar to the cylinder with a few adjustments in
 * the equation and the amount of possible hits.
 * The ray can hit the cone in three different spots. Two represent the wall 
 * of the cone. The third one is at the end cap or base. The three potential 
 * hits are calculated and checked whether they are "visible" - not blocked 
 * by another object - and if the calculated hit is actually a hit and not
 * result of a rounding error.
 * @param co 		Cone 
 * @param rec 		Hit record of ray containing most recent hit
 * @param ray_d 	Interval of min and max defining area of visibility
 * @return true 	If cone is hit
 * @return false 	If cone is not hit
 */
bool	ft_hit_cone(t_cone co, t_hitrecord *rec, t_interval ray_d);

/**
 * @brief Calculates potential hits of a cone
 * 
 * @param co 				Cone
 * @param ray 				Ray shot into scene
 * @param potential_hits 	Float array for three potential hits
 * @return true 			If cone is potentially hit
 * @return false 			If cone is not hit
 */
bool	ft_co_calc_pot_hits(t_cone co, t_ray ray, float potential_hits[3]);

/**
 * @brief Calculates potential hit of cone cap
 * 
 * @param co		Cone 
 * @param ray 		Ray shot into scene
 * @return float 
 */
float	ft_co_cap_hit(t_cone co, t_ray ray);

/**
 * @brief Determines whether the potential hits are accurate
 * 
 * @param co				Cone
 * @param rec				Hit record containing all meta data of identified hits
 * @param potential_hits	Float array for three potential hits
 */
void	ft_co_identify_hits(t_cone co, t_hitrecord *rec, \
	float potential_hits[3]);

/**
 * @brief Check if the ray actually hit the cone wall
 * 
 * @param co 		Cone
 * @param d 		Distance traveled by ray until hit
 * @param rec 		Hit record containing all meta data of identified hits
 * @return true 	If wall was hit
 * @return false 	If was was not hit
 */
bool	ft_co_check_wall(t_cone co, float d, t_hitrecord *rec);

/**
 * @brief Check if the ray actually hit the cone cap
 * 
 * @param co 		Cone
 * @param d 		Distance traveled by ray until hit
 * @param rec 		Hit record containing all meta data of identified hits
 * @return true 	If cap was hit
 * @return false 	If cap was not hit
 */
bool	ft_co_check_cap(t_cone co, float d, t_hitrecord *rec);

/**
 * @brief Calculates the normal on the point of intersection of the cone
 * 
 * @param rec 		Hit record containing all meta data of identified hit
 * @param co 		Cone
 * @return t_vec3 
 */
t_vec3	ft_co_normal(t_hitrecord rec, t_cone co);

/**
 * @brief Checks whether the cone is blocked by another object
 * 
 * @param ray_d 			Interval of min and max defining area of visibility
 * @param potential_hits 	Float array for three potential hits
 * @return true 			If the cone is visible/not blocked
 * @return false 			If the cone is blocked
 */
bool	ft_co_visible(t_interval ray_d, float potential_hits[3]);

/**
 * @brief Transforms the Cartesian coordinates of a hit point on a cone wall
 * into 2D texture UV-coordinates in the range {0, 1}.
 * 
 * @param rec 	Hit record of ray containing most recent hit
 * @param co 	Cone struct containing its parameters
 */
void	ft_get_co_uvcoords(t_hitrecord *rec, t_cone co);

/**
 * @brief Overwrites the hit record "rec" with the new hit data found in the "tmp" hit
 * record
 * 
 * @param co 	Cone struct containing its parameters
 * @param rec 	Main hit record responsible for colour definition
 * @param tmp 	Temporary hit record to identify the closest hit point
 */
void	ft_co_set_hitrecord(t_cone co, t_hitrecord *rec, t_hitrecord tmp);

#endif
