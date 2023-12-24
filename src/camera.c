/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:48:56 by u413q             #+#    #+#             */
/*   Updated: 2023/12/24 18:09:42 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	ft_initiate_camera(t_cam *cam, int size_x, int size_y)
{
	ft_cam_calc_base_vector(cam);
	cam->focal_length = 10.0;
	ft_cam_calc_viewport_dimensions(cam, size_x, size_y);
	ft_cam_calc_viewport_pixels(cam, size_x, size_y);
}

void	ft_cam_calc_base_vector(t_cam *cam)
{
	const t_vec3	world_up = {0.0, 1.0, 0.0};

	cam->w = ft_vec3_norm(ft_vec3_sub(cam->position, cam->direction));
	cam->u = ft_vec3_cross(world_up, cam->w);
	cam->v = ft_vec3_cross(cam->w, cam->u);
}

void	ft_cam_calc_viewport_dimensions(t_cam *cam, int size_x, int size_y)
{
	cam->vp.width = 2 * tan(cam->hfov / 2) * cam->focal_length;
	cam->vp.height = cam->vp.width / size_x * size_y;
}

void	ft_cam_calc_viewport_pixels(t_cam *cam, int size_x, int size_y)
{
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	viewport_upper_left;

	viewport_u = ft_vec3_scale(cam->u, cam->vp.width);
	viewport_v = ft_vec3_scale(cam->v, -cam->vp.height);
	cam->vp.delta_u = ft_vec3_scale(viewport_u, (1.0 / size_x));
	cam->vp.delta_v = ft_vec3_scale(viewport_v, (1.0 / size_y));
	viewport_upper_left = ft_vec3_sub(ft_vec3_sub(ft_vec3_sub(\
		cam->position, ft_vec3_scale(cam->w, cam->focal_length)), \
		ft_vec3_scale(viewport_u, 0.5)), \
		ft_vec3_scale(viewport_v, 0.5));
	cam->vp.pixel00_pos = ft_vec3_add(viewport_upper_left, ft_vec3_scale(\
		ft_vec3_add(cam->vp.delta_u, cam->vp.delta_v), 0.5));
}
