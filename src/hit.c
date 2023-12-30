/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:32:23 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/29 21:54:03 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager.h"

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
