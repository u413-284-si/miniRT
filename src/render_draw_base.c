/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:55 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/28 15:12:57 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_put_pix_to_image(t_img *img, int x, int y, int color)
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

t_colour	ft_shoot_ray(t_vec2i pos, t_ray ray, t_entities scene, t_cam cam)
{
	t_vec3		pixel_centre;

	pixel_centre = cam.pix_cache[pos.y * cam.image.x + pos.x];
	ray.direction = ft_vec3_norm(ft_vec3_sub(pixel_centre, ray.origin));
	return (ft_ray_colour(ray, scene));
}

void	ft_raytrace_image(t_render *render)
{
	t_vec2i		pos;
	t_ray		ray;
	t_colour	colour;

	ray.origin = render->cam.centre;
	ray.d = 1.0;
	pos.y = -1;
	while (++pos.y < render->cam.image.y)
	{
		pos.x = -1;
		while (++pos.x < render->cam.image.x)
		{
			colour = ft_shoot_ray(pos, ray, render->scene, render->cam);
			ft_put_pix_to_image(&render->mlx_ptrs.img, pos.x, \
				pos.y, ft_convert_colour2int(colour));
		}
	}
}
