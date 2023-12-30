/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:09:27 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/30 00:43:46 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager_bonus.h"
#include "geometric_transform_bonus.h"

bool	ft_hit_cone(t_cone co, t_hitrecord *rec, t_interval ray_d)
{
	t_ray		bckray;
	t_vec3		hits[3];
	t_hitrecord	tmp;

	(void)ray_d;
	hits[0] = (t_vec3){-1.0, -1.0, -1.0};
	hits[1] = (t_vec3){-1.0, -1.0, -1.0};
	hits[2] = (t_vec3){-1.0, -1.0, -1.0};
	ft_init_hitrecord(&tmp);
	bckray = ft_get_bckray(co, *rec);
	bckray.direction = ft_vec3_norm(bckray.direction);
	if (!ft_calculate_cone_hits(bckray, hits, co.h, &tmp) \
		&& !ft_calculate_cap_hit(bckray, hits, co.r, &tmp))
		return (false);
	t_mat4	fwd;
	t_mat4	bck;
	t_vec3	rotation;
	rotation = ft_get_rotation_vec3(co.axis);
	ft_set_transform(co.base, rotation, (t_vec3){0, 0, 0}, &fwd);
	ft_invert_matrix(fwd, &bck);
	if (tmp.point.z == 0)
	{
		tmp.normal = (t_vec3){0.0, 0.0, 1.0};
		t_vec3	origin = ft_transform_vec3((t_vec3){0.0, 0.0, 0.0}, FWDTRFM, fwd, bck);
		tmp.normal = ft_vec3_norm(ft_vec3_sub(ft_transform_vec3(tmp.normal, FWDTRFM, fwd, bck), origin));
	}
	else
	{
		tmp.normal.x = tmp.point.x;
		tmp.normal.y = tmp.point.y;
		tmp.normal.z = -sqrtf(pow(tmp.point.x, 2.0) + pow(tmp.point.y, 2.0));
		tmp.normal = ft_vec3_norm(ft_transform_vec3(tmp.normal, FWDTRFM, fwd, bck));
	}
	tmp.point = ft_transform_vec3(tmp.point, FWDTRFM, fwd, bck);
	tmp.d = ft_vec3_abs(ft_vec3_sub(tmp.point, rec->ray.origin));
	if (tmp.d < rec->d)
	{
		rec->d = tmp.d;
		rec->point = tmp.point;
		rec->normal = tmp.normal;
		//rec->normal = ft_vec3_norm(ft_co_normal(*rec, co));
		rec->colour = co.colour;
		return (true);
	}
	return (false);
}

t_ray	ft_get_bckray(t_cone co, t_hitrecord rec)
{
	t_mat4	fwd;
	t_mat4	bck;
	t_vec3	rotation;
	t_ray	bckray;

	rotation = ft_get_rotation_vec3(co.axis);
	ft_set_transform(co.base, rotation, (t_vec3){0, 0, 0}, &fwd);
	ft_invert_matrix(fwd, &bck);
	bckray = ft_transform_ray(rec.ray, BCKTRFM, fwd, bck);
	return (bckray);
}

bool	ft_calculate_cone_hits(t_ray bckray, t_vec3 hits[3], float h, \
	t_hitrecord *tmp)
{
	t_equation	eq;

	eq.a = pow(bckray.direction.x, 2.0) + pow(bckray.direction.y, 2.0) - \
		pow(bckray.direction.z, 2.0);
	eq.b = 2.0 * (bckray.origin.x * bckray.direction.x + bckray.origin.y * \
		bckray.direction.y - bckray.origin.z * bckray.direction.z);
	eq.c = pow(bckray.origin.x, 2.0) + pow(bckray.origin.y, 2.0) - \
		pow(bckray.origin.z, 2.0);
	if (ft_solve(&eq) < 0)
		return (false);
	hits[0] = ft_ray(bckray, eq.d1);
	hits[1] = ft_ray(bckray, eq.d2);
	tmp->d = eq.d1;
	tmp->point = hits[0];
	if (!ft_check_cone_hits(eq.d1, hits[0], h))
	{
		tmp->d = eq.d2;
		tmp->point = hits[1];
		if (!ft_check_cone_hits(eq.d2, hits[1], h))
			return (false);
	}
	return (true);
}

bool	ft_check_cone_hits(float d, t_vec3 hit, float h)
{
	if (d > 0.0 && hit.z > 0.0 && hit.z < h)
		return (true);
	return (false);
}

bool	ft_calculate_cap_hit(t_ray bckray, t_vec3 hits[3], float r, \
	t_hitrecord *tmp)
{
	int	d;

	if (ft_nearly_equal_flt(bckray.direction.z, 0.0))
		return (false);
	d = (bckray.origin.z - 1.0) / -bckray.direction.z;
	hits[2] = ft_ray(bckray, d);
	if (d > 0.0 && sqrtf(pow(hits[2].x, 2.0) + pow(hits[2].y, 2.0)) < r && \
		d < tmp->d)
	{
		tmp->d = d;
		tmp->point = hits[2];
		return (true);
	}
	return (false);
}
