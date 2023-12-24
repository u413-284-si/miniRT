/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:48:56 by u413q             #+#    #+#             */
/*   Updated: 2023/12/24 17:49:31 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	ft_cam_calc_base_vector(t_cam *cam)
{
	const t_vec3	world_up = {0.0, 1.0, 0.0};

	cam->w = ft_vec3_norm(ft_vec3_sub(cam->position, cam->direction));
	cam->u = ft_vec3_cross(world_up, cam->w);
	cam->v = ft_vec3_cross(cam->w, cam->u);
}

void	ft_cam_calc_viewport_dimensions(t_cam *cam, int size_x, int size_y)
{
	cam->viewport_width = 2 * tan(cam->hfov / 2) * cam->focal_length;
	cam->viewport_height = cam->viewport_width / size_x * size_y;
}

void	ft_initiate_camera(t_cam *cam)
{
	ft_cam_calc_base_vector(cam);
	cam->focal_length = 10.0;
	ft_cam_calc_viewport_dimensions(cam, 800, 600);
}

void	ft_initiate_viewport(t_viewport *vp, t_cam cam, int size_x, int size_y)
{
	vp->viewport_u = ft_vec3_scale(cam.u, cam.viewport_width);
	vp->viewport_v = ft_vec3_scale(cam.v, -cam.viewport_height);
	vp->delta_u = ft_vec3_scale(vp->viewport_u, \
		(float)(1.0 / size_x));
	vp->delta_v = ft_vec3_scale(vp->viewport_v, \
		(float)(1.0 / size_y));
	vp->viewport_upper_left = ft_vec3_sub(ft_vec3_sub(ft_vec3_sub(\
		cam.position, ft_vec3_scale(cam.w, cam.focal_length)), \
		ft_vec3_scale(vp->viewport_u, 0.5)), \
		ft_vec3_scale(vp->viewport_v, 0.5));
	vp->pixel00_pos = ft_vec3_add(vp->viewport_upper_left, ft_vec3_scale(\
		ft_vec3_add(vp->delta_u, vp->delta_v), 0.5));
}
