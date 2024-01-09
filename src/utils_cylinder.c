/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:53:34 by u413q             #+#    #+#             */
/*   Updated: 2024/01/09 11:32:22 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

t_vec3	ft_cy_normal(t_hitrecord rec, t_cylinder cy)
{
	t_vec3	hit;
	t_vec3	normal;

	hit = ft_ray(rec.ray, rec.d);
	if (ft_vec3_equal(rec.axis_hit, cy.cap1))
		normal = ft_vec3_scale(cy.axis, -1);
	else if (ft_vec3_equal(rec.axis_hit, cy.cap2))
		normal = cy.axis;
	else
		normal = ft_vec3_sub(hit, rec.axis_hit);
	return (normal);
}

bool	ft_cy_check_wall(t_cylinder cy, float d, t_hitrecord *rec)
{
	t_vec3	hit;
	t_vec3	cap1_ray;
	t_vec3	axis_hit;
	float	m;
	float	len;

	hit = ft_ray(rec->ray, d);
	cap1_ray = ft_vec3_sub(rec->ray.origin, cy.cap1);
	m = ft_vec3_dot(rec->ray.direction, cy.axis) * d + \
		ft_vec3_dot(cap1_ray, cy.axis);
	axis_hit = ft_vec3_add(cy.cap1, ft_vec3_scale(cy.axis, m));
	len = ft_vec3_abs(ft_vec3_sub(hit, axis_hit));
	m -= EPSILON;
	len -= EPSILON;
	if (m >= 0 && m <= cy.h && len <= (cy.d / 2.0) && d > EPSILON && d < rec->d)
	{
		rec->axis_hit = axis_hit;
		return (true);
	}
	return (false);
}

bool	ft_cy_check_cap(t_cylinder cy, t_vec3 cap, float d, t_hitrecord *rec)
{
	t_vec3	hit;
	float	len;

	hit = ft_ray(rec->ray, d);
	len = ft_vec3_abs(ft_vec3_sub(hit, cap));
	len += EPSILON;
	if (len <= (cy.d / 2.0) && d > EPSILON && d < rec->d)
	{
		rec->axis_hit = cap;
		return (true);
	}
	return (false);
}

bool	ft_cy_visible(t_interval ray_d, float potential_hits[4])
{
	if (!ft_surrounds(potential_hits[0], ray_d))
		if (!ft_surrounds(potential_hits[1], ray_d))
			if (!ft_surrounds(potential_hits[2], ray_d))
				if (!ft_surrounds(potential_hits[3], ray_d))
					return (false);
	return (true);
}
