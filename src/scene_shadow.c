/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_shadow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:20:56 by sqiu              #+#    #+#             */
/*   Updated: 2023/12/24 21:16:13 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"

bool	ft_in_shadow(t_light cur, t_hitrecord rec, t_entities scene)
{
	t_ray		shadow_ray;
	t_vec3		light_dir;
	t_interval	ray_d;

	light_dir = ft_vec3_sub(cur.pos, rec.point);
	shadow_ray.origin = rec.point;
	shadow_ray.direction = ft_vec3_norm(light_dir);
	ray_d.max = ft_vec3_abs(light_dir);
	ray_d.min = 0.001;
	return (ft_shadow_ray_blocked(scene, shadow_ray, ray_d));
}

bool	ft_shadow_ray_blocked(t_entities scene, t_ray shadow_ray, \
	t_interval ray_d)
{
	t_hitrecord	block;
	t_hittable	cur;
	int			i;

	ft_init_hitrecord(&block);
	i = -1;
	while (++i < scene.total)
	{
		cur = scene.obj[i];
		if (ft_hit_hittable(cur, shadow_ray, &block, ray_d))
			return (true);
	}
	return (false);
}
