/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:16:38 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/18 15:19:08 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

bool	ft_hit_cylinder(t_cylinder cy, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d)
{
	float		potential_hits[4];

	if (!ft_cy_calculate_pot_hits(cy, ray, ray_d, potential_hits))
		return (false);
	ft_cy_identify_hits(cy, ray, potential_hits, rec);
	if (rec->d < EPSILON)
		return (false);
	rec->point = ft_ray(ray, rec->d);
	rec->normal = ft_vec3_norm(ft_cy_normal(*rec, ray, cy));
	rec->colour = cy.colour;
	return (true);
}

bool	ft_cy_calculate_pot_hits(t_cylinder cy, t_ray ray, t_interval ray_d, \
	float potential_hits[4])
{
	t_equation	eq;
	t_vec3		cap1_ray;
	float		cap_hit1;
	float		cap_hit2;

	cap1_ray = ft_vec3_sub(ray.origin, cy.cap1);
	eq.a = ft_vec3_dot(ray.direction, ray.direction) - \
		pow(ft_vec3_dot(ray.direction, cy.axis), 2);
	eq.b = 2.0 * (ft_vec3_dot(ray.direction, cap1_ray) - \
		(ft_vec3_dot(ray.direction, cy.axis) * ft_vec3_dot(cap1_ray, cy.axis)));
	eq.c = ft_vec3_dot(cap1_ray, cap1_ray) - \
		pow(ft_vec3_dot(cap1_ray, cy.axis), 2) - pow(cy.d / 2.0, 2);
	if (ft_solve(&eq) < 0)
		return (false);
	ft_cy_hit_cap(cy, ray, cy.cap1, &cap_hit1);
	ft_cy_hit_cap(cy, ray, cy.cap2, &cap_hit2);
	if (!ft_cy_visible(eq, ray_d, cap_hit1, cap_hit2))
		return (false);
	potential_hits[0] = eq.d1;
	potential_hits[1] = eq.d2;
	potential_hits[2] = cap_hit1;
	potential_hits[3] = cap_hit2;
	return (true);
}

void	ft_cy_hit_cap(t_cylinder cy, t_ray ray, t_vec3 cap, float *d)
{
	t_plane		pl;
	t_hitrecord	rec;
	t_interval	ray_d;

	pl.point = cap;
	pl.normal = cy.axis;
	pl.colour = cy.colour;
	ray_d.min = 0;
	ray_d.max = INFINITY;
	if (ft_hit_plane(pl, ray, &rec, ray_d))
		*d = rec.d;
	else
		*d = -1;
}

void	ft_cy_identify_hits(t_cylinder cy, t_ray ray, float potential_hits[4], \
	t_hitrecord *rec)
{
	if (ft_cy_check_wall(cy, ray, potential_hits[0], rec) \
		&& potential_hits[0] < rec->d)
		rec->d = potential_hits[0];
	if (ft_cy_check_wall(cy, ray, potential_hits[1], rec) \
		&& potential_hits[1] < rec->d)
		rec->d = potential_hits[1];
	if (ft_cy_check_cap(cy, ray, cy.cap1, potential_hits[2]) \
		&& potential_hits[2] < rec->d)
	{
		rec->axis_hit = cy.cap1;
		rec->d = potential_hits[2];
	}
	if (ft_cy_check_cap(cy, ray, cy.cap2, potential_hits[3]) \
		&& potential_hits[3] < rec->d)
	{
		rec->axis_hit = cy.cap2;
		rec->d = potential_hits[3];
	}
}
