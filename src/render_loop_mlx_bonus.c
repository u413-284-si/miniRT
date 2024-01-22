/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_loop_mlx_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:37:57 by gwolf             #+#    #+#             */
/*   Updated: 2024/01/22 00:52:36 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

int	ft_programm_loop(t_render *render)
{
	static uint8_t	cur_sample;

	if (ft_option_isset(render->options, O_SCENE_CHANGED))
	{
		cur_sample = 0;
		ft_option_clear(&render->options, O_SCENE_CHANGED);
	}
	if (cur_sample < render->sample_goal)
		if (ft_render_sample(render, &cur_sample))
			return (0);
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
	mlx_loop_hook(render->mlx_ptrs.mlx_ptr, ft_programm_loop, render);
	mlx_loop(render->mlx_ptrs.mlx_ptr);
}
