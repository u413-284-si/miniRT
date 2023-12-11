/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:48:56 by u413q             #+#    #+#             */
/*   Updated: 2023/12/08 02:22:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "ft_print.h"

void printMatrix(t_mat4 mat);

void	ft_cam_recalc_projection(t_cam *cam)
{
	ft_mat4_perspective(cam->projection, ft_degree_to_radian(cam->hfov), RATIO, 0.1, 100.0);
	//ft_printf("Proj mat\n");
	//printMatrix(cam->projection);
	ft_inverse_matrix(cam->projection, cam->inv_projection);
	//ft_printf("Inv proj mat\n");
	//printMatrix(cam->inv_projection);
}

void	ft_cam_recalc_view(t_cam *cam)
{
	ft_cam_view_mat(cam);
	ft_printf("View mat\n");
	printMatrix(cam->view);
	ft_inverse_matrix(cam->view, cam->inv_view);
	ft_printf("Inv view mat\n");
	printMatrix(cam->inv_view);
}

void	ft_initiate_image(t_image *image)
{
	image->image_width = WIN_X;
	image->aspect_ratio = RATIO;
	image->image_height = (int)(image->image_width / image->aspect_ratio);
	if (image->image_height < 1)
		image->image_height = 1;
}

void	ft_initiate_camera(t_cam *cam)
{
	cam->vup = ft_vec3_create(0.0, 1.0, 0.0);
	cam->camera_centre = cam->look_from;
	cam->direction = ft_vec3_norm(cam->look_at);
	cam->right = ft_vec3_norm(ft_vec3_cross(cam->direction, cam->vup));
	cam->w = ft_vec3_norm(ft_vec3_sub(cam->look_from, cam->look_at));
	cam->u = ft_vec3_cross(cam->vup, cam->w);
	cam->v = ft_vec3_cross(cam->w, cam->u);
	ft_cam_recalc_view(cam);
	ft_cam_recalc_projection(cam);
}

void	ft_initiate_viewport(t_viewport *vp, t_cam cam, t_image image)
{
	vp->focal_length = ft_vec3_abs(ft_vec3_sub(cam.look_from, cam.look_at));
	cam.hfov = ft_degree_to_radian(cam.hfov);
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
	int			i;
	int			j;
	t_vec3		pixel;
	t_colour	pixel_colour;
	t_ray		ray;

	printf("P3\n%d %d\n255\n", image.image_width, image.image_height);
	j = -1;
	while (++j < image.image_height)
	{
		i = -1;
		while (++i < image.image_width)
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

void	ft_cam_view_mat(t_cam *cam)
{
	t_vec3	cam_up;

	cam_up = ft_vec3_norm(ft_vec3_cross(cam->right, cam->direction));
	cam->view[0][0] = cam->right.x;
	cam->view[1][0] = cam->right.y;
	cam->view[2][0] = cam->right.z;
	cam->view[0][1] = cam_up.x;
	cam->view[1][1] = cam_up.y;
	cam->view[2][1] = cam_up.z;
	cam->view[0][2] = -cam->direction.x;
	cam->view[1][2] = -cam->direction.y;
	cam->view[2][2] = -cam->direction.z;
	cam->view[3][0] = -ft_vec3_dot(cam->right, cam->look_from);
	cam->view[3][1] = -ft_vec3_dot(cam_up, cam->look_from);
	cam->view[3][2] = ft_vec3_dot(cam->direction, cam->look_from);
	cam->view[0][3] = 0;
	cam->view[1][3] = 0;
	cam->view[2][3] = 0;
	cam->view[3][3] = 1;
}

void	ft_cam_update(t_cam *cam)
{
	cam->right = ft_vec3_norm(ft_vec3_cross(cam->direction, cam->vup));
	ft_cam_recalc_view(cam);
	ft_cam_recalc_projection(cam);
}
