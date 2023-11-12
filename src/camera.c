/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:48:56 by u413q             #+#    #+#             */
/*   Updated: 2023/11/11 22:53:39 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"


void	ft_initiate_camera(t_cam *cam)
{
	cam->image_width = 400;
	cam->aspect_ratio = 4.0 / 3.0;
	cam->image_height = (int)(cam->image_width / cam->aspect_ratio);
	if (cam->image_height < 1)
		cam->image_height = 1;
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
	cam->focal_length = ft_vec3_abs(ft_vec3_sub(cam->look_from, cam->look_at));
	cam->vfov = 100;
}

void	ft_initiate_viewport(t_cam *cam)
{
	float	theta;

	theta = ft_degree_to_radian(cam->vfov);
	cam->viewport_height = 2 * tan(theta / 2) * cam->focal_length;
	cam->viewport_width = cam->viewport_height * (float)(cam->image_width \
		/ cam->image_height);
	cam->viewport_u = ft_vec3_scale(cam->u, cam->viewport_width);
	cam->viewport_v = ft_vec3_scale(cam->v, -cam->viewport_height);
	cam->viewport_w.x = 0;
	cam->viewport_w.y = 0;
	cam->viewport_w.z = -cam->focal_length;
	cam->delta_u = ft_vec3_scale(cam->viewport_u, \
		(float)(1.0 / cam->image_width));
	cam->delta_v = ft_vec3_scale(cam->viewport_v, \
		(float)(1.0 / cam->image_height));
	cam->viewport_upper_left = ft_vec3_sub(ft_vec3_sub(ft_vec3_sub(\
		cam->camera_centre, ft_vec3_scale(cam->w, cam->focal_length)), \
		ft_vec3_scale(cam->viewport_u, 0.5)), \
		ft_vec3_scale(cam->viewport_v, 0.5));
	cam->pixel00_pos = ft_vec3_add(cam->viewport_upper_left, ft_vec3_scale(\
		ft_vec3_add(cam->delta_u, cam->delta_v), 0.5));
}

void	ft_create_image(t_cam cam, t_entities scene)
{
	int			i;
	int			j;
	t_vec3		pixel;
	t_colour	pixel_colour;
	t_ray		ray;

	printf("P3\n%d %d\n255\n", cam.image_width, cam.image_height);
	j = -1;
	while (++j < cam.image_height)
	{
		i = -1;
		while (++i < cam.image_width)
		{
			pixel = ft_vec3_add(ft_vec3_add(cam.pixel00_pos, \
				ft_vec3_scale(cam.delta_u, i)), ft_vec3_scale(cam.delta_v, j));
			ray.direction = ft_vec3_sub(pixel, cam.camera_centre);
			ray.origin = cam.camera_centre;
			ray.d = 1.0;
			pixel_colour = ft_ray_colour(ray, scene);
			ft_write_colour(pixel_colour);
		}
	}
}
