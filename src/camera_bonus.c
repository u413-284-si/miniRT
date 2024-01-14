/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:48:56 by u413q             #+#    #+#             */
/*   Updated: 2024/01/14 19:08:37 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_bonus.h"

void	ft_cam_init(t_cam *cam, t_vec2i img_size)
{
	ft_cam_calc_base_vectors(cam);
	cam->focal_length = 1.0;
	cam->image = img_size;
	ft_cam_calc_viewport_dimensions(cam);
	ft_cam_calc_pixel_grid(cam);
}

void	ft_cam_calc_base_vectors(t_cam *cam)
{
	const t_vec3	world_up = {0.0, 1.0, 0.0};

	cam->w = ft_vec3_scale(cam->direction, -1);
	if (cam->w.y == 1)
		cam->u = (t_vec3){-1, 0, 0};
	else if (cam->w.y == -1)
		cam->u = (t_vec3){1, 0, 0};
	else
		cam->u = ft_vec3_cross(world_up, cam->w);
	cam->v = ft_vec3_cross(cam->w, cam->u);
}

void	ft_cam_calc_viewport_dimensions(t_cam *cam)
{
	cam->viewport.x = 2 * tan(cam->hfov / 2) * cam->focal_length;
	cam->viewport.y = cam->viewport.x / cam->image.x * cam->image.y;
}

void	ft_cam_calc_pixel_grid(t_cam *cam)
{
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	viewport_upper_left;

	viewport_u = ft_vec3_scale(cam->u, cam->viewport.x);
	viewport_v = ft_vec3_scale(cam->v, -cam->viewport.y);
	cam->pixels.delta_u = ft_vec3_scale(viewport_u, (1.0 / cam->image.x));
	cam->pixels.delta_v = ft_vec3_scale(viewport_v, (1.0 / cam->image.y));
	viewport_upper_left = ft_vec3_sub(ft_vec3_sub(ft_vec3_sub(\
		cam->centre, ft_vec3_scale(cam->w, cam->focal_length)), \
		ft_vec3_scale(viewport_u, 0.5)), \
		ft_vec3_scale(viewport_v, 0.5));
	cam->pixels.pos00 = ft_vec3_add(viewport_upper_left, ft_vec3_scale(\
		ft_vec3_add(cam->pixels.delta_u, cam->pixels.delta_v), 0.5));
}

t_colour	ft_anti_aliase_colour(int iterate[2], t_pixel_grid pixels, \
	t_cam cam, t_entities scene)
{
	int			curr_sample;
	t_ray		ray;
	t_colour	pixel_colour;

	curr_sample = -1;
	ft_init_colour(&pixel_colour);
	while (++curr_sample < SAMPLE_SIZE)
	{
		ray = ft_create_sample_ray(iterate[0], iterate[1], pixels, cam);
		pixel_colour = ft_add_colour(pixel_colour, \
			ft_ray_colour(ray, scene, cam));
	}
	pixel_colour.r /= SAMPLE_SIZE;
	pixel_colour.g /= SAMPLE_SIZE;
	pixel_colour.b /= SAMPLE_SIZE;
	return (pixel_colour);
}
