/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:53:34 by u413q             #+#    #+#             */
/*   Updated: 2023/11/14 16:51:37 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

t_vec3	ft_cylinder_normal(t_hitrecord rec, t_ray ray, t_cylinder cy)
{
	t_vec3	hit;
	t_vec3	normal;

	hit = ft_ray(ray, rec.d);
	if (ft_vec3_equal(rec.axis_hit, cy.cap1))
		normal = ft_vec3_scale(cy.axis, -1);
	else if (ft_vec3_equal(rec.axis_hit, cy.cap2))
		normal = ft_vec3_scale(cy.axis, 1);
	else
		normal = ft_vec3_sub(hit, rec.axis_hit);
	return (normal);
}

bool	ft_check_wall(t_cylinder cy, t_ray ray, float d, t_hitrecord *rec)
{
	t_vec3	hit;
	t_vec3	cap1_ray;
	t_vec3	axis_hit;
	float	m;
	float	len;

	hit = ft_ray(ray, d);
	cap1_ray = ft_vec3_sub(ray.origin, cy.cap1);
	m = ft_vec3_dot(ray.direction, cy.axis) * d + \
		ft_vec3_dot(cap1_ray, cy.axis);
	axis_hit = ft_vec3_add(cy.cap1, ft_vec3_scale(cy.axis, m));
	len = ft_vec3_abs(ft_vec3_sub(hit, axis_hit));
	m -= EPSILON;
	len -= EPSILON;
	if (m >= 0 && m <= cy.h && len <= (cy.d / 2.0) && d > EPSILON)
	{
		rec->axis_hit = axis_hit;
		return (true);
	}
	return (false);
}

bool	ft_check_cap(t_cylinder cy, t_ray ray, t_vec3 cap, \
	float d)
{
	t_vec3	hit;
	float	len;

	hit = ft_ray(ray, d);
	len = ft_vec3_abs(ft_vec3_sub(hit, cap));
	len += EPSILON;
	if (len <= (cy.d / 2.0) && d > EPSILON)
		return (true);
	return (false);
}

bool	ft_visible(t_equation eq, t_interval ray_d, float d3, \
	float d4)
{
	if (!ft_surrounds(eq.d1, ray_d))
		if (!ft_surrounds(eq.d2, ray_d))
			if (!ft_surrounds(d3, ray_d))
				if (!ft_surrounds(d4, ray_d))
					return (false);
	return (true);
}
