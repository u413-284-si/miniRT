/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_camera_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:41:38 by u413q             #+#    #+#             */
/*   Updated: 2023/11/19 21:59:02 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_bonus.h"

t_ray	ft_create_sample_ray(int i, int j, t_viewport vp, t_cam cam)
{
	t_vec3	pixel_centre;
	t_vec3	pixel_sample;
	t_ray	ray;

	pixel_centre = ft_vec3_add(ft_vec3_add(vp.pixel00_pos, \
		ft_vec3_scale(vp.delta_u, i)), ft_vec3_scale(vp.delta_v, j));
	pixel_sample = ft_vec3_add(pixel_centre, ft_pixel_sample(vp));
	ray.origin = cam.camera_centre;
	ray.direction = ft_vec3_sub(pixel_sample, ray.origin);
	ray.d = 1.0;
	return (ray);
}

t_vec3	ft_pixel_sample(t_viewport vp)
{
	float	px;
	float	py;

	px = -0.5 + ft_random_float();
	py = -0.5 + ft_random_float();
	return (ft_vec3_add(ft_vec3_scale(vp.delta_u, px), \
		ft_vec3_scale(vp.delta_v, py)));
}
