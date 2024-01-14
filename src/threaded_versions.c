/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threaded_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:14:59 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/14 10:30:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	*ft_render_image_threaded(void *arg)
{
	t_render		*render;
	t_vec2i			pos;
	t_ray			ray;
	t_colour		pixel_colour;
	int				colour;

	render = ((t_thread_data *)arg)->arg;
	ray.origin = render->cam.centre;
	ray.d = 1.0;
	pos.y = ((t_thread_data *)arg)->id;
	while (pos.y < render->cam.image.y)
	{
		pos.x = -1;
		while (++pos.x < render->cam.image.x)
		{
			ray.direction = render->cam.ray_cache[pos.y * render->cam.image.x + pos.x];
			pixel_colour = ft_ray_colour(ray, render->scene);
			colour = ft_convert_colour2int(pixel_colour);
			ft_put_pix_to_image(&render->mlx_ptrs.img, pos.x, pos.y, colour);
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
	t_vec3	direction;

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
			direction = ft_vec3_norm(ft_vec3_sub(pixel_pos, cam->centre));
			cam->ray_cache[pos.y * cam->image.x + pos.x] = direction;
		}
		pos.y += NUM_THREADS;
	}
	return (NULL);
}
