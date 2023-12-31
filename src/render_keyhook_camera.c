/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_camera.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:43:17 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/06 19:22:27 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_keyhook_rot_cam(int key, t_vec3 *direction)
{
	if (key == XK_Left)
		*direction = ft_vec3_rotate_y(*direction, MV_UNIT);
	else if (key == XK_Right)
		*direction = ft_vec3_rotate_y(*direction, -MV_UNIT);
	else if (key == XK_Up)
		*direction = ft_vec3_rotate_x(*direction, MV_UNIT);
	else if (key == XK_Down)
		*direction = ft_vec3_rotate_x(*direction, -MV_UNIT);
}

void	ft_keyhook_move_cam(int key, t_cam *cam)
{
	const t_interval	lim = (t_interval){.min = FLOAT_MIN, .max = FLOAT_MAX};

	if (key == XK_q && cam->centre.y > lim.min)
		ft_cam_move_up(cam, -MV_UNIT);
	else if (key == XK_e && cam->centre.y < lim.max)
		ft_cam_move_up(cam, MV_UNIT);
	else if (key == XK_w && cam->centre.z > lim.min)
		ft_cam_move_forward(cam, -MV_UNIT);
	else if (key == XK_s && cam->centre.z < lim.max)
		ft_cam_move_forward(cam, MV_UNIT);
	else if (key == XK_d && cam->centre.x < lim.max)
		ft_cam_move_right(cam, MV_UNIT);
	else if (key == XK_a && cam->centre.x > lim.min)
		ft_cam_move_right(cam, -MV_UNIT);
}

void	ft_keyhook_fov_cam(int key, t_cam *cam)
{
	float	fov_in_degree;

	fov_in_degree = ft_radian_to_degree(cam->hfov);
	if (key == XK_r)
	{
		fov_in_degree -= MV_UNIT;
		if (fov_in_degree < 0)
			fov_in_degree = 0;
	}
	else if (key == XK_f)
	{
		fov_in_degree += MV_UNIT;
		if (fov_in_degree > 180)
			fov_in_degree = 180;
	}
	cam->hfov = ft_degree_to_radian(fov_in_degree);
}

void	ft_manip_cam(int key, t_cam *cam)
{
	if (key == XK_r || key == XK_f)
	{
		ft_keyhook_fov_cam(key, cam);
		ft_cam_calc_viewport_dimensions(cam);
	}
	else if (key >= XK_Left && key <= XK_Down)
	{
		ft_keyhook_rot_cam(key, &cam->direction);
		ft_cam_calc_base_vectors(cam);
	}
	else
		ft_keyhook_move_cam(key, cam);
	ft_cam_calc_pixel_grid(cam);
}
