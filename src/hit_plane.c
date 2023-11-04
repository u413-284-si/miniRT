/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:47:49 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/04 20:44:14 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

bool	ft_hit_scene_pl(t_entities scene, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d)
{
	int		i;
	bool	hit;

	hit = false;
	i = -1;
	while (++i < scene.pl_count)
	{
		if (ft_hit_plane(scene.pl[i], ray, rec, ray_d))
		{
			hit = true;
			ray_d.max = rec->d;
		}
	}
	return (hit);
}

bool	ft_hit_plane(t_plane pl, t_ray ray, t_hitrecord *rec, t_interval ray_d)
{
	t_vec3	pl_point_ray;
	float	dot_product_ray_normal;
	float	d;

	dot_product_ray_normal = ft_vec3_dot(ray.direction, pl.normal);
	if (dot_product_ray_normal > 0.000001)
	{
		pl_point_ray = ft_vec3_sub(pl.point, ray.origin);
		d = ft_vec3_dot(pl_point_ray, pl.normal) / dot_product_ray_normal;
		if (!ft_surrounds(d, ray_d))
			return (false);
		rec->d = d;
		rec->point = ft_ray(ray, d);
		rec->normal = pl.normal;
		rec->colour.r = pl.colour.r;
		rec->colour.b = pl.colour.b;
		rec->colour.g = pl.colour.g;
		return (true);
	}
	return (false);
}
