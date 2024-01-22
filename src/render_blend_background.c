/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_blend_background.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:43:28 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 08:43:50 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

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
