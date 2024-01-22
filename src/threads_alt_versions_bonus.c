/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_alt_versions_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:14:59 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 08:49:39 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	*ft_render_image_threaded(void *arg)
{
	t_render		*render;
	t_vec2i			pos;
	t_ray			ray;
	t_colour		colour;

	render = ((t_thread_data *)arg)->arg;
	ray.origin = render->cam.centre;
	ray.d = 1.0;
	pos.y = ((t_thread_data *)arg)->id;
	while (pos.y < render->cam.image.y)
	{
		pos.x = -1;
		while (++pos.x < render->cam.image.x)
		{
			colour = ft_pixel_colour(pos, ray, render->scene, render->cam);
			render->sample_buffer[pos.y * render->cam.image.x + pos.x] = colour;
		}
		pos.y += NUM_THREADS;
	}
	return (NULL);
}

void	*ft_add_sample_threaded(void *arg)
{
	t_render	*render;
	t_vec2i		pos;
	t_ray		ray;
	t_colour	colour;

	render = ((t_thread_data *)arg)->arg;
	ray.origin = render->cam.centre;
	ray.d = 1.0;
	pos.y = ((t_thread_data *)arg)->id;
	while (pos.y < render->cam.image.y)
	{
		pos.x = -1;
		while (++pos.x < render->cam.image.x)
		{
			colour = ft_anti_alias(pos, ray, render->scene, render->cam);
			colour = ft_add_colour(colour,
					render->sample_buffer[pos.y * render->cam.image.x + pos.x]);
			render->sample_buffer[pos.y * render->cam.image.x + pos.x] = colour;
		}
		pos.y += NUM_THREADS;
	}
	return (NULL);
}

void	*ft_blend_background_threaded(void *arg)
{
	t_render	*render;
	t_vec2i		pos;
	uint32_t	*img_pixel;
	uint32_t	*veil_pixel;
	uint32_t	blend_colour;

	render = ((t_thread_data *)arg)->arg;
	pos.y = ((t_thread_data *)arg)->id;
	while (pos.y < render->mlx_ptrs.veil.size.y)
	{
		pos.x = -1;
		while (++pos.x < render->mlx_ptrs.veil.size.x)
		{
			img_pixel = (uint32_t *)(render->mlx_ptrs.img.addr
					+ (pos.y * render->mlx_ptrs.img.line_len
						+ pos.x * render->mlx_ptrs.img.bytes));
			blend_colour = ft_fast_alpha_blend(*img_pixel, render->menu);
			veil_pixel = (uint32_t *)(render->mlx_ptrs.veil.addr
					+ (pos.y * render->mlx_ptrs.veil.line_len
						+ pos.x * render->mlx_ptrs.veil.bytes));
			*veil_pixel = blend_colour;
		}
		pos.y += NUM_THREADS;
	}
	return (NULL);
}

void	*ft_cam_calc_rays_threaded(void *arg)
{
	t_cam	*cam;
	t_vec2i	pos;
	t_vec3	pixel_pos;

	cam = ((t_thread_data *)arg)->arg;
	pos.y = ((t_thread_data *)arg)->id;
	while (pos.y < cam->image.y)
	{
		pos.x = -1;
		while (++pos.x < cam->image.x)
		{
			pixel_pos = ft_vec3_add(cam->pixels.pos00, ft_vec3_add(\
				ft_vec3_scale(cam->pixels.delta_u, pos.x), \
				ft_vec3_scale(cam->pixels.delta_v, pos.y)));
			cam->pix_cache[pos.y * cam->image.x + pos.x] = pixel_pos;
		}
		pos.y += NUM_THREADS;
	}
	return (NULL);
}
