/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_light_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:15:24 by u413q             #+#    #+#             */
/*   Updated: 2023/12/27 13:08:18 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting_bonus.h"

void	ft_enlighten(t_colour *ray_colour, t_hitrecord rec, t_entities scene, \
	t_cam cam)
{
	t_light		cur;
	t_colour	light;
	int			i;

	rec.reflection_count = 0;
	light = ft_ambient_light(scene.ambient);
	i = -1;
	while (++i < scene.lsrc_count)
	{
		cur = scene.lsrc[i];
		if (ft_in_shadow(cur, rec, scene))
			continue ;
		light = ft_add_colour(light, ft_compute_colour(cur, rec, scene, cam));
	}
	*ray_colour = ft_hadamard_colour(light, rec.colour);
}

t_colour	ft_compute_colour(t_light cur, t_hitrecord rec, \
	t_entities scene, t_cam cam)
{
	t_colour	diff;
	t_colour	refl;
	t_colour	light;

	ft_init_colour(&refl);
	diff = ft_diffuse_light(cur, rec);
	if (rec.reflectivity > 0.0)
		refl = ft_reflective_light(cur, rec, scene, cam);
	light = ft_add_colour(ft_scale_colour(refl, rec.reflectivity), \
		ft_scale_colour(diff, 1.0 - rec.reflectivity));
	if (rec.shininess > 0.0)
		light = ft_add_colour(light, ft_specular_light(cur, rec, cam));
	return (light);
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

t_colour	ft_specular_light(t_light cur, t_hitrecord rec, t_cam cam)
{
	float	specular_strength;
	float	specular_factor;
	t_vec3	view_direction;
	t_vec3	reflect_direction;
	t_vec3	light_direction;

	specular_strength = 0.5;
	view_direction = ft_vec3_norm(ft_vec3_sub(cam.camera_centre, rec.point));
	light_direction = ft_vec3_norm(ft_vec3_scale(\
		ft_vec3_sub(cur.pos, rec.point), -1));
	reflect_direction = ft_vec3_norm(ft_vec3_sub(light_direction, \
		ft_vec3_scale(rec.normal, 2 * ft_vec3_dot(light_direction, \
		rec.normal))));
	specular_factor = pow(fmaxf(0.0, ft_vec3_dot(view_direction, \
		reflect_direction)), rec.shininess);
	return ((t_colour){
		.r = specular_factor * specular_strength * cur.ratio * cur.colour.r,
		.b = specular_factor * specular_strength * cur.ratio * cur.colour.b,
		.g = specular_factor * specular_strength * cur.ratio * cur.colour.g,
	});
}
