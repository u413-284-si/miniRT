/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:02:44 by u413q             #+#    #+#             */
/*   Updated: 2023/12/16 16:43:53 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

/* ====== LIBRARIES ====== */

# include "entities.h"

/* ====== TYPEDEFS ====== */

/**
 * @brief Represents a ray
 * @param origin	point of ray origin
 * @param direction	vector of ray direction
 * @param d			distance into ray direction
 */
typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
	float	d;
}	t_ray;

/**
 * @brief Shows point of intersection
 * @param point		Point of intersection
 * @param normal	Normal vector at point of intersection
 * @param axis_hit	Point of intersection with a cylinders axis
 * @param d			Distance into ray direction when point is hit
 * @param colour	Colour of object at intersection
 */
typedef struct s_hitrecord
{
	t_vec3		point;
	t_vec3		normal;
	t_vec3		axis_hit;
	float		d;
	t_colour	colour;
}	t_hitrecord;

/* ====== FUNCTIONS ====== */

/**
 * @brief Represents a ray
 * 
 * @param ray			General ray created by the image manager
 * @param d 			Distance traveled upon hit
 * @return t_vec3 		Ray vector to hit
 */
t_vec3		ft_ray(t_ray ray, float d);

/**
 * @brief Returns the colour of a ray
 * 
 * @param ray 		Ray sent into the scene
 * @param scene		Scene containing all hittable entities
 * @return t_colour Ray colour
 */
t_colour	ft_ray_colour(t_ray ray, t_entities scene);

/**
 * @brief Returns the background colour
 * 
 * The background colour depends on the ray direction
 * and creates a transition between two colours
 * @param ray 			Ray shot into scene
 * @return t_colour 
 */
t_colour	ft_background_colour(t_ray ray);

/**
 * @brief Initiates hitrecord struct
 * 
 * @param rec 		Hitrecord to be initiated
 */
void		ft_init_hitrecord(t_hitrecord *rec);

#endif
