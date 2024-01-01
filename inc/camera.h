/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:40:06 by u413q             #+#    #+#             */
/*   Updated: 2024/01/01 17:33:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

/* ====== LIBRARIES ====== */

# include "vec2.h"
# include "vec3.h"
# include "utils.h"

/* ====== TYPEDEFS ====== */

/**
 * @brief Pixel grid is a virtual grid of equispaced pixels in the viewport.
 *
 * The viewport is a virtual rectangle in the 3D world. It contains the grid
 * of image pixel locations. If pixels are equispaced horizontally and verti-
 * cally, the viewport has the same aspect_ratio as the image.
 * @param delta_u		Distance between two pixels in u-direction
 * @param delta_v		Distance between two pixels in v-direction
 * @param pos00			Position of the first pixel (0, 0)
 */
typedef struct s_pixel_grid
{
	t_vec3	delta_u;
	t_vec3	delta_v;
	t_vec3	pos00;
}	t_pixel_grid;

/**
 * @brief Contains camera parameters
 *
 * @param position			Where the camera is located.
 * @param direction			In which direction the camera is looking.
 * @param u					Basis vector pointing to camera right
 * @param v					Basis vector pointing to camera up
 * @param w					Basis vector pointing to opposite view direction
 * @param hfov				Horizontal field of view in radians
 * @param focal_length		Distance between camera centre and viewport centre.
 * @param viewport			Width and height of viewport rectangle
 * @param image				Width and height of image in pixels
 * @param pixels			Pixel grid parameters.
 */
typedef struct s_cam
{
	t_vec3			position;
	t_vec3			direction;
	t_vec3			u;
	t_vec3			v;
	t_vec3			w;
	float			hfov;
	float			focal_length;
	t_vec2f			viewport;
	t_vec2i			image;
	t_pixel_grid	pixels;
}	t_cam;

/* ====== FUNCTIONS ====== */

/**
 * @brief Initializes camera parameters.
 *
 * Calculates the base vectors.
 * Sets the focal length to 10.0.
 * Sets the image size to the given size.
 * Calculates the viewport dimensions.
 * Calculates the pixel grid parameters.
 * @param cam 		Struct containing camera parameters
 * @param img_size	Width and height of image in pixels
 */
void	ft_cam_init(t_cam *cam, t_vec2i img_size);

/**
 * @brief Calculates basis vectors u, v, w
 *
 * Calculates the orthonormal basis (coordinate system) to describe the
 * cameras orientation. The camera is looking down along the negative z-axis,
 * which is the opposite of the view direction (w).
 * The world_up vector represents "up" of the world.
 * It is used to calculate the right direction (u). With these two vectors,
 * the up direction of the camera (v) can be calculated.
 * @param cam 	Struct containing camera parameters
 */
void	ft_cam_calc_base_vectors(t_cam *cam);

/**
 * @brief Calculates viewport dimensions.
 *
 * The viewport is a virtual rectangle in the 3D world containing the grid
 * of image pixel locations.
 * Viewport_width is calculated from the horizontal field of view and
 * the focal length: In a right triangle where the angle at the camera is
 * half FOV, the tangent of this angle is the ratio of the opposite side
 * (half the width of the viewport) to the adjacent side (the focal length
 *  of the camera).
 * Multiplying by 2 then gives the full viewport width.
 * Viewport_height is calculated from the viewport_width and aspect ratio.
 * The aspect ratio is not directly used to minimize rounding errors.
 * @param cam		Struct containing camera parameters.
 */
void	ft_cam_calc_viewport_dimensions(t_cam *cam);

/**
 * @brief Calculates the pixel grid parameters of the viewport.
 *
 * The pixel grid is defined by position of the first pixel (0,0) and
 * the distance between two pixels in u- and v-direction.
 *
 * Fist viewport_u and viewport_v are calculated: vectors across the
 * horizontal and down the vertical viewport edges.
 * The distance between two pixels in u- and v-direction is then
 * calculated from these vectors and the image size.
 *
 * The upper left corner of the viewport is calculated from
 * camera position, view direction and focal length, and viewport_u and -_v.
 * The position of the first pixel is then calculated from the upper left corner.
 * @param cam		Struct containing camera parameters.
 */
void	ft_cam_calc_pixel_grid(t_cam *cam);

// camera_movement.c

/**
 * @brief Moves the camera along its direction vector.
 *
 * Moves the camera forward by the given distance.
 * @param cam		Struct containing camera parameters.
 * @param distance	Distance to move the camera.
 */
void	ft_cam_move_forward(t_cam *cam, float distance);

/**
 * @brief Moves the camera along its right vector.
 *
 * Moves the camera right by the given distance.
 * @param cam		Struct containing camera parameters.
 * @param distance	Distance to move the camera.
 */
void	ft_cam_move_right(t_cam *cam, float distance);

/**
 * @brief Moves the camera along the world up vector.
 *
 * Moves the camera up by the given distance.
 * @param cam		Struct containing camera parameters.
 * @param distance	Distance to move the camera.
 */
void	ft_cam_move_up(t_cam *cam, float distance);

#endif
