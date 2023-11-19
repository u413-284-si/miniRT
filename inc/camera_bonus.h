/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:40:06 by u413q             #+#    #+#             */
/*   Updated: 2023/11/19 22:43:49 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_BONUS_H
# define CAMERA_BONUS_H

/* ====== LIBRARIES ====== */

# include "ray_bonus.h"
# include "utils_bonus.h"

/* ====== TYPEDEFS ====== */

/**
 * @brief Contains image parameters
 * 
 * @param aspect_ratio			Ratio of image_width / image_height
 * @param image_width			Width of image created
 * @param image_height			Height of image created
 */
typedef struct s_image
{
	float	aspect_ratio;
	int		image_width;
	int		image_height;
}	t_image;

/**
 * @brief Contains camera parameters
 * 
 * @param look_from				Position the camera is looking from
 * @param look_at				Position the camera is looking at
 * @param u						Basis vector pointing to camera right
 * @param v						Basis vector pointing to camera up
 * @param w						Basis vector pointing to opposite view direction
 * @param vup					Camera-relative up direction
 * @param camera_centre			Camera position
 * @param hfov					Horizontal field of view in degrees
 */
typedef struct s_cam
{
	t_vec3	look_from;
	t_vec3	look_at;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
	t_vec3	vup;
	t_vec3	camera_centre;
	float	hfov;
}	t_cam;

/**
 * @brief Contains viewport parameters
 * 
 * The viewport is a virtual rectangle in the 3D world containing the grid
 * of image pixel locations. If pixels are equispaced horizontally and verti-
 * cally, the viewport has the same aspect_ratio as the image.
 * The focal length is the distance between the camera centre and the viewport
 * centre (vector orthogonal on viewport plane).
 * @param viewport_width		Width of viewport rectangle
 * @param viewport_height		Height of viewport rectangle
 * @param focal_length			Distance between camera centre and viewport centre
 * @param viewport_u			Vector u in viewport coordinates (= x)
 * @param viewport_v			Vector v in viewport coordinates (= -y)
 * @param delta_u				Distance between two pixels in u-direction
 * @param delta_v				Distance between two pixels in v-direction
 * @param viewport_upper_left	Position of upper left corner of viewport
 * @param pixel00_pos			Position of the first pixel (0, 0)
 */
typedef struct s_viewport
{
	float	viewport_width;
	float	viewport_height;
	float	focal_length;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	delta_u;
	t_vec3	delta_v;
	t_vec3	viewport_upper_left;
	t_vec3	pixel00_pos;
}	t_viewport;

/* ====== FUNCTIONS ====== */

/**
 * @brief Sets values of image parameters
 * 
 * @param image Struct containing image parameters
 */
void		ft_initiate_image(t_image *image);

/**
 * @brief Sets values of camera parameters
 * 
 * @param cam 	Struct containing camera parameters
 */
void		ft_initiate_camera(t_cam *cam);

/**
 * @brief Sets values of viewport parameters
 * 
 * @param vp	Struct containing viewport parameters
 * @param cam 	Struct containing camera parameters
 * @param image	Struct containing image parameters
 */
void		ft_initiate_viewport(t_viewport *vp, t_cam cam, t_image image);

/**
 * @brief Generates an image
 * 
 * Creates rays for each pixel of the image and "shoots" them
 * through the according pixel in the viewport. The colour of
 * each ray is returned and used to print out an image.
 * @param image		Struct containing image parameters 
 * @param cam 		Struct containing image and viewport parameters
 * @param vp		Struct containing viewport parameters
 * @param scene		Scene containing all hittable entities
 */
void		ft_create_image(t_image image, t_cam cam, t_viewport vp, \
	t_entities scene);

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
 * @param iterate		Integer array containing current pixel position and amount of samples
 * @param vp			Viewport
 * @param cam			Camera
 * @param scene			The scene containing all hittables
 * @return t_colour
 */
t_colour	ft_get_colour(int iterate[3], t_viewport vp, t_cam cam, \
	t_entities scene);

#endif
