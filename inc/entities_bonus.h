/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:02:07 by u413q             #+#    #+#             */
/*   Updated: 2024/01/28 17:40:20 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_BONUS_H
# define ENTITIES_BONUS_H

/* ====== LIBRARIES ====== */

# include "entities.h"

/* ====== TYPEDEFS ====== */

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
 * @param WIN_SIZE	(-3) Used for window size: line beginning with R.
 * @param COMMENT	(-2) Used for comments: line beginning with # is ignored.
 * @param UNKNOWN	(-1) Used, if line not recognized, set to -1.
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
 * @param co	Union variable addressed as cone.
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
 * @param checkered		Indicates whether the hittable has a checker texture
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
