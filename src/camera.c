/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:48:56 by u413q             #+#    #+#             */
/*   Updated: 2023/12/15 16:20:24 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "ft_print.h"


void	ft_cam_calc_inv_projection(t_cam *cam)
{
	t_mat4	projection;

	projection = ft_mat4_perspective(ft_degree_to_radian(cam->hfov), cam->screen.aspect_ratio, 0.1, 100.0);
	cam->inv_projection = ft_mat4_inverse(projection);
}

void	ft_cam_calc_inv_view(t_cam *cam)
{
	t_mat4	view;

	view = ft_mat4_cam_look_at(cam->look_from, ft_vec3_add(cam->look_from, cam->look_at), (t_vec3){0, 1, 0});
	cam->inv_view = ft_mat4_inverse(view);
}

void	ft_cam_calc_ray_directions(t_cam *cam)
{
	int		y;
	int		x;
	float	x_div;
	float	y_div;
	t_vec4	projected;
	t_vec3	normalized;
	t_vec4	viewed;

	y = -1;
	while (++y < cam->screen.height)
	{
		x = -1;
		while (++x < cam->screen.width)
		{
			x_div = (float)x / (float)cam->screen.width;
			x_div = x_div * 2.0 - 1.0;
			y_div = (float)y / (float)cam->screen.height;
			y_div = y_div * 2.0 - 1.0;


			projected = ft_mat4_mult_vec4(cam->inv_projection, ft_vec4_create(x_div, y_div, 1, 1));

			normalized = ft_vec3_norm(ft_vec3_scale(ft_vec3_create(projected.x, projected.y, projected.z), 1 / projected.w));

			viewed = ft_vec4_create(normalized.x, normalized.y, normalized.z, 0);

			viewed = ft_mat4_mult_vec4(cam->inv_view, viewed);

			cam->cached_rays[y * cam->screen.width + x] = ft_vec3_create(viewed.x, viewed.y, viewed.z);
		}
	}

}

void	ft_initiate_image(t_image *image)
{
	image->width = WIN_X;
	image->height = WIN_Y;
	image->aspect_ratio = image->width / image->height;

}

t_err	ft_initiate_camera(t_cam *cam)
{
	ft_initiate_image(&cam->screen);
	cam->pitch = asinf(cam->look_at.y);
	cam->yaw = atan2f(cam->look_at.z, cam->look_at.x);
	printf("Pitch: %.2f, Yaw: %.2f\n", cam->pitch, cam->yaw);
	if (ft_err_malloc((void **)cam->cached_rays,
			cam->screen.width * cam->screen.height * sizeof (*cam->cached_rays)))
		return (ERROR);
	ft_cam_calc_inv_view(cam);
	ft_cam_calc_inv_projection(cam);
	ft_cam_calc_ray_directions(cam);
	return (SUCCESS);
}

/*
void	ft_initiate_viewport(t_viewport *vp, t_cam cam, t_image image)
{
	vp->focal_length = ft_vec3_abs(ft_vec3_sub(cam.look_from, cam.look_at));
	cam.hfov = ft_degree_to_radian(cam.hfov);
	vp->viewport_width = 2 * tan(cam.hfov / 2) * vp->focal_length;
	vp->viewport_height = vp->viewport_width / image.width \
		* image.height;
	vp->viewport_u = ft_vec3_scale(cam.u, vp->viewport_width);
	vp->viewport_v = ft_vec3_scale(cam.v, -vp->viewport_height);
	vp->delta_u = ft_vec3_scale(vp->viewport_u, \
		(float)(1.0 / image.width));
	vp->delta_v = ft_vec3_scale(vp->viewport_v, \
		(float)(1.0 / image.height));
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
	int			i;
	int			j;
	t_vec3		pixel;
	t_colour	pixel_colour;
	t_ray		ray;

	printf("P3\n%d %d\n255\n", image.width, image.height);
	j = -1;
	while (++j < image.height)
	{
		i = -1;
		while (++i < image.width)
		{
			pixel = ft_vec3_add(ft_vec3_add(vp.pixel00_pos, \
				ft_vec3_scale(vp.delta_u, i)), ft_vec3_scale(vp.delta_v, j));
			ray.direction = ft_vec3_norm(ft_vec3_sub(pixel, cam.camera_centre));
			ray.origin = cam.camera_centre;
			ray.d = 1.0;
			pixel_colour = ft_ray_colour(ray, scene);
			ft_write_colour(pixel_colour);
		}
	}
}
*/

void	ft_cam_update(t_cam *cam)
{
	t_vec3	direction;

	direction.x = cos(cam->yaw) * cos(cam->pitch);
	direction.y = sin(cam->pitch);
	direction.z = sin(cam->yaw) * cos(cam->pitch);
	cam->look_at = ft_vec3_norm(direction);
	printf("yaw: %.2f, pitch: %.2f\n", cam->yaw, cam->pitch);
	printf("Look at: x (%.2f), y (%.2f), z (%.2f)\n", cam->look_at.x, cam->look_at.y, cam->look_at.z);
	ft_cam_calc_inv_view(cam);
	ft_cam_calc_inv_projection(cam);
}
