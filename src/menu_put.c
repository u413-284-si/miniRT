/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:35:59 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/07 18:05:16 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_put.h"

void	ft_menu_put_text(t_render *render)
{
	t_putinfo	put;

	put.mlx_ptrs = render->mlx_ptrs;
	put.pos = (t_vec2i){20, 20};
	put.col = render->menu.font_col;
	if (render->show_menu == false)
		return (ft_put_str(put, "Press I to show menu"));
	mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr,
		render->mlx_ptrs.win_ptr, render->mlx_ptrs.veil.ptr, 0, 0);
	put.pos = ft_put_mode(put, render->mode);
	if (render->menu.cur_page % 3 == 0)
		ft_put_page_scene(put, render->scene.obj[render->active_hittable],
			render->menu.cur_page);
	else if (render->menu.cur_page % 3 == 1 && render->active_light == 0)
		ft_put_page_ambient(put, render->scene.ambient, render->menu.cur_page);
	else if (render->menu.cur_page % 3 == 1)
		ft_put_page_light(put, render->scene.lsrc[render->active_light - 1],
			render->menu.cur_page);
	else if (render->menu.cur_page % 3 == 2)
		ft_put_page_cam(put, render->cam, render->menu.cur_page);
	put.pos = (t_vec2i){20, 490};
	ft_put_info(put);
}
