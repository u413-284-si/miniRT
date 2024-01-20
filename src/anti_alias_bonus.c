/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_alias_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:34:12 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/20 15:59:09 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

uint32_t	ft_anti_aliase_colour(t_vec2i iterate, t_pixel_grid pixels, \
	t_cam cam, t_entities scene)
{
	int			curr_sample;
	t_ray		ray;
	t_colour	pixel_colour;
	t_vec3		pixel_centre;

	curr_sample = -1;
	pixel_colour = (t_colour){0};
	pixel_centre = cam.pix_cache[iterate.y * cam.image.x + iterate.x];
	while (++curr_sample < SAMPLE_SIZE)
	{
		ray = ft_create_sample_ray(pixel_centre, pixels, cam);
		pixel_colour = ft_add_colour(pixel_colour, \
			ft_ray_colour(ray, scene, cam));
	}
	pixel_colour.r /= SAMPLE_SIZE;
	pixel_colour.g /= SAMPLE_SIZE;
	pixel_colour.b /= SAMPLE_SIZE;
	return (ft_convert_colour2int(pixel_colour));
}

t_ray	ft_create_sample_ray(t_vec3 pixel_centre, t_pixel_grid pixels, \
	t_cam cam)
{
	t_vec3	pixel_sample;
	t_ray	ray;

	pixel_sample = ft_vec3_add(pixel_centre, ft_pixel_sample(pixels));
	ray.origin = cam.centre;
	ray.direction = ft_vec3_norm(ft_vec3_sub(pixel_sample, ray.origin));
	ray.d = 1.0;
	return (ray);
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
