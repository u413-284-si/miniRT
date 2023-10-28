/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:08:13 by u413q             #+#    #+#             */
/*   Updated: 2023/10/28 20:08:29 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

bool	ft_hit_sphere(t_sphere sp, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d)
{
	t_vec3	sp_centre_ray;
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	d;

	sp_centre_ray = ft_vec3_sub(ray.origin, sp.centre);
	a = ft_vec3_dot(ray.direction, ray.direction);
	b = 2.0 * ft_vec3_dot(ray.direction, sp_centre_ray);
	c = ft_vec3_dot(sp_centre_ray, sp_centre_ray) - pow(sp.r, 2);
	discriminant = pow(b, 2) - 4.0 * a * c;
	if (discriminant < 0)
		return (false);
	d = (-b - sqrt(discriminant)) / (2.0 * a);
	if (d <= ray_d.min || d >= ray_d.max)
	{
		d = (-b + sqrt(discriminant)) / (2.0 * a);
		if (d <= ray_d.min || d >= ray_d.max)
			return (false);
	}
	rec->d = d;
	rec->point = ft_ray(ray, d);
	rec->normal = ft_vec3_scale(ft_vec3_sub(rec->point, sp.centre), \
		(1.0 / sp.r));
	return (true);
}
