/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:05:20 by u413q             #+#    #+#             */
/*   Updated: 2023/11/03 13:22:02 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "lighting.h"

t_vec3	ft_ray(t_ray ray, float d)
{
	return (ft_vec3_add(ray.origin, ft_vec3_scale(ray.direction, d)));
}

t_colour	ft_ray_colour(t_ray ray, t_entities scene)
{
	// Spheres
	t_colour	ray_colour;
	t_hitrecord	rec;
	t_interval	ray_d;

	ray_d.min = 0;
	ray_d.max = INFINITY;

	if (ft_hit_scene(scene, ray, &rec, ray_d))
	{
		ft_enlighten(&ray_colour, rec, scene);
		return (ray_colour);
	}
/* 	{
		sphere_colour.r = 0.5 * (rec.normal.x + 1.0);
		sphere_colour.g = 0.5 * (rec.normal.y + 1.0);
		sphere_colour.b = 0.5 * (rec.normal.z + 1.0);
		return (sphere_colour);
	} */

	// Background
	t_vec3		unit_direction;
	float		a;
	t_colour	white;
	t_colour	blue;
	white.r = 1.0;
	white.g = 1.0;
	white.b = 1.0;
	blue.r = 0.5;
	blue.g = 0.7;
	blue.b = 1.0;

	unit_direction = ft_vec3_norm(ray.direction);
	a = 0.5 * (unit_direction.y + 1.0);
	ray_colour.r = (1.0 - a) * white.r + a * blue.r;
	ray_colour.g = (1.0 - a) * white.g + a * blue.g;
	ray_colour.b = (1.0 - a) * white.b + a * blue.b;
	return (ray_colour);
}
