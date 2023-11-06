/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:39:35 by u413q             #+#    #+#             */
/*   Updated: 2023/11/06 15:24:22 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

/* bool	ft_hit_scene_sp(t_entities scene, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d)
{
	bool			hit;
	int				i;

	hit = false;
	i = -1;
	while (++i < scene.sp_count)
	{
		if (ft_hit_sphere(scene.obj[i].
		sp[i], ray, rec, ray_d))
		{
			hit = true;
			ray_d.max = rec->d;
		}
	}
	return (hit);
} */

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
	if (!ft_surrounds(d, ray_d))
	{
		d = (-b + sqrt(discriminant)) / (2.0 * a);
		if (!ft_surrounds(d, ray_d))
			return (false);
	}
	rec->d = d;
	rec->point = ft_ray(ray, d);
	rec->normal = ft_vec3_scale(ft_vec3_sub(rec->point, sp.centre), \
		(1.0 / sp.r));
	rec->colour.r = sp.colour.r;
	rec->colour.b = sp.colour.b;
	rec->colour.g = sp.colour.g;
	return (true);
}
