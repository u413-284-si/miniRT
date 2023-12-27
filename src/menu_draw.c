/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:16:52 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/27 17:40:12 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_menu.h"


uint32_t	fast_alpha_blend(uint32_t bg_color, t_menu menu)
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

t_menu	ft_init_menu(uint8_t alpha, uint32_t colour)
{
	t_menu	menu;

	menu.inv_alpha = 255 - alpha;
	menu.rb = (colour & 0xFF00FF) * alpha;
	menu.g = (colour & 0x00FF00) * alpha;
	return (menu);
}

void	ft_blend_background(t_img *img, int x, int y, t_menu menu)
{
	char		*pixel;
	uint32_t	img_colour;
	uint32_t	blend_colour;

	pixel = img->addr + (y * img->line_len + x * img->bytes);
	img_colour = *(uint32_t *)pixel;
	blend_colour = fast_alpha_blend(img_colour, menu);
	*(uint32_t *)pixel = blend_colour;
	(void)menu;
}

void	ft_draw_background(t_render *render)
{
	int		x;
	int		y;
	t_menu	menu;

	menu = ft_init_menu(100, 0xff0000);
	y = -1;
	while (++y < render->mlx_ptrs.img.height)
	{
		x = -1;
		while (++x < 150)
		{
			ft_blend_background(&render->mlx_ptrs.img, x, y, menu);
		}
	}
}
