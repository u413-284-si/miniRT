/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_keyhook_press.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:40:44 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/17 17:27:54 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static bool	ft_is_manip_key(int key)
{
	return (key == XK_w || key == XK_s || key == XK_a || key == XK_d
		|| key == XK_q || key == XK_e || key == XK_r || key == XK_f
		|| key == XK_t || key == XK_g || key == XK_n || key == XK_m
		|| (key >= XK_Left && key <= XK_Down)
		|| (key >= XK_0 && key <= XK_9));
}

static void	ft_change_mode(t_render *render)
{
	if (render->mode == CTRL_SCENE)
	{
		render->mode = CTRL_LIGHT;
		render->menu.cur_page++;
	}
	else if (render->mode == CTRL_LIGHT)
	{
		render->mode = CTRL_CAM;
		render->menu.cur_page++;
	}
	else if (render->mode == CTRL_CAM)
	{
		render->mode = CTRL_SCENE;
		render->menu.cur_page -= 2;
	}
}

static void	ft_change_menu_page_ctrl(t_render *render)
{
	if (render->menu.cur_page <= PAGE_CAM)
		render->menu.cur_page += 3;
	else
		render->menu.cur_page -= 3;
}

static void	ft_toggle_menu(t_render *render)
{
	render->show_menu = !render->show_menu;
	if (render->show_menu == false)
		mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr,
			render->mlx_ptrs.win_ptr, render->mlx_ptrs.img.ptr, 0, 0);
}

int	ft_keyhook_press(int key, t_render *render)
{
	if (ft_is_printing(render))
		return (0);
	else if (key == XK_Escape)
		return (mlx_loop_end(render->mlx_ptrs.mlx_ptr));
	if (key == XK_p)
	{
		ft_toggle_is_printing(render);
		ft_spin_detached_thread(render, ft_output_threaded);
		return (0);
	}
	else if (key == XK_j)
		render->is_threaded = !render->is_threaded;
	else if (key == XK_i)
		ft_toggle_menu(render);
	else if (key == XK_Control_L)
		ft_change_mode(render);
	else if (key == XK_Shift_L)
		ft_change_menu_page_ctrl(render);
	else if (ft_is_manip_key(key))
	{
		if (render->mode == CTRL_SCENE)
			ft_manip_scene(key, &render->scene, &render->active_hittable);
		else if (render->mode == CTRL_CAM)
			ft_manip_cam(key, &render->cam, &render->is_threaded, &render->is_changed);
		else if (render->mode == CTRL_LIGHT)
			ft_manip_light(key, &render->scene, &render->active_light);
		render->is_changed = true;
	}
	return (0);
}
