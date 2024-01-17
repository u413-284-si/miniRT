/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:37:57 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/17 12:17:17 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ft_draw_scene(t_render *render)
{
	if (render->is_changed)
	{
		if (render->is_threaded)
		{
			if (ft_spin_threads(render, ft_render_image_threaded))
				render->is_threaded = false;
			if (ft_spin_threads(render, ft_blend_background_threaded))
				render->is_threaded = false;
		}
		else
		{
			ft_render_image(render);
			ft_blend_background(render);
		}
		mlx_put_image_to_window(render->mlx_ptrs.mlx_ptr,
			render->mlx_ptrs.win_ptr, render->mlx_ptrs.img.ptr, 0, 0);
		render->is_changed = false;
	}
	ft_menu_put_text(render);
	return (0);
}

int	ft_end_loop(t_render *render)
{
	if (ft_is_printing(render))
		return (0);
	mlx_loop_end(render->mlx_ptrs.mlx_ptr);
	return (0);
}

void	ft_render_start_loop(t_render *render)
{
	mlx_hook(render->mlx_ptrs.win_ptr, KeyPress, KeyPressMask,
		ft_keyhook_press, render);
	mlx_hook(render->mlx_ptrs.win_ptr, ButtonPress, ButtonPressMask,
		ft_mouse_hook_press, render);
	mlx_hook(render->mlx_ptrs.win_ptr, ButtonRelease, ButtonReleaseMask,
		ft_mouse_hook_release, render);
	mlx_hook(render->mlx_ptrs.win_ptr, MotionNotify, ButtonMotionMask,
		ft_mouse_hook_move, render);
	mlx_hook(render->mlx_ptrs.win_ptr, DestroyNotify, StructureNotifyMask,
		ft_end_loop, render);
	mlx_loop_hook(render->mlx_ptrs.mlx_ptr, ft_draw_scene, render);
	mlx_set_font(render->mlx_ptrs.mlx_ptr, render->mlx_ptrs.win_ptr, REGULAR);
	render->is_changed = true;
	render->is_threaded = true;
	render->mut_print = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	mlx_loop(render->mlx_ptrs.mlx_ptr);
	ft_free_mlx(render->mlx_ptrs.mlx_ptr, render->mlx_ptrs.win_ptr,
		render->mlx_ptrs.img.ptr, render->mlx_ptrs.veil.ptr);
}
