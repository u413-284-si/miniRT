/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:52:55 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/19 18:20:46 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

uint32_t	ft_fast_alpha_blend(uint32_t bg_color, t_menu menu)
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

void	ft_blend_background(t_render *render)
{
	t_vec2i		pos;
	uint32_t	*img_pixel;
	uint32_t	*veil_pixel;
	uint32_t	blend_colour;

	pos.y = -1;
	while (++pos.y < render->mlx_ptrs.veil.size.y)
	{
		pos.x = -1;
		while (++pos.x < render->mlx_ptrs.veil.size.x)
		{
			img_pixel = (uint32_t *)(render->mlx_ptrs.img.addr
					+ (pos.y * render->mlx_ptrs.img.line_len
						+ pos.x * render->mlx_ptrs.img.bytes));
			blend_colour = ft_fast_alpha_blend(*img_pixel, render->menu);
			veil_pixel = (uint32_t *)(render->mlx_ptrs.veil.addr
					+ (pos.y * render->mlx_ptrs.veil.line_len
						+ pos.x * render->mlx_ptrs.veil.bytes));
			*veil_pixel = blend_colour;
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
	t_vec2i		iterate;
	t_colour	pixel_colour;
	int			colour;

	iterate.y = -1;
	while (++iterate.y < render->cam.image.y)
	{
		iterate.x = -1;
		while (++iterate.x < render->cam.image.x)
		{
			pixel_colour = ft_anti_aliase_colour(iterate, \
				render->cam.pixels, render->cam, render->scene);
			colour = ft_convert_colour2int(pixel_colour);
			ft_put_pix_to_image(&render->mlx_ptrs.img, iterate.x, \
				iterate.y, colour);
		}
	}
	mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr, render->mlx_ptrs.win_ptr,
		render->mlx_ptrs.img.ptr, 0, 0);
}

t_colour	ft_anti_aliase_colour(t_vec2i iterate, t_pixel_grid pixels, \
	t_cam cam, t_entities scene)
{
	int			curr_sample;
	t_ray		ray;
	t_colour	pixel_colour;
	t_vec3		pixel_centre;

	curr_sample = -1;
	pixel_colour = (t_colour){0};
	pixel_centre = cam.pix_cache[iterate.y * cam.image.x + iterate.x];
	while (++curr_sample < SAMPLE_SIZE)
	{
		ray = ft_create_sample_ray(pixel_centre, pixels, cam);
		pixel_colour = ft_add_colour(pixel_colour, \
			ft_ray_colour(ray, scene, cam));
	}
	pixel_colour.r /= SAMPLE_SIZE;
	pixel_colour.g /= SAMPLE_SIZE;
	pixel_colour.b /= SAMPLE_SIZE;
	return (pixel_colour);
}
