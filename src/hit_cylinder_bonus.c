/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:16:38 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/25 13:52:54 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager_bonus.h"

bool	ft_hit_cylinder(t_cylinder cy, t_hitrecord *rec, t_interval ray_d)
{
	float		potential_hits[4];
	t_hitrecord	tmp;

	potential_hits[0] = 0;
	potential_hits[1] = 0;
	potential_hits[2] = 0;
	potential_hits[3] = 0;
	ft_init_hitrecord(&tmp);
	tmp.ray = rec->ray;
	if (!ft_cy_calculate_pot_hits(cy, rec->ray, ray_d, potential_hits))
		return (false);
	ft_cy_identify_hits(cy, potential_hits, &tmp);
	if (tmp.d < EPSILON)
		return (false);
	if (tmp.d < rec->d)
	{
		rec->d = tmp.d;
		rec->axis_hit = tmp.axis_hit;
		rec->point = ft_ray(rec->ray, rec->d);
		rec->normal = ft_vec3_norm(ft_cy_normal(*rec, cy));
		rec->colour = cy.colour;
		return (true);
	}
	return (false);
}

bool	ft_cy_calculate_pot_hits(t_cylinder cy, t_ray ray, t_interval ray_d, \
	float potential_hits[4])
{
	t_equation	eq;
	t_vec3		cap1_ray;
	float		cap_hit1;
	float		cap_hit2;

	cap_hit1 = -1;
	cap_hit2 = -1;
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
	ft_init_hitrecord(&rec);
	rec.ray = ray;
	ft_init_interval(&ray_d);
	if (ft_hit_plane(pl, &rec, ray_d))
		*d = rec.d;
	else
		*d = -1;
}

void	ft_cy_identify_hits(t_cylinder cy, float potential_hits[4], \
	t_hitrecord *rec)
{
	if (ft_cy_check_wall(cy, potential_hits[0], rec))
		rec->d = potential_hits[0];
	if (ft_cy_check_wall(cy, potential_hits[1], rec))
		rec->d = potential_hits[1];
	if (ft_cy_check_cap(cy, cy.cap1, potential_hits[2], rec))
		rec->d = potential_hits[2];
	if (ft_cy_check_cap(cy, cy.cap2, potential_hits[3], rec))
		rec->d = potential_hits[3];
	if (rec->d == INFINITY)
		rec->d = 0;
}
