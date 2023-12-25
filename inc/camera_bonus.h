/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:40:06 by u413q             #+#    #+#             */
/*   Updated: 2023/12/25 19:34:58 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_BONUS_H
# define CAMERA_BONUS_H

/* ====== LIBRARIES ====== */

# include "ray_bonus.h"
# include "utils_bonus.h"
# include "miniRT_config_bonus.h"
# include "structs_bonus.h"

/* ====== TYPEDEFS ====== */

/* ====== FUNCTIONS ====== */

/**
 * @brief Sets values of camera parameters
 * 
 * @param cam 	Struct containing camera parameters
 */
void		ft_initiate_camera(t_cam *cam);

/**
 * @brief Sets values of viewport parameters
 *
 * @param vp		Struct containing viewport parameters
 * @param cam 		Struct containing camera parameters
 * @param size_x	Width of image.
 * @param size_y	Height of image.
 */
void		ft_initiate_viewport(t_viewport *vp, t_cam cam, int size_x, \
	int size_y);

/**
 * @brief Creates a random sample ray in a square surrounding the current pixel
 * 
 * Square size is the distance to the next pixel. Therefore it extends halfway
 * to each neighbouring pixel.
 * @param i 		Current pixel position within a row
 * @param j 		Current pixel position within a column
 * @param vp 		Viewport
 * @param cam 		Camera
 * @return t_ray 
 */
t_ray		ft_create_sample_ray(int i, int j, t_viewport vp, t_cam cam);

/**
 * @brief Generate a random vector that is confined within the square
 * surrounding a pixel. The vector lies in the same plane as the viewport.
 * 
 * @param vp		Viewport 
 * @return t_vec3 
 */
t_vec3		ft_pixel_sample(t_viewport vp);

/**
 * @brief Returns the colour of a pixel by means of anti-aliasing
 * 
 * The pixel colour is generated as an average of a sample of ray colours
 * around the pixel in question.
 * @param iterate		Integer array containing current pixel position
 * @param vp			Viewport
 * @param cam			Camera
 * @param scene			The scene containing all hittables
 * @return t_colour
 */
t_colour	ft_sum_up_colour_samples(int iterate[2], t_viewport vp, t_cam cam, \
	t_entities scene);

/**
 * @brief Returns a sampled down colour
 * 
 * @param pixel 		Colour of pixel
 * @param samples 		Amount of samples
 * @return t_colour 
 */
t_colour	ft_sample_down(t_colour pixel, int samples);

#endif
