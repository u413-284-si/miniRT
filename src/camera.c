/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/12/24 18:19:44 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "camera.h"

void	ft_initiate_camera(t_cam *cam)
{
	cam->vup = (t_vec3){0.0, 1.0, 0.0};
	cam->camera_centre = cam->look_from;
	cam->look_at = ft_vec3_add(cam->camera_centre, cam->camera_direction);
	cam->w = ft_vec3_norm(ft_vec3_sub(cam->look_from, cam->look_at));
	if (cam->camera_direction.y == 1)
		cam->u = (t_vec3){1, 0, 0};
	else if (cam->camera_direction.y == -1)
		cam->u = (t_vec3){-1, 0, 0};
	else
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
