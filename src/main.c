/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u413q <u413q@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:55:47 by sqiu              #+#    #+#             */
/*   Updated: 2023/10/27 15:18:17 by u413q            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "colour.h"
#include "vec3.h"
#include "ray.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error\n");
		exit(123);
	}

	// image
	float		aspect_ratio;
	int			image_width;
	int			image_height;

	image_width = 400;
	aspect_ratio = 16.0 / 9.0;
	image_height = (int)(image_width / aspect_ratio);
	if (image_height < 1)
		image_height = 1;

	// Camera
	float		viewport_height;
	float		viewport_width;
	float		focal_length;
	t_vec3		camera_centre;

	focal_length = 1.0;
	viewport_height = 2.0;
	viewport_width = viewport_height * (float)(image_width / image_height);
	camera_centre.x = 0;
	camera_centre.y = 0;
	camera_centre.z = 0;

	// Viewport
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	viewport_w;
	t_vec3	delta_u;
	t_vec3	delta_v;
	t_vec3	viewport_upper_left;
	t_vec3	pixel00_pos;

	viewport_u.x = viewport_width;
	viewport_u.y = 0;
	viewport_u.z = 0;
	viewport_v.x = 0;
	viewport_v.y = -viewport_height;
	viewport_v.z = 0;
	viewport_w.x = 0;
	viewport_w.y = 0;
	viewport_w.z = -focal_length;
	delta_u = ft_vec3_scale(viewport_u, (float)(1.0 / image_width));
	delta_v = ft_vec3_scale(viewport_v, (float)(1.0 / image_height));
	viewport_upper_left = ft_vec3_sub(ft_vec3_sub(ft_vec3_add(camera_centre, \
		viewport_w), ft_vec3_scale(viewport_u, 0.5)), \
		ft_vec3_scale(viewport_v, 0.5));
	pixel00_pos = ft_vec3_add(viewport_upper_left, ft_vec3_scale(\
		ft_vec3_add(delta_u, delta_v), 0.5));

	// Image creation
	int			i;
	int			j;
	t_vec3		pixel;
	t_colour	pixel_colour;
	t_ray		ray;
	printf("P3\n%d %d\n255\n", image_width, image_height);
	j = -1;
	while (++j < image_height)
	{
		i = -1;
		while (++i < image_width)
		{
			pixel = ft_vec3_add(ft_vec3_add(pixel00_pos, \
				ft_vec3_scale(delta_u, i)), ft_vec3_scale(delta_v, j));
			ray.direction = ft_vec3_sub(pixel, camera_centre);
			ray.origin = camera_centre;
			ray.d = 1.0;
			pixel_colour = ft_ray_colour(ray);
			ft_write_colour(pixel_colour);
		}
	}
	(void)argv;
	return (0);
}
