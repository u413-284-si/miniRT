/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:16:38 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/14 16:48:52 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

bool	ft_hit_cylinder(t_cylinder cy, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d)
{
	float		potential_hits[4];

	if (!ft_calculate_pot_hits(cy, ray, ray_d, potential_hits))
		return (false);
	ft_identify_hits(cy, ray, potential_hits, rec);
	if (rec->d < EPSILON)
		return (false);
	rec->point = ft_ray(ray, rec->d);
	rec->normal = ft_vec3_norm(ft_cylinder_normal(*rec, ray, cy));
	rec->colour = cy.colour;
	return (true);
}

bool	ft_calculate_pot_hits(t_cylinder cy, t_ray ray, t_interval ray_d, \
	float potential_hits[4])
{
	t_equation	eq;
	t_vec3		cap1_ray;
	float		d3;
	float		d4;

	cap1_ray = ft_vec3_sub(ray.origin, cy.cap1);
	eq.a = ft_vec3_dot(ray.direction, ray.direction) - \
		pow(ft_vec3_dot(ray.direction, cy.axis), 2);
	eq.b = 2.0 * (ft_vec3_dot(ray.direction, cap1_ray) - \
		(ft_vec3_dot(ray.direction, cy.axis) * ft_vec3_dot(cap1_ray, cy.axis)));
	eq.c = ft_vec3_dot(cap1_ray, cap1_ray) - \
		pow(ft_vec3_dot(cap1_ray, cy.axis), 2) - pow(cy.d / 2.0, 2);
	if (ft_solve(&eq) < 0)
		return (false);
	ft_hit_cap(cy, ray, cy.cap1, &d3);
	ft_hit_cap(cy, ray, cy.cap2, &d4);
	if (!ft_visible(eq, ray_d, d3, d4))
		return (false);
	potential_hits[0] = eq.d1;
	potential_hits[1] = eq.d2;
	potential_hits[2] = d3;
	potential_hits[3] = d4;
	return (true);
}

void	ft_hit_cap(t_cylinder cy, t_ray ray, t_vec3 cap, float *d)
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

void	ft_identify_hits(t_cylinder cy, t_ray ray, float potential_hits[4], \
	t_hitrecord *rec)
{
	if (ft_check_wall(cy, ray, potential_hits[0], rec) \
		&& potential_hits[0] < rec->d)
		rec->d = potential_hits[0];
	if (ft_check_wall(cy, ray, potential_hits[1], rec) \
		&& potential_hits[1] < rec->d)
		rec->d = potential_hits[1];
	if (ft_check_cap(cy, ray, cy.cap1, potential_hits[2]) \
		&& potential_hits[2] < rec->d)
	{
		rec->axis_hit = cy.cap1;
		rec->d = potential_hits[2];
	}
	if (ft_check_cap(cy, ray, cy.cap2, potential_hits[3]) \
		&& potential_hits[3] < rec->d)
	{
		rec->axis_hit = cy.cap2;
		rec->d = potential_hits[3];
	}
}

/* 	float	a;
	float	b;
	float	c;
	float	z;
	float	discriminant;
	float	d;
	t_vec3	cy_centre_ray_origin;

	cy_centre_ray_origin = ft_vec3_sub(ray.origin, cy.centre);
	a = ft_vec3_dot(ray.direction, ray.direction) - pow (ray.direction.z, 2);
	b = 2.0 * ft_vec3_dot(ray.direction, cy_centre_ray_origin) - 2.0 * \
		ray.direction.z * cy_centre_ray_origin.z;
	c = ft_vec3_dot(cy_centre_ray_origin, cy_centre_ray_origin) - \
		pow(cy_centre_ray_origin.z, 2) - pow(cy.d / 2, 2);
	discriminant = pow(b, 2) - 4.0 * a * c;
	if (discriminant < 0)
		return (false);
	d = (-b - sqrt(discriminant)) / (2.0 * a);
	if (!ft_surrounds(d, ray_d))
	{
		d = (-b + sqrt(discriminant)) / (2.0 * a);
		if (!ft_surrounds(d, ray_d))
			return (false);
	}
	z = cy_centre_ray_origin.z + d * ray.direction.z;
	if (z < cy.centre.z - cy.h / 2 || z > cy.centre.z + cy.h / 2)
		return (false);
	rec->d = d;
	rec->point = ft_ray(ray, d);
	rec->normal = ft_vec3_scale(ft_vec3_sub(rec->point, cy.centre), \
		(1.0 / cy.d / 2));
	rec->colour.r = cy.colour.r;
	rec->colour.b = cy.colour.b;
	rec->colour.g = cy.colour.g; */

/* bool	ft_hit_cylinder(t_cylinder cy, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d)
{
	t_vec3	centre_proj;
	t_vec3	centre_perp;
	t_vec3	ray_origin_proj;
	t_vec3	ray_origin_perp;
	t_vec3	ray_dir_proj;
	t_vec3	ray_dir_perp;
	t_ray	ray_proj;
	t_sphere	sp;
	float	d[2];
	float	hit_centre_proj;

	(void)ray_d;
	centre_proj = ft_vec3_project(cy.centre, cy.axis);
	centre_perp = ft_vec3_sub(cy.centre, centre_proj);
	ray_origin_proj = ft_vec3_project(ray.origin, cy.axis);
	ray_origin_perp = ft_vec3_sub(ray.origin, ray_origin_proj);
	ray_dir_proj = ft_vec3_project(ray.direction, cy.axis);
	ray_dir_perp = ft_vec3_sub(ray.direction, ray_dir_proj);
	ray_proj.origin = ray_origin_perp;
	ray_proj.direction = ray_dir_perp;
	ray_proj.d = 1.0;
	sp.centre = centre_perp;
	sp.r = cy.d / 2;
	sp.colour.r = cy.colour.r;
	sp.colour.b = cy.colour.b;
	sp.colour.g = cy.colour.g;
	if (ft_hit_cylindersphere(sp, ray_proj, d))
		return (false);
	int	i;
	i = -1;
	while (++i < 2)
	{
		hit_centre_proj = ft_vec3_abs(ft_vec3_sub(ft_vec3_add(ray_origin_proj, \
			ft_vec3_scale(ray_dir_proj, d[i])), centre_proj));
		if (hit_centre_proj >= cy.h / 2)
			continue ;
		rec->d = d[i];
		rec->point = ft_ray(ray, d[i]);
		rec->normal = ft_vec3_scale(ft_vec3_sub(rec->point, sp.centre), \
			(1.0 / sp.r));
		rec->colour.r = sp.colour.r;
		rec->colour.b = sp.colour.b;
		rec->colour.g = sp.colour.g;
		return (true);
	}
	return (false);
}

int	ft_hit_cylindersphere(t_sphere sp, t_ray ray, float d[2])
{
	t_vec3	sp_centre_ray;
	float	a;
	float	b;
	float	c;
	float	discriminant;

	sp_centre_ray = ft_vec3_sub(ray.origin, sp.centre);
	a = ft_vec3_dot(ray.direction, ray.direction);
	b = 2.0 * ft_vec3_dot(ray.direction, sp_centre_ray);
	c = ft_vec3_dot(sp_centre_ray, sp_centre_ray) - pow(sp.r, 2);
	discriminant = pow(b, 2) - 4.0 * a * c;
	if (discriminant < 0)
		return (1);
	d[0] = (-b - sqrt(discriminant)) / (2.0 * a);
	d[1] = (-b + sqrt(discriminant)) / (2.0 * a);
	return (0);
} */
