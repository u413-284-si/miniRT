/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_init_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:48:56 by u413q             #+#    #+#             */
/*   Updated: 2023/12/16 11:40:30 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	ft_initiate_image(t_image *image)
{
	image->width = WIN_X;
	image->height = WIN_Y;
	image->aspect_ratio = image->width / image->height;

}

t_err	ft_initiate_camera(t_cam *cam)
{
	int	sum_pixel;

	ft_initiate_image(&cam->screen);
	sum_pixel = cam->screen.height * cam->screen.width;
	if (ft_err_malloc((void **)&cam->cached_rays,
			sizeof (*cam->cached_rays) * sum_pixel))
		return (ERROR);
	cam->pitch = ft_radian_to_degree(asinf(cam->look_at.y));
	cam->yaw = ft_radian_to_degree(atan2f(cam->look_at.z, cam->look_at.x));
	cam->near = NEAR_CLIP;
	cam->far = FAR_CLIP;
	ft_cam_calc_inv_view(cam);
	ft_cam_calc_inv_projection(cam);
	ft_cam_calc_all_ray_dirs(cam);
	return (SUCCESS);
}

/*
void	ft_initiate_viewport(t_viewport *vp, t_cam cam, t_image image)
{
	vp->focal_length = ft_vec3_abs(ft_vec3_sub(cam.look_from, cam.look_at));
	cam.hfov = ft_degree_to_radian(cam.hfov);
	vp->viewport_width = 2 * tan(cam.hfov / 2) * vp->focal_length;
	vp->viewport_height = vp->viewport_width / image.width \
		* image.height;
	vp->viewport_u = ft_vec3_scale(cam.u, vp->viewport_width);
	vp->viewport_v = ft_vec3_scale(cam.v, -vp->viewport_height);
	vp->delta_u = ft_vec3_scale(vp->viewport_u, \
		(float)(1.0 / image.width));
	vp->delta_v = ft_vec3_scale(vp->viewport_v, \
		(float)(1.0 / image.height));
	vp->viewport_upper_left = ft_vec3_sub(ft_vec3_sub(ft_vec3_sub(\
		cam.camera_centre, ft_vec3_scale(cam.w, vp->focal_length)), \
		ft_vec3_scale(vp->viewport_u, 0.5)), \
		ft_vec3_scale(vp->viewport_v, 0.5));
	vp->pixel00_pos = ft_vec3_add(vp->viewport_upper_left, ft_vec3_scale(\
		ft_vec3_add(vp->delta_u, vp->delta_v), 0.5));
}
*/

void	ft_cam_update_angle(t_cam *cam)
{
	t_vec3	direction;
	float	yaw_rad;
	float	pitch_rad;

	yaw_rad = ft_degree_to_radian(cam->yaw);
	pitch_rad = ft_degree_to_radian(cam->pitch);
	direction.x = cos(yaw_rad) * cos(pitch_rad);
	direction.y = sin(pitch_rad);
	direction.z = sin(yaw_rad) * cos(pitch_rad);
	cam->look_at = ft_vec3_norm(direction);
}

void	ft_cam_update_view(t_cam *cam, bool update_angle)
{
	if (update_angle)
		ft_cam_update_angle(cam);
	ft_cam_calc_inv_view(cam);
	ft_cam_calc_all_ray_dirs(cam);
}
