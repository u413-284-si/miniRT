/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:40:06 by u413q             #+#    #+#             */
/*   Updated: 2023/12/16 10:07:34 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

/* ====== LIBRARIES ====== */

# include "ray.h"
# include "utils.h"
# include "mat4.h"
# include "error_syscall.h"

/* ====== MACROS ====== */

# define WIN_X 600
# define WIN_Y 600
# define RATIO 1

/* ====== TYPEDEFS ====== */

/**
 * @brief Contains image parameters
 *
 * @param width			Width of image created
 * @param height		Height of image created
 * @param aspect_ratio	Ratio of width / height
 */
typedef struct s_image
{
	int		width;
	int		height;
	float	aspect_ratio;
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
	//t_vec3	u;
	//t_vec3	v;
	//t_vec3	w;
	t_vec3	vup;
	float	hfov;
	t_mat4	inv_view;
	t_mat4	inv_projection;
	float	pitch;
	float	yaw;
	t_vec3	*cached_rays;
	t_image	screen;
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
void	ft_initiate_image(t_image *image);

/**
 * @brief Sets values of camera parameters
 *
 * @param cam 	Struct containing camera parameters
 */
t_err	ft_initiate_camera(t_cam *cam);

/**
 * @brief Sets values of viewport parameters
 *
 * @param vp	Struct containing viewport parameters
 * @param cam 	Struct containing camera parameters
 * @param image	Struct containing image parameters
 */
void	ft_initiate_viewport(t_viewport *vp, t_cam cam, t_image image);

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
void	ft_create_image(t_image image, t_cam cam, t_viewport vp, \
	t_entities scene);

void	ft_move_cam_forward(t_cam *cam, float dist);
void	ft_move_cam_up(t_cam *cam, float dist);
void	ft_move_cam_right(t_cam *cam, float dist);
void	ft_rotate_cam(t_cam *cam, int delta[2]);

void	ft_cam_calc_inv_view(t_cam *cam);
void	ft_cam_calc_inv_projection(t_cam *cam);
void	ft_cam_update(t_cam *cam, bool update_angle);

#endif
