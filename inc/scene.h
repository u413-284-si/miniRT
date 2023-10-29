/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:02:07 by u413q             #+#    #+#             */
/*   Updated: 2023/10/29 12:21:34 by u413q            ###   ########.fr       */
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

/**
 * @brief Represents a sphere
 * @param centre	Centre of the sphere
 * @param r			Radius of the sphere
 * @param colour	Colour of the sphere
 */
typedef struct s_sphere
{
	t_vec3		centre;
	float		r;
	t_colour	colour;
}	t_sphere;

/**
 * @brief Represents a plane
 * @param point		Point on the plane
 * @param normal	Normalised [-1, 1] normal vector of the plane
 * @param colour	Colour of the plane
 */
typedef struct s_plane
{
	t_vec3		point;
	t_vec3		normal;
	t_colour	colour;
}	t_sphere;

/**
 * @brief Represents a cylinder
 * @param centre	Centre of the cylinder
 * @param axis		Normalised [-1, 1] axis of the cylinder
 * @param d			Diameter of the cylinder
 * @param h			Height of the cylinder
 * @param colour	Colour of the cylinder
 */
typedef struct s_cylinder
{
	t_vec3		centre;
	t_vec3		axis;
	float		d;
	float		h;
	t_colour	colour;
}	t_cylinder;

/**
 * @brief Contains all entities in the scene
 * @param sp		Array of spheres
 * @param pl		Array of planes
 * @param cy		Array of cylinders
 */
typedef struct s_entities
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
}	t_entities;

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
 * @param sp		Sphere
 * @param ray 		Ray shot into scene
 * @param rec		Hit record of ray with sphere
 * @param ray_d 	Interval of accepted values of the ray distance for a hit
 * @return float 	Smallest solution = Closest hit point (the one seen by the 
 * camera)
 */
bool	ft_hit_sphere(t_sphere sp, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d);

/**
 * @brief Builds the scene by filling it with entities
 * 
 * @param scene 	Struct with all entities
 */
void	ft_create_scene(t_entities *scene);

#endif
