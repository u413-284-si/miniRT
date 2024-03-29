/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:33:09 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/26 13:58:09 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager_bonus.h"

bool	ft_hit_cone(t_cone co, t_hitrecord *rec, t_interval ray_d)
{
	t_hitrecord	tmp;
	float		potential_hits[3];

	potential_hits[0] = 0;
	potential_hits[1] = 0;
	potential_hits[2] = 0;
	ft_init_hitrecord(&tmp);
	tmp.ray = rec->ray;
	if (!ft_co_calc_pot_hits(co, rec->ray, potential_hits))
		return (false);
	if (!ft_co_visible(ray_d, potential_hits))
		return (false);
	ft_co_identify_hits(co, &tmp, potential_hits);
	if (tmp.d >= EPSILON && tmp.d < rec->d)
	{
		ft_co_set_hitrecord(co, rec, tmp);
		return (true);
	}
	return (false);
}

bool	ft_co_calc_pot_hits(t_cone co, t_ray ray, float potential_hits[3])
{
	t_vec3		ray_apex;
	t_equation	eq;
	float		dot_product_ray_axis;
	float		dot_product_apex_axis;
	float		cos_2_angle;

	eq = (t_equation){0};
	ray_apex = ft_vec3_sub(ray.origin, co.apex);
	dot_product_ray_axis = ft_vec3_dot(ray.direction, co.axis);
	dot_product_apex_axis = ft_vec3_dot(ray_apex, co.axis);
	cos_2_angle = cos(co.angle) * cos(co.angle);
	eq.a = dot_product_ray_axis * dot_product_ray_axis - cos_2_angle;
	eq.b = 2.0 * (dot_product_ray_axis * dot_product_apex_axis - \
		ft_vec3_dot(ray.direction, ray_apex) * cos_2_angle);
	eq.c = dot_product_apex_axis * dot_product_apex_axis \
		- ft_vec3_dot(ray_apex, ray_apex) * cos_2_angle;
	if (!ft_solve(&eq))
		return (false);
	potential_hits[0] = eq.d1;
	potential_hits[1] = eq.d2;
	potential_hits[2] = ft_co_cap_hit(co, ray);
	return (true);
}

float	ft_co_cap_hit(t_cone co, t_ray ray)
{
	const t_plane	pl = (t_plane){.point = co.base, .normal = co.axis, \
		.colour = co.colour};
	t_hitrecord		rec;
	t_interval		ray_d;

	ft_init_hitrecord(&rec);
	rec.ray = ray;
	ray_d = (t_interval){.max = INFINITY, .min = 0};
	if (ft_hit_plane(pl, &rec, ray_d))
		return (rec.d);
	else
		return (-1);
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

void	ft_co_set_hitrecord(t_cone co, t_hitrecord *rec, t_hitrecord tmp)
{
	rec->d = tmp.d;
	rec->axis_hit = tmp.axis_hit;
	rec->point = ft_scale_ray(rec->ray, rec->d);
	rec->normal = ft_co_normal(*rec, co);
	if (tmp.wall_hit)
		ft_get_co_uvcoords(rec, co);
	else
	{
		ft_get_pl_uvcoords(rec);
		rec->u *= 4;
		rec->v *= 4;
	}
	rec->colour = co.colour;
}
