/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:55 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/06 19:11:13 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static uint32_t	ft_fast_alpha_blend(uint32_t bg_color, t_menu menu)
{
	uint32_t	bg_rb;
	uint32_t	bg_g;
	uint32_t	blend_rb;
	uint32_t	blend_g;

	bg_rb = (bg_color & 0xFF00FF) * menu.inv_alpha;
	bg_g = (bg_color & 0x00FF00) * menu.inv_alpha;
	blend_rb = (((menu.rb + bg_rb) >> 8) & 0xFF00FF);
	blend_g = (((menu.g + bg_g) >> 8) & 0x00FF00);
	return (blend_rb | blend_g);
}

void	ft_blend_background(t_img *img, t_img *veil, t_menu menu)
{
	char		*img_pixel;
	char		*veil_pixel;
	uint32_t	blend_colour;
	t_vec2i		pos;

	pos.y = -1;
	while (++pos.y < veil->size.y)
	{
		pos.x = -1;
		while (++pos.x < veil->size.x)
		{
			img_pixel = img->addr
				+ (pos.y * img->line_len + pos.x * img->bytes);
			blend_colour = fast_alpha_blend(*(uint32_t *)img_pixel, menu);
			veil_pixel = veil->addr
				+ (pos.y * veil->line_len + pos.x * veil->bytes);
			*(uint32_t *)veil_pixel = blend_colour;
		}
	}
}

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

	ray.origin = render->cam.centre;
	ray.d = 1.0;
	y = -1;
	while (++y < render->cam.image.y)
	{
		x = -1;
		while (++x < render->cam.image.x)
		{
			pix_centre = ft_vec3_add(ft_vec3_add(render->cam.pixels.pos00, \
				ft_vec3_scale(render->cam.pixels.delta_u, x)), ft_vec3_scale(render->cam.pixels.delta_v, y));
			ray.direction = ft_vec3_norm(ft_vec3_sub(pix_centre, render->cam.centre));
			pixel_colour = ft_ray_colour(ray, render->scene);
			colour = ft_convert_colour2int(pixel_colour);
			ft_put_pix_to_image(&render->mlx_ptrs.img, x, y, colour);
		}
	}
}
