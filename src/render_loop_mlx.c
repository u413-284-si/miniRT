/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:37:57 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/14 17:21:00 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_draw_scene(t_render *render)
{
	if (render->is_printing)
	{
		mlx_string_put(render->mlx_ptrs.mlx_ptr, render->mlx_ptrs.win_ptr,
			200, 20, render->menu.font_col, "Printing - Please wait");
		ft_output_as_ppm(render->mlx_ptrs.img, &render->is_printing);
		mlx_do_key_autorepeaton(render->mlx_ptrs.mlx_ptr);
		return (0);
	}
	if (render->is_changed)
	{
		ft_render_image(render);
		mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr,
			render->mlx_ptrs.win_ptr, render->mlx_ptrs.img.ptr, 0, 0);
		ft_blend_background(&render->mlx_ptrs.img, &render->mlx_ptrs.veil,
			render->menu);
		render->is_changed = false;
	}
	ft_menu_put_text(render);
	return (0);
}

void	ft_render_start_loop(t_render *render)
{
	mlx_hook(render->mlx_ptrs.win_ptr, KeyPress, KeyPressMask,
		ft_keyhook_press, render);
	mlx_hook(render->mlx_ptrs.win_ptr, KeyRelease, KeyReleaseMask,
		ft_keyhook_release, render);
	mlx_hook(render->mlx_ptrs.win_ptr, ButtonPress, ButtonPressMask,
		ft_mouse_hook_press, render);
	mlx_hook(render->mlx_ptrs.win_ptr, ButtonRelease, ButtonReleaseMask,
		ft_mouse_hook_release, render);
	mlx_hook(render->mlx_ptrs.win_ptr, MotionNotify, ButtonMotionMask,
		ft_mouse_hook_move, render);
	mlx_hook(render->mlx_ptrs.win_ptr, DestroyNotify, StructureNotifyMask,
		mlx_loop_end, render->mlx_ptrs.mlx_ptr);
	mlx_loop_hook(render->mlx_ptrs.mlx_ptr, ft_draw_scene, render);
	mlx_set_font(render->mlx_ptrs.mlx_ptr, render->mlx_ptrs.win_ptr, REGULAR);
	render->is_changed = true;
	mlx_loop(render->mlx_ptrs.mlx_ptr);
	ft_free_mlx(render->mlx_ptrs.mlx_ptr, render->mlx_ptrs.win_ptr,
		render->mlx_ptrs.img.ptr, render->mlx_ptrs.veil.ptr);
}
