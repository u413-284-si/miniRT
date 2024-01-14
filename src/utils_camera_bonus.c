/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_camera_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 21:41:38 by u413q             #+#    #+#             */
/*   Updated: 2024/01/14 17:33:43 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"

t_ray	ft_create_sample_ray(int i, int j, t_pixel_grid pixels, t_cam cam)
{
	t_vec3	pixel_centre;
	t_vec3	pixel_sample;
	t_ray	ray;

	pixel_centre = ft_vec3_add(ft_vec3_add(pixels.pos00, \
		ft_vec3_scale(pixels.delta_u, i)), ft_vec3_scale(pixels.delta_v, j));
	pixel_sample = ft_vec3_add(pixel_centre, ft_pixel_sample(pixels));
	ray.origin = cam.centre;
	ray.direction = ft_vec3_norm(ft_vec3_sub(pixel_sample, ray.origin));
	ray.d = 1.0;
	return (ray);
}

t_vec3	ft_pixel_sample(t_pixel_grid pixels)
{
	float	px;
	float	py;

	px = -0.5 + ft_random_float();
	py = -0.5 + ft_random_float();
	return (ft_vec3_add(ft_vec3_scale(pixels.delta_u, px), \
		ft_vec3_scale(pixels.delta_v, py)));
}
