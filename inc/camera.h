/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:40:06 by u413q             #+#    #+#             */
/*   Updated: 2023/10/30 11:43:51 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

/* ====== LIBRARIES ====== */

# include "ray.h"

/* ====== TYPEDEFS ====== */

/**
 * @brief Contains camera, image and viewport parameters
 * 
 * The viewport is a virtual rectangle in the 3D world containing the grid
 * of image pixel locations. If pixels are equispaced horizontally and verti-
 * cally, the viewport has the same aspect_ratio as the image.
 * The focal length is the distance between the camera centre and the viewport
 * centre (vector orthogonal on viewport plane).
 * @param aspect_ratio			Ratio of image_width / image_height
 * @param image_width			Width of image created
 * @param image_height			Height of image created
 * @param viewport_width		Width of viewport rectangle
 * @param viewport_height		Height of viewport rectangle
 * @param focal_length			Distance between camera centre and viewport centre
 * @param viewport_u			Vector u in viewport coordinates (= x)
 * @param viewport_v			Vector v in viewport coordinates (= -y)
 * @param viewport_w			Vector w in viewport coordinates (= -z)
 * @param delta_u				Distance between two pixels in u-direction
 * @param delta_v				Distance between two pixels in v-direction
 * @param viewport_upper_left	Position of upper left corner of viewport
 * @param pixel00_pos			Position of the first pixel (0, 0)
 */
typedef struct s_cam
{
	float	aspect_ratio;
	int		image_width;
	int		image_height;
	float	viewport_width;
	float	viewport_height;
	float	focal_length;
	t_vec3	camera_centre;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	viewport_w;
	t_vec3	delta_u;
	t_vec3	delta_v;
	t_vec3	viewport_upper_left;
	t_vec3	pixel00_pos;
}	t_cam;

/* ====== FUNCTIONS ====== */

/**
 * @brief Sets values of camera parameters
 * 
 * @param cam Struct containing camera parameters
 */
void	ft_initiate_camera(t_cam *cam);

/**
 * @brief Sets values of viewport parameters
 * 
 * @param cam Struct containing viewport parameters
 */
void	ft_initiate_viewport(t_cam *cam);

/**
 * @brief Generates an image
 * 
 * Creates rays for each pixel of the image and "shoots" them
 * through the according pixel in the viewport. The colour of
 * each ray is returned and used to print out an image. 
 * @param cam 		Struct containing image and viewport parameters
 * @param scene		Scene containing all hittable entities
 */
void	ft_create_image(t_cam cam, t_entities scene);


#endif
