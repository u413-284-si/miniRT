/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:02:44 by u413q             #+#    #+#             */
/*   Updated: 2024/01/20 15:59:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_BONUS_H
# define RAY_BONUS_H

/* ====== LIBRARIES ====== */

# include "entities_bonus.h"
# include "camera.h"

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

/* ====== FUNCTIONS ====== */

/**
 * @brief Represents a ray
 *
 * @param ray			General ray created by the image manager
 * @param d 			Distance traveled upon hit
 * @return t_vec3 		Ray vector to hit
 */
t_vec3		ft_scale_ray(t_ray ray, float d);

/**
 * @brief Returns the colour of a ray
 *
 * @param ray 		Ray sent into the scene
 * @param scene		Scene containing all hittable entities
 * @param cam		Camera observing scene
 * @return t_colour Ray colour
 */
t_colour	ft_ray_colour(t_ray ray, t_entities scene, t_cam cam);

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
 * @brief Creates a random sample ray in a square surrounding the current pixel
 *
 * Square side length is the distance to the next pixel.
 * Therefore it extends halfway to each neighbouring pixel.
 * @param pixel_centre	Position of current pixel
 * @param pixels		Pixel grid defining its starting position and
 * 						horizontal/vertical distances
 * @param cam 			Camera
 * @return t_ray
 */
t_ray		ft_create_sample_ray(t_vec3 pixel_centre, t_pixel_grid pixels, \
	t_cam cam);

/**
 * @brief Generate a random vector that is confined within the square
 * surrounding a pixel. The vector lies in the same plane as the viewport.
 *
 * @param pixels		Pixel grid defining its starting position and
 * 						horizontal/vertical distances
 * @return t_vec3
 */
t_vec3		ft_pixel_sample(t_pixel_grid pixels);

/**
 * @brief Returns the colour of a pixel by means of anti-aliasing
 *
 * The pixel colour is generated as an average of a sample of ray colours
 * around the pixel in question.
 * @param iterate		Integer 2D vector containing current pixel position
 * @param pixels		Pixel grid defining its starting position and
 * 						horizontal/vertical distances
 * @param cam			Camera
 * @param scene			The scene containing all hittables
 * @return uint32_t		Colour of pixel.
 */
uint32_t	ft_anti_aliase_colour(t_vec2i iterate, t_pixel_grid pixels, \
	t_cam cam, t_entities scene);

#endif
