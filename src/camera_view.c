/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:48:56 by u413q             #+#    #+#             */
/*   Updated: 2023/12/16 11:24:49 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	ft_cam_calc_inv_projection(t_cam *cam)
{
	t_mat4	projection;

	projection = ft_mat4_perspective(ft_degree_to_radian(cam->hfov), cam->screen.aspect_ratio, 0.1, 100.0);
	cam->inv_projection = ft_mat4_inverse(projection);
}

void	ft_cam_calc_inv_view(t_cam *cam)
{
	t_mat4	view;

	view = ft_mat4_cam_look_at(cam->look_from, ft_vec3_add(cam->look_from, cam->look_at), (t_vec3){0, 1, 0});
	cam->inv_view = ft_mat4_inverse(view);
}

void	ft_cam_calc_ray_dir(t_cam *cam, float y_ndc, float x_ndc, int index)
{
	t_vec4	projected;
	t_vec3	perspective_div;
	t_vec4	viewed;

	projected = ft_mat4_mult_vec4(cam->inv_projection,
			(t_vec4){x_ndc, y_ndc, 1, 1});

	perspective_div = ft_vec3_norm(ft_vec3_scale((t_vec3){projected.x, projected.y, projected.z}, 1 / projected.w));

	viewed = ft_mat4_mult_vec4(cam->inv_view,
			(t_vec4){perspective_div.x, perspective_div.y, perspective_div.z, 0});

	cam->cached_rays[index] = (t_vec3){viewed.x, viewed.y, viewed.z};

}

void	ft_cam_calc_all_ray_dirs(t_cam *cam)
{
	int		y;
	int		x;
	float	x_ndc;
	float	y_ndc;

	y = -1;
	while (++y < cam->screen.height)
	{
		x = -1;
		while (++x < cam->screen.width)
		{
			x_ndc = (float)x / (float)cam->screen.width;
			x_ndc = x_ndc * 2.0 - 1.0;
			y_ndc = (float)y / (float)cam->screen.height;
			y_ndc = y_ndc * 2.0 - 1.0;
			ft_cam_calc_ray_dir(cam, y_ndc, x_ndc, y * cam->screen.width + x);
		}
	}
}
