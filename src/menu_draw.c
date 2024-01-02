/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:16:52 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/02 23:38:30 by gwolf            ###   ########.fr       */
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

void	ft_blend_background(t_img *img, t_menu menu)
{
	char		*pixel;
	uint32_t	img_colour;
	uint32_t	blend_colour;
	t_vec2i		pos;

	pos.y = -1;
	while (++pos.y < img->size.y)
	{
		pos.x = -1;
		while (++pos.x < MENU_WIDTH)
		{
			pixel = img->addr + (pos.y * img->line_len + pos.x * img->bytes);
			img_colour = *(uint32_t *)pixel;
			blend_colour = fast_alpha_blend(img_colour, menu);
			*(uint32_t *)pixel = blend_colour;
		}
	}
}

void	ft_draw_menu(t_render *render)
{
	t_vec2i	pos;

	pos = (t_vec2i){20, 20};
	if (render->show_menu == false)
		return (ft_mlx_put_str(&render->mlx_ptrs, pos,
			render->menu.font_col, "Press 'i' to show menu"));
	ft_blend_background(&render->mlx_ptrs.img, render->menu);
	pos = ft_put_mode(&render->mlx_ptrs, pos,
			render->menu.font_col, render->mode);
	if (render->mode == CTRL_SCENE)
		ft_put_hittable(&render->mlx_ptrs, pos,
			render->menu.font_col, render->scene.obj[render->scene.active]);
	else if (render->mode == CTRL_CAM)
	{
		ft_put_camera(&render->mlx_ptrs, pos,
			render->menu.font_col, render->cam);
		pos.y = 300;
		ft_put_ctrl_camera(&render->mlx_ptrs, pos, render->menu.font_col);
	}
	else if (render->mode == CTRL_LIGHT)

		;//ft_put_light(&render->mlx_ptrs, pos,
		//	render->menu.font_col, render->scene.light[render->scene.active]);}
	pos = (t_vec2i){20, 530};
	ft_put_info(&render->mlx_ptrs, pos, render->menu.font_col);
}
