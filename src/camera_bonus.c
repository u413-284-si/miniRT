/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:48:56 by u413q             #+#    #+#             */
/*   Updated: 2023/11/19 23:02:09 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera_bonus.h"

void	ft_initiate_image(t_image *image)
{
	image->image_width = 800;
	image->aspect_ratio = 16.0 / 9.0;
	image->image_height = (int)(image->image_width / image->aspect_ratio);
	if (image->image_height < 1)
		image->image_height = 1;
}

void	ft_initiate_camera(t_cam *cam)
{
	cam->look_from.x = -0.0;
	cam->look_from.y = 0.0;
	cam->look_from.z = 0.0;
	cam->look_at.x = 0.0;
	cam->look_at.y = 0.0;
	cam->look_at.z = -1.0;
	cam->vup.x = 0.0;
	cam->vup.y = 1.0;
	cam->vup.z = 0.0;
	cam->camera_centre.x = cam->look_from.x;
	cam->camera_centre.y = cam->look_from.y;
	cam->camera_centre.z = cam->look_from.z;
	cam->w = ft_vec3_norm(ft_vec3_sub(cam->look_from, cam->look_at));
	cam->u = ft_vec3_cross(cam->vup, cam->w);
	cam->v = ft_vec3_cross(cam->w, cam->u);
	cam->samples_per_pixel = 10;
}

void	ft_initiate_viewport(t_viewport *vp, t_cam cam, t_image image)
{
	vp->focal_length = ft_vec3_abs(ft_vec3_sub(cam.look_from, cam.look_at));
	cam.hfov = ft_degree_to_radian(100);
	vp->viewport_width = 2 * tan(cam.hfov / 2) * vp->focal_length;
	vp->viewport_height = vp->viewport_width / image.image_width \
		* image.image_height;
	vp->viewport_u = ft_vec3_scale(cam.u, vp->viewport_width);
	vp->viewport_v = ft_vec3_scale(cam.v, -vp->viewport_height);
	vp->delta_u = ft_vec3_scale(vp->viewport_u, \
		(float)(1.0 / image.image_width));
	vp->delta_v = ft_vec3_scale(vp->viewport_v, \
		(float)(1.0 / image.image_height));
	vp->viewport_upper_left = ft_vec3_sub(ft_vec3_sub(ft_vec3_sub(\
		cam.camera_centre, ft_vec3_scale(cam.w, vp->focal_length)), \
		ft_vec3_scale(vp->viewport_u, 0.5)), \
		ft_vec3_scale(vp->viewport_v, 0.5));
	vp->pixel00_pos = ft_vec3_add(vp->viewport_upper_left, ft_vec3_scale(\
		ft_vec3_add(vp->delta_u, vp->delta_v), 0.5));
}

void	ft_create_image(t_image image, t_cam cam, t_viewport vp, \
	t_entities scene)
{
	int	iterate[2];

	printf("P3\n%d %d\n255\n", image.image_width, image.image_height);
	iterate[1] = -1;
	while (++iterate[1] < image.image_height)
	{
		iterate[0] = -1;
		while (++iterate[0] < image.image_width)
			ft_write_colour(ft_get_colour(iterate, vp, cam, scene), \
				cam.samples_per_pixel);
	}
}

t_colour	ft_get_colour(int iterate[2], t_viewport vp, t_cam cam, \
	t_entities scene)
{
	int			curr_sample;
	t_ray		ray;
	t_colour	pixel_colour;

	curr_sample = -1;
	pixel_colour.r = 0.0;
	pixel_colour.g = 0.0;
	pixel_colour.b = 0.0;
	while (++curr_sample < cam.samples_per_pixel)
	{
		ray = ft_create_sample_ray(iterate[0], iterate[1], vp, cam);
		pixel_colour = ft_add_colour(pixel_colour, \
			ft_ray_colour(ray, scene));
	}
	return (pixel_colour);
}
