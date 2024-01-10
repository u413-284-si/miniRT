/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:39:35 by u413q             #+#    #+#             */
/*   Updated: 2023/11/14 17:38:00 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

bool	ft_hit_sphere(t_sphere sp, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d)
{
	t_vec3		sp_centre_ray;
	t_equation	eq;
	float		closest_d;

	sp_centre_ray = ft_vec3_sub(ray.origin, sp.centre);
	eq.a = ft_vec3_dot(ray.direction, ray.direction);
	eq.b = 2.0 * ft_vec3_dot(ray.direction, sp_centre_ray);
	eq.c = ft_vec3_dot(sp_centre_ray, sp_centre_ray) - pow(sp.r, 2);
	if (ft_solve(&eq) < 0)
		return (false);
	closest_d = eq.d1;
	if (!ft_surrounds(closest_d, ray_d))
	{
		closest_d = eq.d2;
		if (!ft_surrounds(closest_d, ray_d))
			return (false);
	}
	rec->d = closest_d;
	rec->point = ft_ray(ray, closest_d);
	rec->normal = ft_vec3_scale(ft_vec3_sub(rec->point, sp.centre), \
		(1.0 / sp.r));
	rec->colour = sp.colour;
	return (true);
}
