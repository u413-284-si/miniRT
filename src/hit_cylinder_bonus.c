/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:16:38 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/17 16:40:04 by sqiu             ###   ########.fr       */
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
	if (!ft_cy_calc_pot_hits(cy, rec->ray, potential_hits))
		return (false);
	if (!ft_cy_visible(ray_d, potential_hits))
		return (false);
	ft_cy_identify_hits(cy, potential_hits, &tmp);
	if (tmp.d >= EPSILON && tmp.d < rec->d)
	{
		ft_cy_set_hitrecord(cy, rec, tmp);
		return (true);
	}
	return (false);
}

bool	ft_cy_calc_pot_hits(t_cylinder cy, t_ray ray, float potential_hits[4])
{
	t_equation	eq;
	t_vec3		cap1_ray;
	float		dot_product_ray_axis;
	float		dot_product_cap_axis;

	cap1_ray = ft_vec3_sub(ray.origin, cy.cap1);
	dot_product_ray_axis = ft_vec3_dot(ray.direction, cy.axis);
	dot_product_cap_axis = ft_vec3_dot(cap1_ray, cy.axis);
	eq.a = ft_vec3_dot(ray.direction, ray.direction) - \
		pow(dot_product_ray_axis, 2);
	eq.b = 2.0 * (ft_vec3_dot(ray.direction, cap1_ray) - \
		(dot_product_ray_axis * dot_product_cap_axis));
	eq.c = ft_vec3_dot(cap1_ray, cap1_ray) - \
		pow(dot_product_cap_axis, 2) - pow(cy.d / 2.0, 2);
	if (ft_solve(&eq) < 0)
		return (false);
	potential_hits[0] = eq.d1;
	potential_hits[1] = eq.d2;
	potential_hits[2] = ft_cy_cap_hit(cy, ray, cy.cap1);
	potential_hits[3] = ft_cy_cap_hit(cy, ray, cy.cap2);
	return (true);
}

float	ft_cy_cap_hit(t_cylinder cy, t_ray ray, t_vec3 cap)
{
	const t_plane	pl = (t_plane){.point = cap, .normal = cy.axis, \
		.colour = cy.colour};
	t_hitrecord		rec;
	t_interval		ray_d;

	ft_init_hitrecord(&rec);
	rec.ray = ray;
	ft_init_interval(&ray_d);
	if (ft_hit_plane(pl, &rec, ray_d))
		return (rec.d);
	else
		return (-1);
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

void	ft_cy_set_hitrecord(t_cylinder cy, t_hitrecord *rec, t_hitrecord tmp)
{
	rec->d = tmp.d;
	rec->axis_hit = tmp.axis_hit;
	rec->point = ft_scale_ray(rec->ray, rec->d);
	rec->normal = ft_cy_normal(*rec, cy);
	if (tmp.wall_hit)
		ft_get_cy_uvcoords(rec, cy);
	else
	{
		ft_get_pl_uvcoords(rec);
		rec->u *= 2;
		rec->v *= 2;
	}
	rec->colour = cy.colour;
}
