/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:39:35 by u413q             #+#    #+#             */
/*   Updated: 2024/01/05 01:50:59 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager_bonus.h"

bool	ft_hit_sphere(t_sphere sp, t_hitrecord *rec, t_interval ray_d)
{
	t_vec3		sp_centre_ray;
	t_equation	eq;
	float		closest_d;

	sp_centre_ray = ft_vec3_sub(rec->ray.origin, sp.centre);
	eq.a = ft_vec3_dot(rec->ray.direction, rec->ray.direction);
	eq.b = 2.0 * ft_vec3_dot(rec->ray.direction, sp_centre_ray);
	eq.c = ft_vec3_dot(sp_centre_ray, sp_centre_ray) - pow(sp.d / 2.0, 2);
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
	rec->point = ft_ray(rec->ray, closest_d);
	rec->normal = ft_vec3_norm(ft_vec3_scale(\
		ft_vec3_sub(rec->point, sp.centre), (1.0 / (sp.d / 2.0))));
	rec->colour = sp.colour;
	ft_get_sp_uvcoords(rec, sp);
	return (true);
}

void	ft_get_sp_uvcoords(t_hitrecord *rec, t_sphere sp)
{
	t_vec3	north_pole;
	t_vec3	equator;
	float	phi;
	float	theta;

	north_pole = ft_vec3_add(sp.centre, ft_vec3_scale((t_vec3){0, 1, 0}, sp.d / 2.0));
	equator = ft_vec3_add(sp.centre, ft_vec3_scale((t_vec3){1, 0, 0}, sp.d / 2.0));
	phi = acos(ft_vec3_dot(ft_vec3_scale(rec->normal, -1), north_pole));
	theta = acos(ft_vec3_dot(rec->normal, equator) / sin(phi)) / (2 * M_PI);
	if (ft_vec3_dot(ft_vec3_cross(north_pole, equator), rec->normal) > 0)
		rec->u = theta;
	else
		rec->u = 1 - theta;
	rec->u = ft_set_tiling(rec->u, 0.1);
	rec->v = phi / M_PI;
	rec->v = ft_set_tiling(rec->v, 0.1);
}
