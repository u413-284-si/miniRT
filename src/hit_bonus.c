/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:32:23 by sqiu              #+#    #+#             */
/*   Updated: 2023/11/21 12:13:25 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hit_manager_bonus.h"

bool	ft_hit_hittable(t_hittable obj, t_ray ray, t_hitrecord *rec, \
	t_interval ray_d)
{
	if (obj.type == SPHERE)
		return (ft_hit_sphere(obj.params.sp, ray, rec, ray_d));
	else if (obj.type == PLANE)
		return (ft_hit_plane(obj.params.pl, ray, rec, ray_d));
	else if (obj.type == CYLINDER)
		return (ft_hit_cylinder(obj.params.cy, ray, rec, ray_d));
	else
		return (false);
}
