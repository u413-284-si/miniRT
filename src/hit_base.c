/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:32:23 by sqiu              #+#    #+#             */
/*   Updated: 2024/01/12 20:38:23 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

void	ft_init_hitrecord(t_hitrecord *rec)
{
	rec->axis_hit = (t_vec3){.x = 0, .y = 0, .z = 0};
	rec->colour = (t_colour){.b = 0, .g = 0, .r = 0};
	rec->d = INFINITY;
	rec->normal = (t_vec3){.x = 0, .y = 0, .z = 0};
	rec->point = (t_vec3){.x = 0, .y = 0, .z = 0};
	rec->ray = (t_ray){.origin = {0}, .direction = {0}, .d = 0};
}

bool	ft_hit_hittable(t_hittable obj, t_hitrecord *rec, t_interval ray_d)
{
	if (obj.type == SPHERE)
		return (ft_hit_sphere(obj.params.sp, rec, ray_d));
	else if (obj.type == PLANE)
		return (ft_hit_plane(obj.params.pl, rec, ray_d));
	else if (obj.type == CYLINDER)
		return (ft_hit_cylinder(obj.params.cy, rec, ray_d));
	else
		return (false);
}
