/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cone_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:42:46 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/09 11:02:26 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager_bonus.h"

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
		rec->wall_hit = true;
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
		rec->axis_hit = co.base;
		rec->wall_hit = false;
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

	if (ft_vec3_equal(rec.axis_hit, co.base))
		normal = co.axis;
	else if (ft_vec3_equal(rec.axis_hit, co.apex))
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

bool	ft_co_visible(t_interval ray_d, float potential_hits[3])
{
	if (!ft_surrounds(potential_hits[0], ray_d))
		if (!ft_surrounds(potential_hits[1], ray_d))
			if (!ft_surrounds(potential_hits[2], ray_d))
				return (false);
	return (true);
}

void	ft_get_co_uvcoords(t_hitrecord *rec, t_cone co)
{
	t_vec3	centre_hit;
	float	theta;
	float	rotation;

	centre_hit = ft_vec3_sub(rec->point, co.apex);
	if (!((co.axis.y + EPSILON >= 1.0) && (co.axis.y - EPSILON <= 1.0)))
	{
		rotation = acos(co.axis.y);
		centre_hit = ft_quaternion_rot(centre_hit,
				ft_vec3_norm(ft_vec3_cross((t_vec3){0, 1, 0}, \
				co.axis)), -rotation);
	}
	theta = atan2(centre_hit.x / co.r, centre_hit.z / co.r);
	rec->u = 1.0 - (theta / (2.0 * M_PI) + 0.5);
	rec->v = (0.5 + centre_hit.y / co.h);
	rec->u *= CHECKER_SCALE;
	rec->v *= CHECKER_SCALE;
}
