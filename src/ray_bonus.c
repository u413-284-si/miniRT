/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:05:20 by u413q             #+#    #+#             */
/*   Updated: 2023/12/16 16:50:52 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lighting_bonus.h"

t_vec3	ft_ray(t_ray ray, float d)
{
	return (ft_vec3_add(ray.origin, ft_vec3_scale(ray.direction, d)));
}

void	ft_init_hitrecord(t_hitrecord *rec)
{
	rec->axis_hit = (t_vec3){.x = 0, .y = 0, .z = 0};
	rec->colour = (t_colour){.b = 0, .g = 0, .r = 0};
	rec->d = INFINITY;
	rec->normal = (t_vec3){.x = 0, .y = 0, .z = 0};
	rec->point = (t_vec3){.x = 0, .y = 0, .z = 0};
}

t_colour	ft_ray_colour(t_ray ray, t_entities scene, t_cam cam)
{
	t_colour	ray_colour;
	t_hitrecord	rec;
	t_hittable	cur;
	t_interval	ray_d;
	int			i;

	ft_init_colour(&ray_colour);
	ft_init_hitrecord(&rec);
	ft_init_interval(&ray_d);
	i = -1;
	while (++i < scene.total)
	{
		cur = scene.obj[i];
		if (ft_hit_hittable(cur, ray, &rec, ray_d))
		{
			if (rec.d < ray_d.max)
			{
				ray_d.max = rec.d;
				rec.shininess = cur.shininess;
			}
		}
	}
	if (ray_d.max < INFINITY)
	{
		ft_enlighten(&ray_colour, rec, scene, cam);
		return (ray_colour);
	}
	return (ft_background_colour(ray));
}

t_colour	ft_background_colour(t_ray ray)
{
	t_vec3		unit_direction;
	float		a;
	t_colour	white;
	t_colour	blue;
	t_colour	ray_colour;

	white.r = 1.0;
	white.g = 1.0;
	white.b = 1.0;
	blue.r = 0.5;
	blue.g = 0.7;
	blue.b = 1.0;

	unit_direction = ft_vec3_norm(ray.direction);
	a = 0.5 * (unit_direction.y + 1.0);
	ray_colour.r = (1.0 - a) * white.r + a * blue.r;
	ray_colour.g = (1.0 - a) * white.g + a * blue.g;
	ray_colour.b = (1.0 - a) * white.b + a * blue.b;
	return (ray_colour);
}