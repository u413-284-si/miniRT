/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:48:56 by u413q             #+#    #+#             */
/*   Updated: 2023/12/16 10:07:43 by gwolf            ###   ########.fr       */
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

void	ft_cam_calc_ray_direction(t_cam *cam, float y_ndc, float x_ndc, int index)
{
	t_vec4	projected;
	t_vec3	perspective_div;
	t_vec4	viewed;

	projected = ft_mat4_mult_vec4(cam->inv_projection,
			(t_vec4){x_ndc, y_ndc, 1, 1});

	perspective_div = ft_vec3_norm(ft_vec3_scale((t_vec3){projected.x, projected.y, projected.z}, 1 / projected.w));

	viewed = ft_mat4_mult_vec4(cam->inv_view,
			(t_vec4){perspective_div.x, perspective_div.y, perspective_div.z, 0});

	cam->cached_rays[index] = (t_vec3){viewed.x, viewed.y, viewed.z};

}

void	ft_cam_calc_ray_directions(t_cam *cam)
{
	int		y;
	int		x;
	float	x_ndc;
	float	y_ndc;

	y = -1;
	while (++y < cam->screen.height)
	{
		x = -1;
		while (++x < cam->screen.width)
		{
			x_ndc = (float)x / (float)cam->screen.width;
			x_ndc = x_ndc * 2.0 - 1.0;
			y_ndc = (float)y / (float)cam->screen.height;
			y_ndc = y_ndc * 2.0 - 1.0;
			ft_cam_calc_ray_direction(cam, y_ndc, x_ndc, y * cam->screen.width + x);
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
	int	sum_pixel;

	ft_initiate_image(&cam->screen);
	sum_pixel = cam->screen.height * cam->screen.width;
	cam->pitch = asinf(cam->look_at.y);
	cam->yaw = atan2f(cam->look_at.z, cam->look_at.x);
	if (ft_err_malloc((void **)&cam->cached_rays,
			sizeof (*cam->cached_rays) * sum_pixel))
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

void	ft_cam_update_angle(t_cam *cam)
{
	t_vec3	direction;

	direction.x = cos(cam->yaw) * cos(cam->pitch);
	direction.y = sin(cam->pitch);
	direction.z = sin(cam->yaw) * cos(cam->pitch);
	cam->look_at = ft_vec3_norm(direction);
}

void	ft_cam_update(t_cam *cam, bool update_angle)
{
	if (update_angle)
		ft_cam_update_angle(cam);
	ft_cam_calc_inv_view(cam);
	ft_cam_calc_ray_directions(cam);
}
