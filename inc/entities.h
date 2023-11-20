/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:02:07 by u413q             #+#    #+#             */
/*   Updated: 2023/11/20 09:43:27 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H
# define ENTITIES_H

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
 * @param cap1		Centre of first cap = centre - h/2 * axis
 * @param cap2		Centre of second cap = centre + h/2 * axis
 * @param d			Diameter of the cylinder
 * @param h			Height of the cylinder
 * @param colour	Colour of the cylinder
 */
typedef struct s_cylinder
{
	t_vec3		centre;
	t_vec3		axis;
	t_vec3		cap1;
	t_vec3		cap2;
	float		d;
	float		h;
	t_colour	colour;
}	t_cylinder;

/**
 * @brief Enumeration of all different entity types.
 * 
 * @param UNKOWN	Used, if line not recognized, set to -1.
 * @param SUM_ENTS	Amounts to sum of all entity types.
 */
typedef enum e_type
{
	UNKNOWN = -1,
	SPHERE,
	PLANE,
	CYLINDER,
	AMBIENT,
	CAMERA,
	LIGHT,
	SUM_ENTS
}	t_type;

/**
 * @brief Contains information of the different shapes
 *
 * Each union represents one shape which can be addressed
 * by the respective member. The memory space can be interpreted
 * with different names (its members) as a variable. It
 * has the size of the biggest member type.
 * @param sp	Union variable addressed as sphere.
 * @param pl	Union variable addressed as plane.
 * @param cy	Union variable addressed as cylinder.
 */
typedef union u_shape
{
	t_sphere	sp;
	t_plane		pl;
	t_cylinder	cy;
}	t_shape;

/**
 * @brief Represents a hittable
 *
 * @param id		The hittables ID
 * @param type		The hittables type
 * @param params	Required parameters to distinctly describe the hittable
 */
typedef struct s_hittable
{
	int		id;
	t_type	type;
	t_shape	params;
}	t_hittable;

/**
 * @brief Contains all entities in the scene
 * @param ambient		Ambient lighting
 * @param lsrc			Light sources
 * @param obj			Array of hittables
 * @param sp_count		Number of spheres
 * @param pl_count		Number of planes
 * @param cy_count		Number of cylinders
 * @param lsrc_count	Number of light sources
 */
typedef struct s_entities
{
	t_light		ambient;
	t_light		*lsrc;
	t_hittable	*obj;
	int			sp_count;
	int			pl_count;
	int			cy_count;
	int			lsrc_count;
	int			total;
}	t_entities;

#endif
