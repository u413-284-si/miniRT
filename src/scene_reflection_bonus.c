/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_reflection_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 23:15:28 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/17 16:33:45 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting_bonus.h"

t_colour	ft_reflective_light(t_light cur, t_hitrecord rec, \
	t_entities scene, t_cam cam)
{
	t_vec3		reflect_direction;
	t_ray		reflect_ray;
	t_interval	interval;
	t_colour	reflective_colour;

	reflective_colour = (t_colour){0};
	reflect_direction = ft_vec3_sub(rec.ray.direction, ft_vec3_scale(\
		rec.normal, 2 * ft_vec3_dot(rec.ray.direction, rec.normal)));
	reflect_ray.origin = rec.point;
	reflect_ray.direction = ft_vec3_norm(reflect_direction);
	reflect_ray.d = 1;
	interval.min = 0.001;
	interval.max = INFINITY;
	if (ft_get_closest_hit(scene, reflect_ray, interval, &rec) \
		&& rec.reflection_count < REFLECTION_MAX)
	{
		rec.reflection_count++;
		if (rec.reflectivity > 0.0)
			reflective_colour = ft_compute_colour(cur, rec, scene, cam);
		else
			reflective_colour = ft_diffuse_light(cur, rec);
	}
	return (reflective_colour);
}

bool	ft_get_closest_hit(t_entities scene, t_ray ray, t_interval ray_d, \
	t_hitrecord *closest)
{
	t_hittable	cur;
	int			i;
	bool		hit_found;

	ft_init_hitrecord(closest);
	(*closest).ray = ray;
	hit_found = false;
	i = -1;
	while (++i < scene.total)
	{
		cur = scene.obj[i];
		if (ft_hit_hittable(cur, closest, ray_d))
		{
			hit_found = true;
			if ((*closest).d < ray_d.max)
			{
				ray_d.max = (*closest).d;
				(*closest).reflectivity = cur.reflectivity;
				(*closest).shininess = cur.shininess;
			}
		}
	}
	return (hit_found);
}
