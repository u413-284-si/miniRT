/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:15:24 by u413q             #+#    #+#             */
/*   Updated: 2023/11/17 14:40:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting.h"

void	ft_enlighten(t_colour *ray_colour, t_hitrecord rec, t_entities scene)
{
	t_light		cur;
	t_colour	tmp;
	t_colour	ambient;
	t_colour	diffuse;
	int			i;

	ambient = ft_ambient_light(scene.ambient);
	*ray_colour = ft_hadamard_colour(ambient, rec.colour);
	i = -1;
	while (++i < scene.lsrc_count)
	{
		cur = scene.lsrc[i];
		if (ft_in_shadow(cur, rec, scene))
			continue ;
		diffuse = ft_diffuse_light(cur, rec);
		tmp = ft_hadamard_colour(diffuse, rec.colour);
		*ray_colour = ft_add_colour(*ray_colour, tmp);
	}
}

t_colour	ft_ambient_light(t_light ambient)
{
	return ((t_colour){
		.r = ambient.colour.r * ambient.ratio,
		.b = ambient.colour.b * ambient.ratio,
		.g = ambient.colour.g * ambient.ratio,
	});
}

t_colour	ft_diffuse_light(t_light cur, t_hitrecord rec)
{
	t_vec3	light_dir;
	float	dot_product;

	light_dir = ft_vec3_norm(ft_vec3_sub(cur.pos, rec.point));
	dot_product = fmaxf(0.0, ft_vec3_dot(light_dir, rec.normal));
	return ((t_colour){
		.r = dot_product * cur.ratio * cur.colour.r,
		.b = dot_product * cur.ratio * cur.colour.b,
		.g = dot_product * cur.ratio * cur.colour.g,
	});
}
