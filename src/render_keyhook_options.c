/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_options.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:15:52 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/08 12:20:02 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	ft_change_mode(t_mode *mode, t_pages *cur_page)
{
	if (*mode == CTRL_SCENE)
	{
		*mode = CTRL_LIGHT;
		(*cur_page)++;
	}
	else if (*mode == CTRL_LIGHT)
	{
		*mode = CTRL_CAM;
		(*cur_page)++;
	}
	else if (*mode == CTRL_CAM)
	{
		*mode = CTRL_SCENE;
		(*cur_page) -= 2;
	}
}

static void	ft_toggle_menu_page(t_pages *cur_page)
{
	if (*cur_page <= PAGE_CAM)
		*cur_page += 3;
	else
		*cur_page -= 3;
}

static void	ft_toggle_menu(bool *show_menu, const t_mlx_ptrs mlx_ptrs)
{
	*show_menu = !(*show_menu);
	if (*show_menu == false)
	{
		mlx_put_image_to_window(mlx_ptrs.mlx_ptr,
			mlx_ptrs.win_ptr, mlx_ptrs.img.ptr, 0, 0);
	}
}

void	ft_change_options(int key, t_render *render)
{
	if (key == XK_Escape)
		mlx_loop_end(render->mlx_ptrs.mlx_ptr);
	else if (key == XK_i)
		ft_toggle_menu(&render->show_menu, render->mlx_ptrs);
	else if (key == XK_Control_L)
		ft_change_mode(&render->mode, &render->menu.cur_page);
	else if (key == XK_Shift_L)
		ft_toggle_menu_page(&render->menu.cur_page);
}
