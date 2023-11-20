/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:02:07 by u413q             #+#    #+#             */
/*   Updated: 2023/11/20 09:30:47 by gwolf            ###   ########.fr       */
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
 * @param sp		Array of spheres
 * @param pl		Array of planes
 * @param cy		Array of cylinders
 * @param sp_count	Number of spheres
 * @param pl_count	Number of planes
 * @param cy_count	Number of cylinders
 */
typedef struct s_entities
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
	int			sp_count;
	int			pl_count;
	int			cy_count;
}	t_entities;

/* ====== FUNCTIONS ====== */

/**
 * @brief Builds the scene by filling it with entities
 *
 * @param scene 	Struct with all entities
 */
void	ft_create_scene(t_entities *scene);

#endif
