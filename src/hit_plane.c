/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:47:49 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/03 14:18:05 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

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
