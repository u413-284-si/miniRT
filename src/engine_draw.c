/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:00:30 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/06 18:20:11 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"


float	ft_max_fl(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

t_vec3	ft_calc_pix_centre(t_viewport vp, int i, int j)
{
	t_vec3	pos_u;
	t_vec3	pos_v;
	t_vec3	pix_centre;

	pos_u = ft_vec3_scale(vp.delta_u, i);
	pos_v = ft_vec3_scale(vp.delta_v, j);
	pix_centre = ft_vec3_add(vp.pixel00_pos, pos_u);
	pix_centre = ft_vec3_add(pix_centre, pos_v);
	return (pix_centre);
}

int	ft_calc_pix_colour(t_cam cam, t_vec3 pix_centre, t_entities scene)
{
	t_ray		ray;
	t_colour	pix_colour;
	int			colour;

	ray.origin = cam.camera_centre;
	ray.direction = ft_vec3_norm(ft_vec3_sub(pix_centre, cam.camera_centre));
	ray.d = 1.0;
	pix_colour = ft_ray_colour(ray, scene);
	colour = ft_convert_colour2int(pix_colour);
	return (colour);
}

t_colour	ft_per_pixel(float x, float y)
{
	t_vec3 ray_origin = ft_vec3_create(0.0, 0.0, 1.0);
	t_vec3 ray_direction = ft_vec3_create(x, y, -1.0);
	float radius = 0.5;

	float a = ft_vec3_dot(ray_direction, ray_direction);
	float b = 2.0 * ft_vec3_dot(ray_origin, ray_direction);
	float c = ft_vec3_dot(ray_origin, ray_origin) - (radius * radius);

	float discriminant = b * b - 4.0 * a * c;

	if (discriminant <  0.0)
		return (ft_colour_create(0, 0, 0));

	//float t0 = (-b + sqrt(discriminant)) / (2.0 * a);
	float t_close = (-b - sqrtf(discriminant)) / (2.0 * a);

	//t_vec3	h0 = ft_vec3_scale(ft_vec3_add(ray_origin, ray_direction), t0);
	t_vec3	hit_point = ft_vec3_add(ray_origin, ft_vec3_scale(ray_direction, t_close));
	t_vec3	normal = ft_vec3_norm(hit_point);

	t_vec3	light_dir = ft_vec3_scale(ft_vec3_norm(ft_vec3_create(-1.0, -1.0, -1.0)), -1);

	// cos(angle)
	float d = ft_max_fl(ft_vec3_dot(normal, light_dir), 0.1);
	t_vec3	sphere_color = ft_vec3_scale(ft_vec3_create(1.0, 0.0, 1.0), d);

	return (ft_colour_create(sphere_color.x, sphere_color.y, sphere_color.z));
}

int	ft_draw_scene(t_engine *engine)
{
	int			x;
	int			y;
	//t_vec3		pix_centre;
	t_colour	colour;


	y = -1;
	while (++y < engine->image.image_height)
	{
		x = -1;
		while (++x < engine->image.image_width)
		{
			float x_div = (float)x / (float)engine->image.image_width;
			x_div = x_div * 2.0 - 1.0;
			x_div *= engine->image.aspect_ratio;
			float y_div = (float)y / (float)engine->image.image_height;
			y_div = y_div * 2.0 - 1.0;
			colour = ft_per_pixel(x_div, y_div);
			colour = ft_clamp_colour(colour, 0.0, 1.0);
			int convert = ft_convert_colour2int(colour);
			// flip image height with height - 1 - y
			ft_put_pix_to_image(&engine->render.buffer, x, engine->image.image_height - 1 - y, convert);

		}
	}
	mlx_put_image_to_window(engine->render.mlx_ptr, engine->render.win_ptr,
		engine->render.buffer.ptr, 0, 0);
	return (0);
}
