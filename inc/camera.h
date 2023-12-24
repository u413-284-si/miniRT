/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:40:06 by u413q             #+#    #+#             */
/*   Updated: 2023/12/24 17:38:56 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

/* ====== LIBRARIES ====== */

# include "ray.h"
# include "utils.h"

/* ====== TYPEDEFS ====== */

/**
 * @brief Contains camera parameters
 *
 * @param position				Where the camera is located.
 * @param orientation			How the camera is orientated.
 * @param u						Basis vector pointing to camera right
 * @param v						Basis vector pointing to camera up
 * @param w						Basis vector pointing to opposite view direction
 * @param vup					Camera-relative up direction
 * @param hfov					Horizontal field of view in radians
 */
typedef struct s_cam
{
	t_vec3	position;
	t_vec3	orientation;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
	t_vec3	vup;
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
 * @brief Sets values of camera parameters
 *
 * @param cam 	Struct containing camera parameters
 */
void	ft_initiate_camera(t_cam *cam);

/**
 * @brief Sets values of viewport parameters
 *
 * @param vp		Struct containing viewport parameters
 * @param cam 		Struct containing camera parameters
 * @param size_x	Width of image.
 * @param size_y	Height of image.
 */
void	ft_initiate_viewport(t_viewport *vp, t_cam cam, int size_x, int size_y);

#endif
