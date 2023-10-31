/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:02:07 by u413q             #+#    #+#             */
/*   Updated: 2023/10/31 18:51:37 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

/* ====== LIBRARIES ====== */

// Standard C libs
# include <stdbool.h>
# include <stdlib.h>

// Home-grown libs
# include "vec3.h"
# include "colour.h"

/* ====== TYPEDEFS ====== */

/**
 * @brief Represents lighting in the scene
 * @param pos		Position of the light
 * @param ratio		Light brightess ratio
 * @param colour	Colour of the light
 */
typedef struct s_light
{
	t_vec3		pos;
	float		ratio;
	t_colour	colour;
}	t_light;

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
}	t_plane;

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
 * @param ambient		Ambient lighting
 * @param lsrc			Light sources
 * @param sp			Array of spheres
 * @param pl			Array of planes
 * @param cy			Array of cylinders
 * @param sp_count		Number of spheres
 * @param pl_count		Number of planes
 * @param cy_count		Number of cylinders
 * @param lsrc_count	Number of light sources
 */
typedef struct s_entities
{
	t_light		ambient;
	t_light		*lsrc;
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
	int			sp_count;
	int			pl_count;
	int			cy_count;
	int			lsrc_count;
}	t_entities;

/* ====== FUNCTIONS ====== */

/**
 * @brief Builds the scene by filling it with entities
 * 
 * @param scene 	Struct with all entities
 */
void		ft_create_scene(t_entities *scene);

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

#endif
