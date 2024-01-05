/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:16:52 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/05 15:02:05 by gwolf            ###   ########.fr       */
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
			img_pixel = img->addr + (pos.y * img->line_len + pos.x * img->bytes);
			blend_colour = fast_alpha_blend(*(uint32_t *)img_pixel, menu);
			veil_pixel = veil->addr + (pos.y * veil->line_len + pos.x * veil->bytes);
			*(uint32_t *)veil_pixel = blend_colour;
		}
	}
}

void	ft_draw_menu(t_render *render)
{
	t_putinfo	put;

	put.pos = (t_vec2i){20, 20};
	put.col = render->menu.font_col;
	if (render->show_menu == false)
	{
		mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr,
			render->mlx_ptrs.win_ptr, render->mlx_ptrs.img.ptr, 0, 0);
		return (ft_mlx_put_str(&render->mlx_ptrs, put,
				"Press 'i' to show menu"));
	}
	mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr,
		render->mlx_ptrs.win_ptr, render->mlx_ptrs.veil.ptr, 0, 0);
	put.pos = ft_put_mode(&render->mlx_ptrs, put, render->mode);
	if (render->menu.cur_page == PAGE_SCENE)
		ft_put_hittable(&render->mlx_ptrs, put,
			render->scene.obj[render->active_hittable]);
	else if (render->menu.cur_page == PAGE_LIGHT && render->active_light == 0)
		ft_put_ambient(&render->mlx_ptrs, put, render->scene.ambient);
	else if (render->menu.cur_page == PAGE_LIGHT)
		ft_put_light(&render->mlx_ptrs, put,
			render->scene.lsrc[render->active_light - 1]);
	else if (render->menu.cur_page == PAGE_CAM)
		ft_put_camera(&render->mlx_ptrs, put, render->cam);
	else if (render->menu.cur_page == PAGE_SCENE_CTRL)
		ft_put_ctrl_hittable(&render->mlx_ptrs, put,
			&render->scene.obj[render->active_hittable]);
	else if (render->menu.cur_page == PAGE_LIGHT_CTRL)
		ft_put_ctrl_light(&render->mlx_ptrs, put, render->active_light);
	else if (render->menu.cur_page == PAGE_CAM_CTRL)
		ft_put_ctrl_cam(&render->mlx_ptrs, put);
	put.pos = (t_vec2i){20, 490};
	ft_put_info(&render->mlx_ptrs, put);
}
