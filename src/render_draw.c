/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/20 16:14:06 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_put_pix_to_image(t_buffer *img, int x, int y, int color)
{
	int		i;
	char	*pixel;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * img->bytes);
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	ft_render_image(t_image image, t_cam cam, t_viewport vp, \
	t_entities scene, t_render *render)
{
	int			i;
	int			j;
	t_vec3		pixel;
	t_colour	pixel_colour;
	int			colour;
	t_ray		ray;

	j = -1;
	while (++j < image.image_height)
	{
		i = -1;
		while (++i < image.image_width)
		{
			pixel = ft_vec3_add(ft_vec3_add(vp.pixel00_pos, \
				ft_vec3_scale(vp.delta_u, i)), ft_vec3_scale(vp.delta_v, j));
			ray.origin = cam.camera_centre;
			ray.direction = ft_vec3_norm(ft_vec3_sub(pixel, cam.camera_centre));
			ray.d = 1.0;
			pixel_colour = ft_ray_colour(ray, scene);
			colour = ft_convert_colour2int(pixel_colour);
			ft_put_pix_to_image(&render->buffer, i, j, colour);

		}
	}
	mlx_put_image_to_window(render->mlx_ptr, render->win_ptr,
		render->buffer.ptr, 0, 0);
}
