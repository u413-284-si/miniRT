/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:32:23 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/15 12:02:17 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager_bonus.h"

void	ft_init_hitrecord(t_hitrecord *rec)
{
	rec->axis_hit = (t_vec3){.x = 0, .y = 0, .z = 0};
	rec->colour = (t_colour){.b = 0, .g = 0, .r = 0};
	rec->d = INFINITY;
	rec->normal = (t_vec3){.x = 0, .y = 0, .z = 0};
	rec->point = (t_vec3){.x = 0, .y = 0, .z = 0};
	rec->ray = (t_ray){.origin = {0}, .direction = {0}, .d = 0};
	rec->shininess = 0.0;
	rec->reflectivity = 0.0;
	rec->checkered = false;
	rec->u = 0.0;
	rec->v = 0.0;
	rec->wall_hit = false;
}

bool	ft_hit_hittable(t_hittable obj, t_hitrecord *rec, t_interval ray_d)
{
	if (obj.type == SPHERE)
		return (ft_hit_sphere(obj.params.sp, rec, ray_d));
	else if (obj.type == PLANE)
		return (ft_hit_plane(obj.params.pl, rec, ray_d));
	else if (obj.type == CYLINDER)
		return (ft_hit_cylinder(obj.params.cy, rec, ray_d));
	else if (obj.type == CONE)
		return (ft_hit_cone(obj.params.co, rec, ray_d));
	else
		return (false);
}

void	ft_set_hitrecord_features(t_hitrecord *rec, t_hittable cur, \
	t_interval *ray_d)
{
	ray_d->max = rec->d;
	rec->shininess = cur.shininess;
	rec->reflectivity = cur.reflectivity;
	if (cur.checkered)
		rec->checkered = true;
}
