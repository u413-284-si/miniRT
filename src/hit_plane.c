/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:47:49 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/14 17:20:07 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

/* bool	ft_hit_scene_pl(t_entities scene, t_ray ray, t_hitrecord *rec, \
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
} */

bool	ft_hit_plane(t_plane pl, t_ray ray, t_hitrecord *rec, t_interval ray_d)
{
	t_vec3		pl_point_ray;
	t_equation	eq;

	eq.b = ft_vec3_dot(ray.direction, pl.normal);
	if (eq.b < EPSILON)
		return (false);
	pl_point_ray = ft_vec3_sub(ray.origin, pl.point);
	eq.a = 0.0;
	eq.c = ft_vec3_dot(pl_point_ray, pl.normal);
	if (ft_solve(&eq) < 0)
		return (false);
	if (!ft_surrounds(eq.d1, ray_d) || eq.d1 < EPSILON)
		return (false);
	rec->d = eq.d1;
	rec->point = ft_ray(ray, eq.d1);
	rec->normal = pl.normal;
	rec->colour = pl.colour;
	return (true);
}
