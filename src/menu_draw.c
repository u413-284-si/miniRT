/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:16:52 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/31 10:46:12 by gwolf            ###   ########.fr       */
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

void	ft_blend_background(t_img *img, int x, int y, t_menu menu)
{
	char		*pixel;
	uint32_t	img_colour;
	uint32_t	blend_colour;

	pixel = img->addr + (y * img->line_len + x * img->bytes);
	img_colour = *(uint32_t *)pixel;
	blend_colour = fast_alpha_blend(img_colour, menu);
	*(uint32_t *)pixel = blend_colour;
}

void	ft_draw_menu(t_render *render)
{
	int		x;
	int		y;

	if (render->show_menu == false)
		return (ft_mlx_put_str(&render->mlx_ptrs, (t_vec2i){20, 20},
			render->menu.font_col, "Press 'i' to show menu"));
	y = -1;
	while (++y < render->mlx_ptrs.img.height)
	{
		x = -1;
		while (++x < MENU_WIDTH)
		{
			ft_blend_background(&render->mlx_ptrs.img, x, y, render->menu);
		}
	}
	if (1)
		ft_put_hittable(&render->mlx_ptrs, (t_vec2i){20, 20},
			render->menu.font_col, render->scene.obj[render->scene.active]);
	else
		ft_put_camera(&render->mlx_ptrs, (t_vec2i){20, 20},
			render->menu.font_col, render->cam);
}
