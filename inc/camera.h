/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:40:06 by u413q             #+#    #+#             */
/*   Updated: 2023/12/24 18:09:25 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

/* ====== LIBRARIES ====== */

# include "ray.h"
# include "utils.h"

/* ====== TYPEDEFS ====== */

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
 * @param viewport_u			Vector u in viewport coordinates (= x)
 * @param viewport_v			Vector v in viewport coordinates (= -y)
 * @param delta_u				Distance between two pixels in u-direction
 * @param delta_v				Distance between two pixels in v-direction
 * @param viewport_upper_left	Position of upper left corner of viewport
 * @param pixel00_pos			Position of the first pixel (0, 0)
 */
typedef struct s_viewport
{
	float	width;
	float	height;
	t_vec3	delta_u;
	t_vec3	delta_v;
	t_vec3	pixel00_pos;
}	t_viewport;

/**
 * @brief Contains camera parameters
 *
 * @param position				Where the camera is located.
 * @param direction				In which direction the camera is looking.
 * @param u						Basis vector pointing to camera right
 * @param v						Basis vector pointing to camera up
 * @param w						Basis vector pointing to opposite view direction
 * @param hfov					Horizontal field of view in radians
 * @param focal_length			Distance between camera centre and viewport centre.
 */
typedef struct s_cam
{
	t_vec3	position;
	t_vec3	direction;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
	float	hfov;
	float	focal_length;
	t_viewport	vp;
}	t_cam;

/* ====== FUNCTIONS ====== */

/**
 * @brief Sets values of camera parameters
 *
 * @param cam 	Struct containing camera parameters
 */
void	ft_initiate_camera(t_cam *cam, int size_x, int size_y);

void	ft_cam_calc_base_vector(t_cam *cam);
void	ft_cam_calc_viewport_dimensions(t_cam *cam, int size_x, int size_y);
void	ft_cam_calc_viewport_pixels(t_cam *cam, int size_x, int size_y);

#endif
