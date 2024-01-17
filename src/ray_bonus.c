/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:05:20 by u413q             #+#    #+#             */
/*   Updated: 2024/01/17 16:27:21 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting_bonus.h"

t_vec3	ft_scale_ray(t_ray ray, float d)
{
	return (ft_vec3_add(ray.origin, ft_vec3_scale(ray.direction, d)));
}

t_colour	ft_ray_colour(t_ray ray, t_entities scene, t_cam cam)
{
	t_colour	ray_colour;
	t_hitrecord	rec;
	t_hittable	cur;
	t_interval	ray_d;
	int			i;

	ft_init_colour(&ray_colour);
	ft_init_hitrecord(&rec);
	rec.ray = ray;
	ft_init_interval(&ray_d);
	i = -1;
	while (++i < scene.total)
	{
		cur = scene.obj[i];
		if (ft_hit_hittable(cur, &rec, ray_d))
			if (rec.d < ray_d.max)
				ft_set_hitrecord_features(&rec, cur, &ray_d);
	}
	if (ray_d.max < INFINITY)
	{
		ft_enlighten(&ray_colour, rec, scene, cam);
		return (ray_colour);
	}
	return (ft_background_colour(ray));
}

t_colour	ft_background_colour(t_ray ray)
{
	t_vec3		unit_direction;
	float		a;
	t_colour	white;
	t_colour	blue;
	t_colour	ray_colour;

	white.r = 1.0;
	white.g = 1.0;
	white.b = 1.0;
	blue.r = 0.5;
	blue.g = 0.7;
	blue.b = 1.0;
	unit_direction = ray.direction;
	a = 0.5 * (unit_direction.y + 1.0);
	ray_colour.r = (1.0 - a) * white.r + a * blue.r;
	ray_colour.g = (1.0 - a) * white.g + a * blue.g;
	ray_colour.b = (1.0 - a) * white.b + a * blue.b;
	return (ray_colour);
}

t_ray	ft_create_sample_ray(t_vec3 pixel_centre, t_pixel_grid pixels, \
	t_cam cam)
{
	t_vec3	pixel_sample;
	t_ray	ray;

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
