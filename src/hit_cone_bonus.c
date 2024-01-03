/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:33:09 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/04 00:55:31 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager_bonus.h"

bool	ft_hit_cone(t_cone co, t_hitrecord *rec, t_interval ray_d)
{
	t_hitrecord	tmp;
	float		potential_hits[3];

	ft_init_hitrecord(&tmp);
	tmp.ray = rec->ray;
	potential_hits[0] = 0;
	potential_hits[1] = 0;
	potential_hits[2] = 0;
	if (!ft_co_calc_pot_hits(co, rec->ray, potential_hits))
		return (false);
	if (!ft_co_visible(ray_d, potential_hits))
		return (false);
	ft_co_identify_hits(co, &tmp, potential_hits);
	if (tmp.d >= EPSILON && tmp.d < rec->d)
	{
		rec->d = tmp.d;
		rec->point = ft_ray(rec->ray, rec->d);
		rec->u = tmp.u;
		rec->v = tmp.v;
		rec->normal = ft_vec3_norm(ft_co_normal(*rec, co));
		rec->colour = co.colour;
		return (true);
	}
	return (false);
}

bool	ft_co_calc_pot_hits(t_cone co, t_ray ray, float potential_hits[3])
{
	t_vec3		ray_apex;
	t_equation	eq;

	ray_apex = ft_vec3_sub(ray.origin, co.apex);
	eq.a = pow(ft_vec3_dot(ray.direction, co.axis), 2) \
		- pow(cos(co.angle), 2);
	eq.b = 2.0 * (ft_vec3_dot(ray.direction, co.axis) * \
		ft_vec3_dot(ray_apex, co.axis) - ft_vec3_dot(ray.direction, \
		ray_apex) * pow(cos(co.angle), 2));
	eq.c = pow(ft_vec3_dot(ray_apex, co.axis), 2) - ft_vec3_dot(ray_apex, \
		ray_apex) * pow(cos(co.angle), 2);
	if (!ft_solve(&eq))
		return (false);
	potential_hits[0] = eq.d1;
	potential_hits[1] = eq.d2;
	potential_hits[2] = ft_co_cap_hit(co, ray);
	return (true);
}

float	ft_co_cap_hit(t_cone co, t_ray ray)
{
	t_plane		pl;
	t_hitrecord	rec;
	t_interval	ray_d;
	float		d;

	pl.point = co.base;
	pl.normal = co.axis;
	pl.colour = co.colour;
	ft_init_hitrecord(&rec);
	rec.ray = ray;
	ft_init_interval(&ray_d);
	if (ft_hit_plane(pl, &rec, ray_d))
		d = rec.d;
	else
		d = -1;
	return (d);
}

void	ft_co_identify_hits(t_cone co, t_hitrecord *rec, \
	float potential_hits[3])
{
	if (ft_co_check_wall(co, potential_hits[0], rec))
		rec->d = potential_hits[0];
	if (ft_co_check_wall(co, potential_hits[1], rec))
		rec->d = potential_hits[1];
	if (ft_co_check_cap(co, potential_hits[2], rec))
		rec->d = potential_hits[2];
	if (rec->d == INFINITY)
		rec->d = 0;
}
