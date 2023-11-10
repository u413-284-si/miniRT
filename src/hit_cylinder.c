/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:16:38 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/10 19:36:02 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

bool	ft_hit_cylinder(t_cylinder cy, t_ray ray, t_hitrecord *rec, \
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
}
