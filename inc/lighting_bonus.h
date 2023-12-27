/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:18:23 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/27 00:43:28 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_BONUS_H
# define LIGHTING_BONUS_H

/* ====== LIBRARIES ====== */

# include "hit_manager_bonus.h"
# include "camera_bonus.h"

/* ====== TYPEDEFS ====== */

/* ====== FUNCTIONS ====== */

// Lighting
/**
 * @brief Calculate the effect of different lighting on perception
 * 
 * @param ray_colour 	Resulting colour
 * @param rec 			Hit record
 * @param scene 		Scene containing light information
 * @param cam			Camera looking at scene
 */
void		ft_enlighten(t_colour *ray_colour, t_hitrecord rec, \
	t_entities scene, t_cam cam);

/**
 * @brief Create ambient lighting
 * 
 * Ambient light = ambient ratio * light colour
 * @param ambient 		Ambient light parameters
 * @return t_colour 
 */
t_colour	ft_ambient_light(t_light ambient);


/**
 * @brief Create diffuse lighting
 * 
 * Diffuse factor = dot product(light dir, normal vector)
 * Diffuse light = diffuse factor * light colour
 * @param cur 		Current light source
 * @param rec 		Hit record
 * @return t_colour 
 */
t_colour	ft_diffuse_light(t_light cur, t_hitrecord rec);

/**
 * @brief Create specular lighting
 * 
 * Specular factor = (dot product(view dir, reflected dir))^shininess
 * Specular lighting = specular factor * specular strength * light colour
 * @param cur 			Current light source
 * @param rec 			Hit record
 * @param cam 			Camera
 * @return t_colour 
 */
t_colour	ft_specular_light(t_light cur, t_hitrecord rec, t_cam cam);

/**
 * @brief Calculate the reflection vector
 * 
 * @param incoming 	Vector being reflected on surface
 * @param normal 	Surface normal
 * @return t_vec3 
 */
t_vec3		ft_reflect(t_vec3 incoming, t_vec3 normal);

// Shadow realm

/**
 * @brief Determines whether the point of intersection lies in a shadow
 * regarding the current light source
 * 
 * Send ray from intersection point towards the light source and check
 * whether it is blocked or not (= shadow ray)
 * @param cur		Current observed light source 
 * @param rec 		Hit record of point of intersection
 * @param scene 	Scene with all entitites
 * @return true 	If shadow ray doesn't reach the light source
 * @return false 	If shadow ray reaches the light source
 */
bool		ft_in_shadow(t_light cur, t_hitrecord rec, t_entities scene);

/**
 * @brief Determines whether the shadow ray emitted from the 
 * point of intersection is blocked on its way to the light source
 * 
 * An intervall is given to determine the relevant hits
 * min: any value smaller is considered shadow acne (ray hits its 
 * own emitting entity due to rounding errors of the float
 * coordinates of the intersection point)
 * max: distance to light source, anything further away is irrelevant
 * @param scene 		Scene with all entitites
 * @param shadow ray	Shadow ray in question
 * @param ray_d			Intervall for relevant hits
 * @return true 		If shadow ray doesn't reach the light source
 * @return false 		If shadow ray reaches the light source
 */
bool		ft_shadow_ray_blocked(t_entities scene, t_ray shadow_ray, \
	t_interval ray_d);

/**
 * @brief 
 * 
 */
t_colour	ft_reflective_light(t_light cur, t_hitrecord rec, \
	t_entities scene, t_cam cam, int reflection_count);

/**
 * @brief 
 * 
 */
bool		ft_get_closest_hit(t_entities scene, t_ray ray, t_interval ray_d, \
	t_hitrecord *closest);

/**
 * @brief 
 * 
 */
t_colour	ft_compute_colour(t_light cur, t_hitrecord rec, \
	t_entities scene, t_cam cam, int reflection_count);

#endif
