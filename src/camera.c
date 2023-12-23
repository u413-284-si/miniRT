/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/12/23 19:15:54 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "camera.h"

void	ft_initiate_camera(t_cam *cam)
{
	cam->vup.x = 0.0;
	cam->vup.y = 1.0;
	cam->vup.z = 0.0;
	cam->camera_centre.x = cam->look_from.x;
	cam->camera_centre.y = cam->look_from.y;
	cam->camera_centre.z = cam->look_from.z;
	cam->w = ft_vec3_norm(ft_vec3_sub(cam->look_from, cam->look_at));
	cam->u = ft_vec3_norm(ft_vec3_cross(cam->vup, cam->w));
	cam->v = ft_vec3_cross(cam->w, cam->u);
}

void	ft_initiate_viewport(t_viewport *vp, t_cam cam, int size_x, int size_y)
{
	float	hfov_rad;

	vp->focal_length = ft_vec3_abs(ft_vec3_sub(cam.look_from, cam.look_at));
	hfov_rad = ft_degree_to_radian(cam.hfov);
	vp->viewport_width = 2 * tan(hfov_rad / 2) * vp->focal_length;
	vp->viewport_height = vp->viewport_width / size_x * size_y;
	vp->viewport_u = ft_vec3_scale(cam.u, vp->viewport_width);
	vp->viewport_v = ft_vec3_scale(cam.v, -vp->viewport_height);
	vp->delta_u = ft_vec3_scale(vp->viewport_u, \
		(float)(1.0 / size_x));
	vp->delta_v = ft_vec3_scale(vp->viewport_v, \
		(float)(1.0 / size_y));
	vp->viewport_upper_left = ft_vec3_sub(ft_vec3_sub(ft_vec3_sub(\
		cam.look_from, ft_vec3_scale(cam.w, vp->focal_length)), \
		ft_vec3_scale(vp->viewport_u, 0.5)), \
		ft_vec3_scale(vp->viewport_v, 0.5));
	vp->pixel00_pos = ft_vec3_add(vp->viewport_upper_left, ft_vec3_scale(\
		ft_vec3_add(vp->delta_u, vp->delta_v), 0.5));
}
