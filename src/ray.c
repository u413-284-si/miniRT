/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:05:20 by u413q             #+#    #+#             */
/*   Updated: 2023/10/28 18:15:51 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_vec3	ft_ray(t_ray ray, float d)
{
	return (ft_vec3_add(ray.origin, ft_vec3_scale(ray.direction, d)));
}

t_colour	ft_ray_colour(t_ray ray)
{
	t_colour	ray_colour;
	t_colour	white;
	t_colour	blue;
	t_colour	sphere_colour;
	t_vec3		unit_direction;
	float		a;
	t_vec3		sp_centre;
	float		r;
	float		d;
	t_vec3		n;

	white.r = 1.0;
	white.g = 1.0;
	white.b = 1.0;
	blue.r = 0.5;
	blue.g = 0.7;
	blue.b = 1.0;
	sp_centre.x = 0.0;
	sp_centre.y = 0.0;
	sp_centre.z = -1.0;
	r = 0.5;
	d = ft_hit_sphere(sp_centre, r, ray);
	if (d > 0.0)
	{
		n = ft_vec3_norm(ft_vec3_sub(ft_ray(ray, d), sp_centre));
		sphere_colour.r = 0.5 * (n.x + 1.0);
		sphere_colour.g = 0.5 * (n.y + 1.0);
		sphere_colour.b = 0.5 * (n.z + 1.0);
		return (sphere_colour);
	}
	unit_direction = ft_vec3_norm(ray.direction);
	a = 0.5 * (unit_direction.y + 1.0);
	ray_colour.r = (1.0 - a) * white.r + a * blue.r;
	ray_colour.g = (1.0 - a) * white.g + a * blue.g;
	ray_colour.b = (1.0 - a) * white.b + a * blue.b;
	return (ray_colour);
}
