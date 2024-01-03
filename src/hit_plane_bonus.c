/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:47:49 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/04 00:32:22 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager_bonus.h"

bool	ft_hit_plane(t_plane pl, t_hitrecord *rec, t_interval ray_d)
{
	t_vec3		pl_point_ray;
	t_equation	eq;

	eq.a = 0.0;
	eq.b = ft_vec3_dot(ft_vec3_norm(rec->ray.direction), pl.normal);
	if (fabs(eq.b) < EPSILON)
		return (false);
	pl_point_ray = ft_vec3_sub(rec->ray.origin, pl.point);
	eq.c = ft_vec3_dot(pl_point_ray, pl.normal);
	ft_solve(&eq);
	if (!ft_surrounds(eq.d1, ray_d) || eq.d1 < EPSILON)
		return (false);
	rec->d = eq.d1;
	if (eq.b > 0)
		rec->normal = ft_vec3_scale(pl.normal, -1);
	else
		rec->normal = pl.normal;
	rec->point = ft_ray(rec->ray, eq.d1);
	rec->colour = pl.colour;
	rec->u = rec->point.x;
	rec->v = rec->point.y;
	return (true);
}
