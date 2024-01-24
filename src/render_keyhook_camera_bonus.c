/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_camera_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:43:17 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/24 11:36:37 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	ft_keyhook_rot_cam(int key, t_vec3 *direction, float inc)
{
	if (key == XK_Left)
		*direction = ft_vec3_rotate_y(*direction, inc * 0.1);
	else if (key == XK_Right)
		*direction = ft_vec3_rotate_y(*direction, -inc * 0.1);
	else if (key == XK_Up)
		*direction = ft_vec3_rotate_x(*direction, inc * 0.1);
	else if (key == XK_Down)
		*direction = ft_vec3_rotate_x(*direction, -inc * 0.1);
}

void	ft_keyhook_move_cam(int key, t_cam *cam, float inc)
{
	const t_interval	lim = (t_interval){.min = FLOAT_MIN, .max = FLOAT_MAX};

	if (key == XK_q && cam->centre.y > lim.min)
		ft_cam_move_up(cam, -inc);
	else if (key == XK_e && cam->centre.y < lim.max)
		ft_cam_move_up(cam, inc);
	else if (key == XK_w && cam->centre.z > lim.min)
		ft_cam_move_forward(cam, -inc);
	else if (key == XK_s && cam->centre.z < lim.max)
		ft_cam_move_forward(cam, inc);
	else if (key == XK_d && cam->centre.x < lim.max)
		ft_cam_move_right(cam, inc);
	else if (key == XK_a && cam->centre.x > lim.min)
		ft_cam_move_right(cam, -inc);
}

void	ft_keyhook_fov_cam(int key, t_cam *cam, float inc)
{
	float	fov_in_degree;

	fov_in_degree = ft_radian_to_degree(cam->hfov);
	if (key == XK_r)
	{
		fov_in_degree -= inc;
		if (fov_in_degree < 0)
			fov_in_degree = 0;
	}
	else if (key == XK_f)
	{
		fov_in_degree += inc;
		if (fov_in_degree > 180)
			fov_in_degree = 180;
	}
	cam->hfov = ft_degree_to_radian(fov_in_degree);
}

void	ft_manip_cam(int key, t_cam *cam, float inc, uint32_t *options)
{
	if (key == XK_r || key == XK_f)
	{
		ft_keyhook_fov_cam(key, cam, inc);
		ft_cam_calc_viewport_dimensions(cam);
	}
	else if (key >= XK_Left && key <= XK_Down)
	{
		ft_keyhook_rot_cam(key, &cam->direction, inc);
		ft_cam_calc_base_vectors(cam);
	}
	else
		ft_keyhook_move_cam(key, cam, inc);
	ft_cam_calc_pixel_grid(cam);
	if (ft_option_isset(*options, O_IS_THREADED))
	{
		if (ft_spin_threads(cam, ft_cam_calc_pix_pos_threaded))
			ft_option_clear(options, O_IS_THREADED);
	}
	else
		ft_cam_calc_pix_pos(cam);
	ft_option_set(options, O_SCENE_CHANGED);
}
