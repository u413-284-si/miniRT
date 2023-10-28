/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:05:20 by u413q             #+#    #+#             */
/*   Updated: 2023/10/28 17:43:20 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_vec3	ft_ray(t_vec3 origin, t_vec3 direction, float d)
{
	return (ft_vec3_add(origin, ft_vec3_scale(direction, d)));
}

t_colour	ft_ray_colour(t_ray ray)
{
	t_colour	ray_colour;
	t_colour	white;
	t_colour	blue;
	t_colour	red;
	t_vec3		unit_direction;
	float		a;
	t_vec3		sp_centre;
	float		r;

	white.r = 1.0;
	white.g = 1.0;
	white.b = 1.0;
	blue.r = 0.5;
	blue.g = 0.7;
	blue.b = 1.0;
	red.r = 1.0;
	red.g = 0.0;
	red.b = 0.0;
	sp_centre.x = 0.0;
	sp_centre.y = 0.0;
	sp_centre.z = -1.0;
	r = 0.5;
	if (ft_hit_sphere(sp_centre, r, ray))
		return (red);
	unit_direction = ft_vec3_norm(ray.direction);
	a = 0.5 * (unit_direction.y + 1.0);
	ray_colour.r = (1.0 - a) * white.r + a * blue.r;
	ray_colour.g = (1.0 - a) * white.g + a * blue.g;
	ray_colour.b = (1.0 - a) * white.b + a * blue.b;
	return (ray_colour);
}
