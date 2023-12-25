/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/25 08:56:58 by gwolf            ###   ########.fr       */
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

void	ft_render_image(t_render *render)
{
	t_ray		ray;
	int			y;
	int			x;
	t_vec3		pix_centre;
	t_colour	pixel_colour;
	int			colour;

	ray.origin = render->cam.position;
	ray.d = 1.0;
	y = -1;
	while (++y < render->cam.image.y)
	{
		x = -1;
		while (++x < render->cam.image.x)
		{
			pix_centre = ft_vec3_add(ft_vec3_add(render->cam.pixels.pos00, \
				ft_vec3_scale(render->cam.pixels.delta_u, x)), ft_vec3_scale(render->cam.pixels.delta_v, y));
			ray.direction = ft_vec3_norm(ft_vec3_sub(pix_centre, render->cam.position));
			pixel_colour = ft_ray_colour(ray, render->scene);
			colour = ft_convert_colour2int(pixel_colour);
			ft_put_pix_to_image(&render->mlx_ptrs.img, x, y, colour);
		}
	}
	mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr, render->mlx_ptrs.win_ptr,
		render->mlx_ptrs.img.ptr, 0, 0);
}
