/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:02:07 by u413q             #+#    #+#             */
/*   Updated: 2024/01/26 10:14:52 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_BONUS_H
# define ENTITIES_BONUS_H

/* ====== LIBRARIES ====== */

// Standard C libs
# include <stdbool.h>
# include <stdlib.h>

// Home-grown libs
# include "vec3.h"
# include "colour_bonus.h"

/* ====== TYPEDEFS ====== */

/**
 * @brief Represents lighting in the scene
 *
 * @param id		ID of the light
 * @param pos		Position of the light
 * @param ratio		Light brightess ratio
 * @param colour	Colour of the light
 */
typedef struct s_light
{
	int			id;
	t_vec3		pos;
	float		ratio;
	t_colour	colour;
}	t_light;

/**
 * @brief Represents a sphere
 *
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
 *
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
 *
 * @param centre	Centre of the cylinder
 * @param axis		Normalised [-1, 1] axis of the cylinder
 * @param r			Radius of the cylinder
 * @param h			Height of the cylinder
 * @param colour	Colour of the cylinder
 * @param cap1		Centre of first cap = centre - h/2 * axis
 * @param cap2		Centre of second cap = centre + h/2 * axis
 */
typedef struct s_cylinder
{
	t_vec3		centre;
	t_vec3		axis;
	float		r;
	float		h;
	t_colour	colour;
	t_vec3		cap1;
	t_vec3		cap2;
}	t_cylinder;

/**
 * @brief Represents a cone
 *
 * @param apex		Apex point of the cone
 * @param base		Base of the cone
 * @param axis		Normalised [-1, 1] axis of the cone
 * @param r			Radius of the circular base
 * @param h			Height of the cone
 * @param angle		Half angle of the cone
 * @param colour	Colour of the cone
 */
typedef struct s_cone
{
	t_vec3		apex;
	t_vec3		base;
	t_vec3		axis;
	float		r;
	float		h;
	float		angle;
	t_colour	colour;
}	t_cone;

/**
 * @brief Enumeration of all different entity types.
 *
 * @param COMMENT	Used for comments: line beginning with # is ignored.
 * @param UNKOWN	Used, if line not recognized, set to -1.
 * @param SUM_ENTS	Amounts to sum of all entity types.
 */
typedef enum e_type
{
	WIN_SIZE = -3,
	COMMENT = -2,
	UNKNOWN = -1,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
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
	t_cone		co;
}	t_shape;

/**
 * @brief Represents a hittable
 *
 * @param id			The hittables ID
 * @param type			The hittables type
 * @param params		Required parameters to distinctly describe the hittable
 * @param shininess		Material property of point of intersection
 * 						on the breadth of the angle of specular reflection
 * 						(the higher, the smoother the surface appears)
 * @param reflectivity	Material property of point of intersection
 * 						on share of reflected light
 * @param Checkered		Indicates whether the hittable has a checker texture
 */
typedef struct s_hittable
{
	int		id;
	t_type	type;
	t_shape	params;
	float	shininess;
	float	reflectivity;
	float	checkered;
}	t_hittable;

/**
 * @brief Contains all entities in the scene
 * @param ambient		Ambient lighting
 * @param lsrc			Light sources
 * @param obj			Array of hittables
 * @param lsrc_count	Number of light sources
 * @param total			Number of hittables
 */
typedef struct s_entities
{
	t_light		ambient;
	t_light		*lsrc;
	t_hittable	*obj;
	int			lsrc_count;
	int			total;
}	t_entities;

#endif
