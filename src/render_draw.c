/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:55 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/16 10:58:10 by gwolf            ###   ########.fr       */
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

void	ft_render_image(t_render *render, t_cam *cam, t_entities scene)
{
	int			x;
	int			y;
	t_colour	pixel_colour;
	int			colour;
	t_ray		ray;

	ray.origin = cam->look_from;
	ray.d = 1.0;
	y = -1;
	while (++y < cam->screen.height)
	{
		x = -1;
		while (++x < cam->screen.width)
		{
			ray.direction = cam->cached_rays[y * cam->screen.width + x];
			pixel_colour = ft_ray_colour(ray, scene);
			pixel_colour = ft_clamp_colour(pixel_colour, 0.0, 1.0);
			colour = ft_convert_colour2int(pixel_colour);
			ft_put_pix_to_image(&render->buffer, x, cam->screen.height - y - 1, colour);

		}
	}
	mlx_put_image_to_window(render->mlx_ptr, render->win_ptr,
		render->buffer.ptr, 0, 0);
}
