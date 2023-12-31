/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_bonus_.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:33:09 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/31 13:14:15 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager_bonus.h"

bool	ft_hit_cone(t_cone co, t_hitrecord *rec, t_interval ray_d)
{
	t_vec3		ray_apex;
	t_equation	eq;
	float		d3;
	t_hitrecord	tmp;

	(void)ray_d;
	ft_init_hitrecord(&tmp);
	tmp.ray = rec->ray;
	ray_apex = ft_vec3_sub(rec->ray.origin, co.apex);
	eq.a = pow(ft_vec3_dot(rec->ray.direction, co.axis), 2) \
		- pow(cos(co.angle), 2);
	eq.b = 2.0 * (ft_vec3_dot(rec->ray.direction, co.axis) * \
		ft_vec3_dot(ray_apex, co.axis) - ft_vec3_dot(rec->ray.direction, \
		ray_apex) * pow(cos(co.angle), 2));
	eq.c = pow(ft_vec3_dot(ray_apex, co.axis), 2) - ft_vec3_dot(ray_apex, \
		ray_apex) * pow(cos(co.angle), 2);
	if (!ft_solve(&eq))
		return (false);
	d3 = ft_co_cap_hit(co, tmp.ray);
	ft_co_identify_hits(co, &tmp, eq, d3);
	if (tmp.d < EPSILON)
		return (false);
	if (tmp.d < rec->d)
	{
		rec->d = tmp.d;
		rec->point = ft_ray(rec->ray, rec->d);
		rec->normal = ft_vec3_norm(ft_co_normal(*rec, co));
		rec->colour = co.colour;
		return (true);
	}
	return (false);
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

void	ft_co_identify_hits(t_cone co, t_hitrecord *rec, t_equation eq, float d3)
{
	if (ft_co_check_wall(co, eq.d1, rec))
		rec->d = eq.d1;
	if (ft_co_check_wall(co, eq.d2, rec))
		rec->d = eq.d2;
	if (ft_co_check_cap(co, d3, rec))
		rec->d = d3;
	if (rec->d == INFINITY)
		rec->d = 0;
}

bool	ft_co_check_wall(t_cone co, float d, t_hitrecord *rec)
{
	t_vec3	ray_apex;
	t_vec3	tmp;
	t_vec3	hit;
	double	angle;
	double	m;

	hit = ft_ray(rec->ray, d);
	ray_apex = ft_vec3_sub(rec->ray.origin, co.apex);
	m = ft_vec3_dot(rec->ray.direction, co.axis) * d + ft_vec3_dot(ray_apex,
			co.axis);
	tmp = ft_vec3_sub(hit, co.apex);
	angle = acos(ft_vec3_dot(co.axis, tmp) / \
		(ft_vec3_abs(co.axis) * ft_vec3_abs(tmp))) - 0.001;
	if (m >= 0 && m <= co.h && angle - EPSILON <= co.angle && d > EPSILON
		&& d < rec->d)
	{
		rec->axis_hit = ft_vec3_add(co.apex, ft_vec3_scale(co.axis, m));
		return (true);
	}
	return (false);
}

bool	ft_co_check_cap(t_cone co, float d, t_hitrecord *rec)
{
	double	len;
	t_vec3	hit;

	hit = ft_ray(rec->ray, d);
	len = ft_vec3_abs(ft_vec3_sub(hit, co.base));
	len -= EPSILON;
	if (len >= 0 && len <= co.r && d > EPSILON && d < rec->d)
	{
		rec->axis_hit = co.axis;
		return (true);
	}
	return (false);
}

t_vec3	ft_co_normal(t_hitrecord rec, t_cone co)
{
	t_vec3	normal;
	t_vec3	tmp;
	double	adj;
	double	hip;

	if (ft_vec3_equal(rec.axis_hit, co.axis))
		normal = co.axis;
	else if (ft_vec3_equal(rec.point, co.apex))
		normal = ft_vec3_scale(co.axis, -1);
	else
	{
		adj = ft_vec3_abs(ft_vec3_sub(rec.point, co.apex));
		hip = adj / cos(co.angle);
		tmp = ft_vec3_add(co.apex, ft_vec3_scale(co.axis, hip));
		normal = ft_vec3_sub(rec.point, tmp);
	}
	return (normal);
}
