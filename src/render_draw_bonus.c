/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:55 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/23 18:33:53 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

t_colour	ft_shoot_ray(t_vec2i pos, t_ray ray, t_entities scene, t_cam cam)
{
	t_vec3		pixel_centre;

	pixel_centre = cam.pix_cache[pos.y * cam.image.x + pos.x];
	ray.direction = ft_vec3_norm(ft_vec3_sub(pixel_centre, ray.origin));
	return (ft_ray_colour(ray, scene));
}

void	ft_raytrace_sample(t_render *render)
{
	t_vec2i		pos;
	t_ray		ray;
	t_colour	colour;

	ray.origin = render->cam.centre;
	ray.d = 1.0;
	pos.y = -1;
	while (++pos.y < render->cam.image.y)
	{
		pos.x = -1;
		while (++pos.x < render->cam.image.x)
		{
			colour = ft_shoot_ray(pos, ray, render->scene, render->cam);
			render->sample_buffer[pos.y * render->cam.image.x + pos.x] = colour;
		}
	}
}

t_vec3	ft_pixel_sample(t_pixel_grid pixels)
{
	float	px;
	float	py;

	px = -0.5 + ft_random_float();
	py = -0.5 + ft_random_float();
	return (ft_vec3_add(ft_vec3_scale(pixels.delta_u, px), \
		ft_vec3_scale(pixels.delta_v, py)));
}

t_colour	ft_shoot_aa_ray(t_vec2i pos, t_ray ray, t_entities scene, t_cam cam)
{
	t_vec3		pixel_centre;
	t_vec3		pixel_sample;

	pixel_centre = cam.pix_cache[pos.y * cam.image.x + pos.x];
	pixel_sample = ft_vec3_add(pixel_centre, ft_pixel_sample(cam.pixels));
	ray.direction = ft_vec3_norm(ft_vec3_sub(pixel_sample, ray.origin));
	return (ft_ray_colour(ray, scene));
}

void	ft_add_raytrace_sample(t_render *render)
{
	t_vec2i		pos;
	t_ray		ray;
	t_colour	colour;

	ray.origin = render->cam.centre;
	ray.d = 1.0;
	pos.y = -1;
	while (++pos.y < render->cam.image.y)
	{
		pos.x = -1;
		while (++pos.x < render->cam.image.x)
		{
			colour = ft_shoot_aa_ray(pos, ray, render->scene, render->cam);
			colour = ft_add_colour(colour,
					render->sample_buffer[pos.y * render->cam.image.x + pos.x]);
			render->sample_buffer[pos.y * render->cam.image.x + pos.x] = colour;
		}
	}
}
