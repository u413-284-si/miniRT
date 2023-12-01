/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:00:30 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/01 15:23:08 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

int	ft_draw_scene(t_engine *engine)
{
	int			i;
	int			j;
	t_vec3		pix_centre;
	int			colour;

	j = -1;
	while (++j < engine->image.image_height)
	{
		i = -1;
		while (++i < engine->image.image_width)
		{
			float x = (float)i / (float)engine->image.image_width;
			x = x * 2.0 - 1.0;
			float y = (float)j / (float)engine->image.image_height;
			y = y * 2.0 - 1.0;
			t_vec4 target;
			target = ft_vec4_create(x, y, 1, 1);
			target = ft_mult_vec4_mat4(target, engine->cam.inv_projection);
			t_vec3	temp;
			temp = ft_vec3_create(target.x, target.y, target.z);
			temp = ft_vec3_norm(ft_vec3_scale(temp, 1 / target.w));
			target = ft_vec4_create(temp.x, temp.y, temp.z, 0);
			target = ft_mult_vec4_mat4(target, engine->cam.inv_view);
			pix_centre = ft_vec3_create(target.x, target.y, target.z);
			colour = ft_calc_pix_colour(engine->cam, pix_centre, engine->scene);
			ft_put_pix_to_image(&engine->render.buffer, i, j, colour);
		}
	}
	mlx_put_image_to_window(engine->render.mlx_ptr, engine->render.win_ptr,
		engine->render.buffer.ptr, 0, 0);
	return (0);
}
